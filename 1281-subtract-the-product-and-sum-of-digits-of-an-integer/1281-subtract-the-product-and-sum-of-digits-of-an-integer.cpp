class Solution {
public:
    int subtractProductAndSum(int n) {

   vector<int>ans;
   int sum =0;
   int product =1;
   while(n!=0){
   int digit = n%10;
   n = n/10;

ans.push_back(digit);
product = product*digit;
sum = sum + digit;
   }
 return (product - sum);
    }
};