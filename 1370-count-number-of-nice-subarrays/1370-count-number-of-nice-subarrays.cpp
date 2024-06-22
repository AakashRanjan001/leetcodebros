class Solution {
public:

    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> pre;
        unordered_map<int,int> mp;
        pre.push_back(arr[0]); 
        int ct = 0;
        for(int i = 1; i < n; i++) pre.push_back(arr[i] + pre[i - 1]);
        for(int i = 0; i < n; i++)
        {
            if(pre[i] == k) ct++;
            if(mp.find(pre[i] - k) != mp.end()) ct += mp[pre[i] - k];
            mp[pre[i]]++; 
        }        
        return ct; 
    }


    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++) nums[i] = (nums[i] % 2 != 0);
        return subarraySum(nums,k);
    }
};

      
      