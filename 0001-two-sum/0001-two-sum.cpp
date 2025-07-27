class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // int n = nums.size();
        // vector<int>ans;
        // for(int i=0;i<n;i++){
        //      for(int j=i+1;j<n;j++){
        //          if(nums[i] + nums[j] == target){
        //              ans.push_back(i);
        //              ans.push_back(j);
        //          }
        //      }
        // }
        // return ans;

        //Approach 2 : Hashing + pref sum

        int n = nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int val = nums[i];
            if(mp.find(target - val)!=mp.end()){
                 return {mp[target-val],i};
            }  

            mp[nums[i]] = i;
        }
        return {};
 
    }
};