// // class Solution {
// // public:
// //     int maxDistinctElements(vector<int>& nums, int k) {

// //         int n = nums.size();
// //         sort(nums.begin(),nums.end());
// //         unordered_set<int>st;
    
// //           int element = nums[0] - k;
// //            nums[0] = element ;
// //            st.insert(nums[0]);
           
        
// //         for(int i=1;i<n;i++){
// //            element = nums[i]  - k;
// //             if( st.find(element) == st.end()){
// //                  nums[i] = element;
// //                  st.insert(nums[i]);
// //             }
// //             else{
// //                 nums[i] = element +1;
// //                 st.insert(nums[i]);
// //             }
            

            
// //         }
// //     }
// // };

// class Solution {
// public:
//     int maxDistinctElements(vector<int>& nums, int k) {
      
//       int n = nums.size();
//       sort(nums.begin(),nums.end());

//       nums[0] = nums[0] - k;
//       int prev;
//       int oper =1;
//       for(int i=1;i<n;i++){
//          prev = nums[i-1];
//          int mini = nums[i] - k;
//          int maxi = nums[i] + k;

//          if(nums[i] >= mini && nums[i] <= maxi){
//             nums[i] = prev +1;
//              if(nums[i]<=maxi){
//                 oper++;
//              }
//          }
//       }
//       return oper;

//    }
// };

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sort the array

        nums[0] = nums[0] - k; // Modify the first element within range
        int prev = nums[0];   // Track the previous value
        int oper = 1;         // Count of distinct elements

        for (int i = 1; i < n; i++) {
            int mini = nums[i] - k; // Minimum possible value for nums[i]
            int maxi = nums[i] + k; // Maximum possible value for nums[i]

            // Assign a value to nums[i] such that it's distinct and within [mini, maxi]
            if (prev + 1 <= maxi) {
                nums[i] = max(prev + 1, mini); // Ensure it's greater than prev
                oper++;                        // Increment count of distinct elements
            } else {
                nums[i] = maxi; // If prev + 1 is outside range, assign maxi
            }

            prev = nums[i]; // Update prev to the current value
        }

        return oper; // Return the number of distinct elements
    }
};
