// class Solution {
// public:
//      int solveOptimal(vector<int> & arr,vector<int> &lis){
//       if(arr.size() == 0)return 0;
//       vector<int>ans;
//       lis.push_back(1);
//       ans.push_back(arr[0]);


//       for(int i=1;i<arr.size();i++){
//           if(arr[i]>ans.back()){
//             // include this in the ans array 
//               ans.push_back(arr[i]);
//               lis.push_back(ans.size());
//           }
//           else{
//              // agar nnums[i]<ans.back then we can replace it , we can do it by using binary search
//               int index = lower_bound(ans.begin(),ans.end(),arr[i]) - ans.begin();
//               ans[index] = arr[i];
//               lis.push_back(index+1);
//           }
//       }
//       return ans.size();
//     }
//     int minimumMountainRemovals(vector<int>& nums) {
//          vector<int>lis,lds;  
//          //making lis  amd lds array by making eaxh element as pivot 
//          solveOptimal(nums,lis);

//          //for lis
//          reverse(nums.begin(),nums.end());
//          solveOptimal(nums,lds);

//         //  for(auto v:lis){
//         //      cout<<v<<" ";
//         //  }
//         //  cout<<endl;
//         //  for(int i = 0;i<nums.size();i++){
//         //      cout<<lds[nums.size() -i - 1]<<" "; 
//         //  }


//         //main logic 
//         // i want largest mountain ki range 
//          int largestMountain = INT_MIN;
//          for(int i=0;i<nums.size();i++){ 
//             if((lis[i] == 1 )|| (lds[nums.size() - i -1] == 1))continue;
            
//             largestMountain = max(largestMountain, lis[i] + lds[nums.size() - i -1]);

//          }
//          int minRemovals = nums.size() - largestMountain;
//          return minRemovals;
//     }
// };



class Solution {
public:
    int solveOptimal(vector<int>& nums, vector<int>& lis) {
        if (nums.size() == 0) return 0;
        vector<int> ans;
        lis.resize(nums.size(), 0); // Initialize lis array
        ans.push_back(nums[0]);
        lis[0] = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > ans.back()) {
                // Include this in the ans array
                ans.push_back(nums[i]);
                lis[i] = ans.size();
            } else {
                // Replace element using binary search
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
                lis[i] = index + 1;
            }
        }
        return ans.size();
    }

    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> lis, lds;

        // Compute LIS
        solveOptimal(nums, lis);

        // Compute LDS
        reverse(nums.begin(), nums.end());
        solveOptimal(nums, lds);
        reverse(nums.begin(), nums.end());
        reverse(lds.begin(), lds.end()); // Align LDS with original nums order

        // Find the largest mountain
        int largestMountain = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (lis[i] > 1 && lds[i] > 1) { // Ensure valid mountain
                largestMountain = max(largestMountain, lis[i] + lds[i] - 1);
            }
        }

        // Calculate minimum removals
        int minRemovals = nums.size() - largestMountain;
        return minRemovals;
    }
};
