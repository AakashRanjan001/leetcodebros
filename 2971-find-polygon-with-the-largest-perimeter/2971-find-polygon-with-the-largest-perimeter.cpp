class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        int i= n-1;
        while(i>=0)
        {
            if(i==1){
                return -1;
            }
            if(sum - nums[i]<=nums[i]){
               
                sum = sum - nums[i];
               --i;
            }
           
            else{
                return sum ;
            }
        }
        return sum ;
    }
};