class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
        map<char,int>mp;
        int i=0;
        mp[s[i]]=1;
        int ans=1;
        for(int j=1;j<s.size();j++){

            while(mp[s[j]]==1){
                mp[s[i]]=0;
                i++;
            }

            mp[s[j]]=1;
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};