class Solution {
public:
    double power(double x,int n){
        if(n==0) return 1;

        double a=power(x,n/2);
        if(n%2==0)  return a*a;
        return a*a*x;
}
    double myPow(double x, int n) {
        if(n==0) return 1;
        else if(n>0) return power(x,n);
        else {
            long long z=n;
            z*=-1;
            return 1/power(x,n);
        }
    }
};