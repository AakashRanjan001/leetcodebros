class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //  int times = nums.size()/3;
        //  set<int>ans;
     
        //  for(int i=0;i<nums.size();i++){
        //     int cnt =1;
        //      for(int j=i+1;j<nums.size();j++){
        //          if(nums[i] == nums[j]){
        //              cnt++;
        //          }
        //      }
        //       if(cnt>times)ans.insert(nums[i]);
        //  }
        //  vector<int>val(ans.begin(),ans.end());
        //  return val;


        map<int,int>m;
        vector<int>ans;
        int n = nums.size();
        for(auto i:nums){
             m[i]++;
        }
        for(auto it:m){
             if(it.second>(n/3)){
                 ans.push_back(it.first);
             }
        }
        return ans;
    }
};