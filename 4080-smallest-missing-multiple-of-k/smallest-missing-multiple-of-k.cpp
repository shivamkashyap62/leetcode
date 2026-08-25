class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(int i:nums) st.insert(i);

        int x=k;
        while(true){
            if(st.find(x)==st.end()) return x;
            x+=k;
        }
        
    }
};