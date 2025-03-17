class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        int n = nums.size();
        int total_pairs = n/2;

        sort(nums.begin(),nums.end());
        int cnt =0;
        for(int i=0;i<n-1;i+=2){
             if(nums[i] == nums[i+1]){
                cnt++;
             }
        }
        if(cnt == total_pairs)return true;
        return false;
    }
};