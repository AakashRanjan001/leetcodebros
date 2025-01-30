class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        
        //brute force 
       vector<int>temp;
       int maxi = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            maxi = 0;
            for(int j=i;j<n;j++){
                for(int k=i ;k<=j;k++){
                    maxi = max(nums[k],maxi);
                }
                temp.push_back(maxi);
            }
        }
        int cnt =0;
        for(int i=0;i<temp.size();i++){
            if(temp[i]>=left && temp[i]<=right){
                 cnt++;
            }
        }
        return cnt;
    }
};