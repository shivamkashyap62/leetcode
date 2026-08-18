class Solution {
public:
    vector<int> findLeftMax(vector<int>& height,int &n){
        vector<int>left(n);
        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }
        return left;
    }
    vector<int> findRightMax(vector<int>& height,int &n){
        vector<int>right(n);
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        return right;
    }
    int trap(vector<int>& height) {
        int n=height.size();
        int sum=0;
        vector<int>left_max=findLeftMax(height,n);
        vector<int>right_max=findRightMax(height,n);
        for(int i=0;i<n;i++){
            sum+=(min(left_max[i],right_max[i])-height[i]);
        }
        return sum;
    }
};