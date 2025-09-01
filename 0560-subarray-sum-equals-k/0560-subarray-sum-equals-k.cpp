class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         int n = nums.size();
         int cnt =0;
         for(int i=0;i<n;i++){
            int sum =0;
             for(int j = i;j<n;j++){
                 sum+=nums[j];

                 if(sum == k){
                     cnt++;
                   
                 }
             }
         }
         return cnt;

      // prefix sum  + hashing 
    //   int n = nums.size();
    //   map<long long,int>prefsum;
    //   int sum =0;
    //   for(int i=0;i<n;i++){
    //      sum+=nums[i];

    //      if(sum == k){
    //          maxlen = max(maxlen , i+1);
    //      }

    //      int rem = sum - k;
    //      if(prefsum.find(rem)!=pref.end()){
    //          int len = i - prefsum[rem];
    //          maxlen  = max(maxlen, len);
    //      }

    //      if(prefsum.find(sum) == prefsum.end()){
    //          prefsum[sum] = i;
    //      }
    //   }


// SLIDING WIMDOW




    }
};