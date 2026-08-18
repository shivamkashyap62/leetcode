class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        map<int ,set<int>> freq;
        for(int i=0;i<=n-k;i++){
            for(int j=i;j<k+i;j++){
                freq[nums[j]].insert(i);
            }
        }
        int maxi=-1;
        for(auto & [el, f]: freq){
            if(f.size()==1){
                maxi=max(maxi,el);
            }
        }
        return maxi;
    }
};