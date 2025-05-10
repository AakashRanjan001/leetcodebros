// class Solution {
// public:
//     long long minSum(vector<int>& nums1, vector<int>& nums2) {
//          bool f = false;
//          for(int i=0;i<nums1.size();i++){
//              if(nums1[i] == 0){
//                  f = true;
//              }
//          }
//          bool f1 = false;
//          for(int i=0;i<nums2.size();i++){
//              if(nums2[i] == 0){
//                  f1 = true;
//              }
//          }

//          if(f == false || f1 == false){
//               return -1;
//          }
//          long long sum1 = 0;
//          for(int i=0;i<nums1.size();i++){
//              if(nums1[i] == 0){
//                  nums1[i] = 1;
//              }
//              sum1+=nums1[i];
//          }
//          long long sum2 =0;
//          for(int i=0;i<nums2.size();i++){
//              if(nums2[i] == 0){
//                  nums2[i] = 1;
//              }
//              sum2+=nums2[i];
//          }
//        return max(sum1,sum2);

//     }
// };


class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long zeroe1 = 0, zeroe2 = 0;
        long long sum1 = 0, sum2 = 0;

        for (int num : nums1) {
            if (num == 0) zeroe1++;
            sum1 += num;
        }
        for (int num : nums2) {
            if (num == 0) zeroe2++;
            sum2 += num;
        }

        if (zeroe1 == 0 && zeroe2 == 0) {
            return sum1 == sum2 ? sum1 : -1;
        }

        if (zeroe1 == 0) {
            return (sum2 + zeroe2 <= sum1) ? sum1 : -1;
        }

        if (zeroe2 == 0) {
            return (sum1 + zeroe1 <= sum2) ? sum2 : -1;
        }

        return max(sum1 + zeroe1, sum2 + zeroe2);
    }
};
