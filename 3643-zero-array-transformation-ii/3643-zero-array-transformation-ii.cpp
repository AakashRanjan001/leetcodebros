// class Solution {
// public:
//     int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
//         //ekdam brute solution
//           int oper =0;
//           for(int i=0;i<queries.size();i++){
//               int left = queries[i][0];
//               int right = queries[i][1];
//               int val = queries[i][2];

//               for(int j=left;j<=right;j++){
//                 //   int diff = nums[j]-val;
//                 //   if(diff>0){nums[j] = diff;}
//                 //   else {nums[j] = 0;}
                
//                 nums[j] = max(0 , nums[j] - val);
//               }
//              bool allZero = true;
//              for(auto i:nums){
//                 if(i!=0){
//                     allZero = false;
//                     break;
//                 }
//              }
//              if(allZero==false)oper++;        
//           }
        
//         for(auto it:nums){
//             if(it!=0)return -1;
//         }
//         return oper;
//     }
// };


class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int oper = 0;

        for (int i = 0; i < queries.size(); i++) {
  
            bool allZero = true;
            for (int num : nums) {
                if (num != 0) {
                    allZero = false;
                    break;
                }
            }
            if (allZero) return oper;

            int left = queries[i][0];
            int right = queries[i][1];
            int val = queries[i][2];

            for (int j = left; j <= right; j++) {
                int diff = nums[j] - val;
                nums[j] = (diff > 0) ? diff : 0;
            }

            oper++;
        }
        for (int num : nums) {
            if (num != 0) return -1;
        }

        return oper;
    }
};
