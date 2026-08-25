class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(int i:nums) st.insert(i);

        int x=k;
        while(st.count(x)){
            x+=k;
        }
        return x;
        
    }
};