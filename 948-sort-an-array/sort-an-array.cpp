class Solution {
public:
    void merge(vector<int>& arr,int l,int mid,int r){
        int n1=mid+1-l;
        int n2=r-mid;
        vector<int>A(n1);
        vector<int>B(n2);
        for(int i=0;i<n1;i++) A[i]=arr[i+l];
        for(int i=0;i<n2;i++) B[i]=arr[mid+1+i];

        int i=0,j=0,k=l;
        while(i<n1 && j<n2){
            if(A[i]<B[j]){
                arr[k]=A[i];
                i++;
            }
            else{
                arr[k]=B[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            arr[k]=A[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k]=B[j];
            j++;
            k++;
        }

    }
    void mergeSort(vector<int>& arr,int l,int r){
        if(l>=r) return;
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        merge(arr,l,mid,r);

    }

    

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
        
    }
};