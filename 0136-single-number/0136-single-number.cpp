class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int n=nums.size();
        //  int val = -1;
        // for(int i=0;i<n;i++){
        //     bool f = false;
        //      int val = nums[i];
        //      for(int j=0;j<n;j++){
        //          if(i!=j && nums[i] == nums[j]){
        //               f = true;
        //              break;
        //          } 
        //      }
        //      if(f  == 0)return val;
        // }
        // return 0;

        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
             mp[nums[i]]++;
        }
        for(auto i: mp){
             if(i.second == 1){
                 return i.first;
             }
        }
        return 0;
    }
};