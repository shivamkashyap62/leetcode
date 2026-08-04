class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>st(101,0);
        vector<int>ans;
        int maxi=0;
        int mini=100;
        for(int i=0;i<nums.size();i++){
            if(maxi<nums[i]) maxi=nums[i];
            if(mini>nums[i]) mini=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            st[nums[i]]=1;
        }
        for(int i=mini;i<=maxi;i++){
            if(st[i]==0) ans.push_back(i);
        }
        return ans;
    }
};