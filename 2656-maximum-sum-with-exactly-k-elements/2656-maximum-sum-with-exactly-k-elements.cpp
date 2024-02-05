class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
    
        int n = nums.size();
        
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
        }

        int sum =0;
     
     
        for(int i=0;i<k;i++){
            
             sum = sum + maxi;
             maxi=maxi+1;
           
           
            }
        
        
        return sum;
        
    }
};