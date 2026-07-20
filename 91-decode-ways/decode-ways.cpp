class Solution {
public:
    // int f(int ind, string s, vector<int>&dp){
    //     if(s[i]=='0' || s.empty()) return 0;

    //     int onedigit=

    // }
    int numDecodings(string s) {
        if(s.empty() || s[0]=='0') return 0;
        int n=s.size();
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int onedigit=s[i-1]-'0';
            if(onedigit >=1 && onedigit<=9) dp[i]=dp[i]+dp[i-1];

            int twodigits=stoi(s.substr(i-2,2));
            if(twodigits>=10 && twodigits<=26) dp[i]=dp[i]+dp[i-2];
            

        }
        return dp[n];
        // return f(n-1,s,dp);
    }
};