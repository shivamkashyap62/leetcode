class Solution {
public:
    vector<int> twoSum(vector<int>& number, int target) {
        int i=0, j=number.size()-1;
        while(i<j){
            int sum=number[i]+number[j];
            if(sum==target) return {i+1,j+1};
            else if(sum>target) j--;
            else i++;
        }
        return {};
    }
};