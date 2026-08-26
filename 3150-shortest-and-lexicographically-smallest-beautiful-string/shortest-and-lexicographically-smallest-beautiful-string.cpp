class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n=s.size();
        int c1=0;
        int left=0;
        string ans="";

        for(int right=0;right<n;right++){
            if(s[right]=='1') c1++;

            while(c1>k){
                if(s[left]=='1') c1--;
                left++;
            }

            if(c1==k){
                while(left<=right && s[left]=='0') 
                    left++;

                string curr=s.substr(left,right-left+1);

                if(ans== "" || 
                ans.size() > curr.size() || 
                (ans.size()==curr.size() && ans>curr)) 
                    ans=curr;
            }

            while(c1>k){
                if(s[left]=='1') c1--;
                left++;
            }
        }
        return ans;

    }
};