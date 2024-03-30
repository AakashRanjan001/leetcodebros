class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return subarray(nums,k)-subarray(nums,k-1);
    }  //for exactly k distinct eleemnts we are using this subtracting k by k-1
    int subarray(vector<int>&nums,int k){
        unordered_map<int,int>freq;   //sliding window 

        int n = nums.size();
        int left =0;
        int total_count =0;
        for(int right =0;right<n;right++){
            freq[nums[right]]++;
        
          while(freq.size()>k){
            freq[nums[left]]--;
            

            if(freq[nums[left]]==0){freq.erase(nums[left]);}
            left++;
          }
           total_count +=(right-left+1);

        }
        
return total_count;

    }
};