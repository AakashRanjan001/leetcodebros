class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        
        map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<=n-k;i++){  // out of bounds na jaane ke liye apon i<=n-k kiye hai       
          unordered_set<int>unique;
            for(int j=i;j<i+k;j++){
                //  if(mp.find(nums[i]) == mp.end()){
                //      mp[nums[j]]++;
                //  }
                //  else{
                //     mp[nums[j]]--;
                //  }
                unique.insert(nums[j]);
            }
                for(auto it:unique){
                    mp[it]++;
                }

        }
        int maxi = -1;
        for(auto it:mp){
            if(it.second == 1){
                 maxi = max(maxi , it.first);
            }
        }
        return maxi;
    }
};