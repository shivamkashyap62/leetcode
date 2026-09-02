class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        int ind=-1;
        if(nums[0]>target) return 0;
        if(nums[j]<target) return j+1;

        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]>=target){
                j=mid-1;
                ind=mid;
            }
            else{
                i=mid+1;
            }
        }
        return ind;
    }
};