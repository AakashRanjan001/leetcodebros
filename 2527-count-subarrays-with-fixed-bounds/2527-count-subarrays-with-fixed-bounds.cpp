class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            //sliding window question
    long long ans =0;
    int left_index =-1;
    int right_index =-1;
    int bad_index =-1;
  
    for(int i=0;i<nums.size();i++){
        if(nums[i]<minK || nums[i]>maxK){
            bad_index = i;
        }
        else{
            if(nums[i]==minK)left_index =i;
            if(nums[i]==maxK)right_index = i;

        }
        ans+=max(0, min(left_index ,right_index)-bad_index);
    }
   return ans;

    }
};