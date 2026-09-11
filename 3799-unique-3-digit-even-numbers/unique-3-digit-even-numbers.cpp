class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        set<int>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(digits[i]!=0 && digits[k]%2==0 
                    && i!=j && j!=k && i!=k){
                        st.insert(digits[i]*100 + digits[j]*10 + digits[k]);
                    }
                }
            }
        } 
        return st.size();

    }
};