class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int i=0;
        int j=0;
        int n = nums.size();

        int zeroes =0;
        int maxlen =0;

        while(j<n){
             //calculation  // hame o0ne ka use hi  nhi hai hame zeroes se deal karni hai 
             if(nums[j] == 0)zeroes++;

             while(zeroes > k){
                if(nums[i] == 0)zeroes--;
                  i++;
             }
            maxlen = max(maxlen,j-i+1);
            j++;

        }
        return maxlen;
    }
};