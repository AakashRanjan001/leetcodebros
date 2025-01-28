// class Solution {
// public:
//     vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
      
//       int n = nums.size();
//       int i=0;
//       int j = n-1;
//       bool swapping = false;
//       while(i<j){
//          if(abs(nums[i] - nums[j])<=limit && nums[i]<=nums[j]){
//               swapping = false;
//               j--;
//          }
//          else if(abs(nums[i] - nums[j])<=limit && nums[i]>nums[j]){
//             swapping = true;
//             swap(nums[i],nums[j]);
           
//          }
//          else if(abs(nums[i] - nums[j])>limit){
//              j--;
//          }

//           else if(i == j){
//              i++;
//              j= n-1;
//           }
//       }
//       return nums;
//     }
// };


#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    std::vector<int> lexicographicallySmallestArray(std::vector<int>& nums, int limit) {
        int n = nums.size();
        int i = 0;

        while (i < n) {
            int j = i;
            
            // Identify the segment where consecutive differences are within the limit
            while (j + 1 < n && std::abs(nums[j] - nums[j + 1]) <= limit) {
                j++;
            }

            // Sort the identified segment
            std::sort(nums.begin() + i, nums.begin() + j + 1);

            // Move to the next segment
            i = j + 1;
        }
        
        return nums;
    }
};
