class Solution {
public:
    int maxWidthRamp(vector<int>& nums) { // GREEDy
    //  int currWidth = 0;    // BRUTE force approach showing TLE
    //  int n = nums.size();

    //  for(int i=0;i<n-1;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(nums[i]<=nums[j]){
    //             currWidth = max(currWidth , j -i);
    //         }
    //     }
    //  }
    //  return currWidth;

 
 int n = nums.size();
        stack<int> s;

    
        for (int i = 0; i < n; i++) {
            if (s.empty() || nums[i] < nums[s.top()]) {
                s.push(i);
            }
        }
        
        int ans = 0;

        // Step 2: Find the maximum width
        for (int j = n - 1; j >= 0; j--) {
            while (!s.empty() && nums[s.top()] <= nums[j]) {
                ans = max(ans, j - s.top());
                s.pop();
            }
        }

        return ans;

    }
};