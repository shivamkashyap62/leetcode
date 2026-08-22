class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0, product=1;
        int m=n;
        while(n>0){
            int digit=n%10;
            sum+=digit;
            product*=digit;
            n=n/10;
        }
    
        int total=sum+product;
        cout<<total;
        return m%total==0;
    }
};