// class Solution {
// public:
//     bool isValid(vector<int>& nums, int curr, int dir){
//          while(curr>=0 && curr<nums.size()){
//              if(nums[curr] == 0){
//                  curr+=dir; // phele moving in the left dir
//              }
//              else{
//                  nums[curr]--;
//                  dir = -dir;
//                  curr+=dir;
//              }
//          }
//         for(auto i:nums){ 
//             if(i!=0)return false;
//         }
//         return true;
//     }
//     int countValidSelections(vector<int>& nums) {
//         int n = nums.size();
//         int cnt = 0;
//         for(int i=n-1;i>=0;i--){
//             if(nums[i] == 0){
//                 vector<int>left = nums;
//                 vector<int>right = nums;
//                  if(isValid(left, i , -1) || isValid(right , i , 1)){
//                      cnt++;
//                  }
//             }
//         }
//         return cnt;
//     }
// };
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0LL), ls = 0, cases = 0;
        for (int num : nums) {
            int rs = total - ls - num;
            if (num == 0) {
                if (ls == rs) {
                    cases += 2;
                } else if (ls == rs - 1 || ls - 1 == rs) {
                    cases++;
                }
            }
            ls += num;
        }
        return cases;
    }
};
