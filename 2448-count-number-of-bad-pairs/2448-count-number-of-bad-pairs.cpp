class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        //brute force 
        int n = nums.size();
        int cnt =0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                  if(i<j && (j-i)!=nums[j]-nums[i]){
                     cnt++;
                  }
            }
        }
        return cnt;
    }
};