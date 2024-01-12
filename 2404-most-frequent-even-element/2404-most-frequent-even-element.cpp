class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                mpp[nums[i]]++;
            }
        }
        int ans =-1;
        int freq = INT_MIN;
        for(auto it:mpp){
            if(it.second>freq){
                freq = it.second;
                ans = it.first;
                
            }
        }
        return ans;
            
    }
};