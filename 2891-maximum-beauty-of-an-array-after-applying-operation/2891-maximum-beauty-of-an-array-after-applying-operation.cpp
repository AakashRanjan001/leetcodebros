class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();

        //sliding woindoe approach
        sort(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int cnt =0;
        
        while(j<n){
            
            while(nums[j]-k > nums[i]+k){
                i++;
            }
            cnt = max(cnt,j-i+1);
            j++;
       
        }
        return cnt;
    }
};