typedef long long ll;
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
         ll n = nums.size();
         sort(nums.begin(),nums.end());

         int i=0,j =n-1;
         ll sum =0;
         while(i<j){
             int median = nums[j-1];
             sum+=median;
             i++;
             j-=2;
         } 
         return sum;
    }
};