// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<pair<int,int>>p;
//         for(int i=0;i<n-1;i++){
//             for(int j=i+1;j<n;j++){
//                  p.push_back(make_pair(nums[i],nums[j]));
//             }
//         }
//         int diff = INT_MAX;
//         vector<int>ans;
//         for(int i=0;i<p.size();i++){
//             diff = min(diff , abs(p[i].first-p[i].second));
//             ans.push_back(diff);
//         }
//       sort(ans.begin(),ans.end());
//   int val =0;
//   for(int i=0;i<ans.size();i++){
//       while(k!=0){
//           val = ans[i];
//       }
//   }
     
//       return val;
      
//     }
// };

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int low = 0, high = nums[n - 1] - nums[0];
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            int j = 0;
            
            for (int i = 0; i < n; ++i) {
                while (j < n && nums[j] - nums[i] <= mid) {
                    j++;
                }
                count += j - i - 1;
            }
            
            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};
