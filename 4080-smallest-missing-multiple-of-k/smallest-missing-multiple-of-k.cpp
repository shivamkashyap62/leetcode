class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        int i=1;
        int x=k;
        while(k<=k*n)
        {
            bool flag=false;
            for(int j=0;j<n;j++){
                if(nums[j]==k){
                flag=true;
                break;}
            }
            if(flag==false) return k;
            i++;
            k=x*i;
            
        }

        return 0;
    }
};