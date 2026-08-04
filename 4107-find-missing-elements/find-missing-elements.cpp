class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       vector<int>ans;
        for(int i=1;i<nums.size();i++){
            int x=nums[i-1];
            int y=nums[i];

            while(x+1!=y){
                x++;
                ans.push_back(x);
                
            }
        }
        return ans;
    }
};