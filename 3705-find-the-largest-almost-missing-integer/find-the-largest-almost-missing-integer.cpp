class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        map<int ,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
        if(k==1){
            int ans=-1;
            for(auto& [x, freq]: mp){
                
                if(freq==1){
                    ans=max(ans,x);
                }
            }
            return ans;
        }
        else if(k==n){
            int ans=-1;
            for(int i=0;i<n;i++){
                ans=max(ans,nums[i]);
            }
            return ans;
        }
        else{
            int ans=-1;
            if(mp[nums[0]]==1) ans=max(ans,nums[0]);
            if(mp[nums[n-1]]==1) ans=max(ans,nums[n-1]);
            return ans;
        }
        
        return -1;
    }
};