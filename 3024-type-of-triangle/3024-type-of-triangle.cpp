class Solution {
public:
    bool isValid(vector<int>&nums, int i){
        return (nums[i]+nums[i+1]>nums[i+2] && nums[i+1]+nums[i+2] > nums[i] && nums[i] + nums[i+2]>nums[i+1]);
    }
    string triangleType(vector<int>& nums) {
        int n = nums.size();
        string ans = "";
        
        for(int i=0;i<n-2;i++){
     if(isValid(nums,i)){
             if(nums[i] == nums[i+1] && nums[i+1] == nums[i+2] && nums[i] == nums[i+2]){
                 ans = "equilateral";
             }
             else if(nums[i]!=nums[i+1] && nums[i]!=nums[i+2] && nums[i+1]!=nums[i+2]){
                   
                        ans = "scalene";          
             }
             else{
                 ans = "isosceles";
             }
             return ans;
         }
         

     }
     return "none";
        
    }
};