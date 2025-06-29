#define MOD 1000000007
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
          int n = nums.size();
          sort(nums.begin(),nums.end());
        
        // As the Power Funcytion is  taking too much of the time hence we will precompute the power of many values 
          vector<int>power(n);
          power[0] = 1;
          for(int i=1;i<n;i++){
             power[i] = (power[i-1]* 2)% MOD;

          }

          int l = 0;
          int r = n-1;
          long long res =0;
          while(l<=r){
              if(nums[l]+ nums[r]<=target){
                //   res= ((int)res + (int)(pow(2,r-l))% MOD) %MOD;
                int diff = r-l;
                res = (res%MOD + power[diff])% MOD;
                  l++;
              }
              else{
                 r--;
              }
          }
          return res%MOD;



    }
};