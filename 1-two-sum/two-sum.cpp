class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int rem=target-nums[i];
            
            if(mp.find(rem)!=mp.end()){
                int j=mp[rem];
                return {j,i};
            }
            mp[nums[i]]=i;
        }
        return { };
    }

};