class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //  int n = nums.size();
        //  unordered_map<int,int>mp;
        //  for(auto i: nums){
        //      mp[i]++;
        //  }
        //  for(auto i:mp){
        //      if(i.second == 1){
        //         return i.first;
        //         break;
        //      }
        //  }
        //  return 0;


       int n = nums.size();
       int val = -1;
       for(int i=0;i<n;i++){
           val = nums[i];
           bool f = 0;
          for(int j=0;j<n;j++){
              if(nums[j] == val && j!=i){
                  f = true;
                  break;
              }
          }
          if(f == 0)return val;
           
       }
       return 0;

   
    }
};