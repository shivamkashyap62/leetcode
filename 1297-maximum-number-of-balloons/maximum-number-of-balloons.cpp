class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.size();
        map<char,int>mp;
        for(int i=0;i<n;i++){
            if(text[i]=='b' || text[i]=='a' || text[i]=='l' || text[i]=='o' || text[i]=='n')
            mp[text[i]]++;
        }
        
        int x=min(mp['b'],min(mp['a'],mp['n']));
        int y=min(mp['l'],mp['o']);
        return min(x,y/2);
    }
};