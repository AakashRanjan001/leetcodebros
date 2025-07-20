typedef long long ll;
class Solution {
public:
    bool isPrime(long long ind,long long n){
        ll cnt = 0;
         for(ll i=1;i<=(ll)sqrt(ind);i++){
             if(ind%i ==0){
                 cnt++;
                 if(ind/i!=i){ 
                    cnt++;
                  }
             }
           
         }
         if(cnt == 2)return true;
         return false;
    }
    long long splitArray(vector<int>& nums) {
          ll n = nums.size();
          ll T_sum = accumulate(nums.begin(),nums.end(),0LL);

          ll prime_sum =0;
          for(int i=2;i<n;i++){
             if(isPrime(i,n) == true){
                  prime_sum+=nums[i];
             }
          }
          ll rem_sum = T_sum - prime_sum;
          return abs(rem_sum - prime_sum);
    }
};