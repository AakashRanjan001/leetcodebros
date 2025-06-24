class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        //  map<int,vector<int>>mp;
        //  for(int i=0;i<nums.size();i++){
        //       if(nums[i] == key){
        //          mp[key].push_back(i);
        //       }
        //  }
        //  vector<int>ans;
        // for(int i=0;i<nums.size();i++){
        //      for(auto j:mp[key]){
        //          if(abs(i-j)<=k){
        //              ans.push_back(i);
        //              break;
        //          }
        //      }
        // }
        // return ans;

     int n = nums.size();
        vector<int> res;
        int last = -1;  // Track last inserted index to avoid duplicates

        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                int start = max(i - k, 0);
                int end = min(i + k, n - 1);

                start = max(start, last + 1);  // avoid duplicates
                for (int j = start; j <= end; j++) {
                    res.push_back(j);
                }
                last = end;
            }
        }
        return res;
    }
};