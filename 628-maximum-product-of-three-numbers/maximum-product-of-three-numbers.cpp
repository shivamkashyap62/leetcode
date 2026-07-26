class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1=-1000,max2=-1000,max3=-1000;
        int min1=0,min2=0;

        for(int i: nums){
            if(i>=max1){
                max3=max2;
                max2=max1;
                max1=i;
            }
            else if(i>=max2){
                max3=max2;
                max2=i;
            }
            else if(i>=max3){
                max3=i;
            }
            if(min1>=i){
                min2=min1;
                min1=i;
            }
            else if(min2>=i){
                min2=i;
            }
        }
        return max(max1*max2*max3, min1*min2*max1);
    }
};