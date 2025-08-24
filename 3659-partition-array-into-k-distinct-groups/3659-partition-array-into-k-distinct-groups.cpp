class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        //   int n = nums.size();
        //   if(n%k!=0)return false;
          
        //   sort(nums.begin(),nums.end());
        //   for(int i=0;i<n-k;i++){
        //      if(nums[i] ==  nums[i+k])return false;
        //   }
        //   if(n == k)return false;
        //   return true;
             int n = nums.size();
        if (n % k != 0) return false; // must divide evenly

        unordered_map<int,int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        int groups = n / k;
        for (auto &p : freq) {
            if (p.second > groups) {
                return false; // too many occurrences of one element
            }
        }
        return true;
    }
};