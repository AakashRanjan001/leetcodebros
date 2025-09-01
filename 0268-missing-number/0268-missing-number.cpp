class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //  int n = nums.size();
        //  bool f = false;
        //  for(int i=0;i<=n;i++){
        //     f = false;
        //      for(int j=0;j<n;j++){
        //          if(i == nums[j]){
        //              f = true;
        //              break;
        //          }
        //      }
        //      if(f == false)return i;
        //  }
        //  return 0;

        // int n = nums.size();
        // int T_sum = 0;
        // for(int i=0;i<=n;i++){
        //      T_sum+=i;
        // }
        // int arr_sum = accumulate(nums.begin(),nums.end(), 0);
        // return T_sum - arr_sum;
       
       int n = nums.size();
       int XOR1 = 0;
       for(int i=1;i<=n;i++){
          XOR1^=i;
       }
       int XOR2 = 0;
       for(int i=0;i<n;i++){
          XOR2^=nums[i];
       }
       return XOR1^XOR2;
     
        

    }
};