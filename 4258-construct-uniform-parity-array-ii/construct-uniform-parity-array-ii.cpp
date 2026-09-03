class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int co=0;
        int ce=0;
        int em=1e9;
        int om=1e9;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0){ 
                ce++;
                em=min(em,nums1[i]);
            }
            else {
                om=min(om,nums1[i]);
                co++;}
        }
        if(co==n || ce==n) return true;
        

        else{
            for(int i=0;i<n;i++){
                int x=nums1[i]%2;
                if(x==0){
                    if((nums1[i]-om)<1) return false;
                }
                
            }
        }
        return true;
    }
};