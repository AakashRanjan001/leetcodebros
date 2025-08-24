class Solution {
public:
    int gcdOfOddEvenSums(int n) {
           int odd_sum  = n*n;
           int even_sum = n*(n+1);

           return gcd(odd_sum,even_sum);
    }
};