// class Solution {
// public:
//     double power(double &a, int &b){
//          double res =1;
//          while(b>0){
//              if(b%2 == 1){
//                  res = res* a;
//              }
//              a = a*a;
//              b>>=1;
//          }
//          double ans = (b>=0)? res : double(1/res);
//          return ans;
//     }
//     double myPow(double x, int n) {
//          return power(x,n); 
//     }
// };

class Solution {
public:
    double power(double a, long long b) {
        double res = 1.0;
        while (b > 0) {
            if (b % 2 == 1) res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }

    double myPow(double x, int n) {
        long long b = n;  // Use long long to safely handle INT_MIN
        if (b < 0) {
            x = 1.0 / x;
            b = -b;
        }
        return power(x, b);
    }
};
