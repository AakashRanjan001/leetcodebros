// class Solution {
// public:
//     long long maxProduct(vector<int>& nums) {
//         // matlab largest and secondlargest hi toh nikalna hai 

//         long long largest = LLONG_MAX;
//         long long second_largest = LLONG_MAX;

//         for(int i=0;i<nums.size();i++){
//              if(abs(nums[i])>largest){
//                 second_largest = largest;
//                  largest = abs(nums[i]);
//              }
//              else if(abs(nums[i])>second_largest && abs(nums[i])!=largest){
//                  second_largest = abs(nums[i]);
//              }
//         }
//         return (largest * second_largest *1LL);
//     }
// };

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long largest = 0;
        long long second_largest = 0;

        for (int i = 0; i < nums.size(); i++) {
            long long val = abs(nums[i]);
            if (val > largest) {
                second_largest = largest;
                largest = val;
            } else if (val > second_largest && val != largest) {
                second_largest = val;
            }
        }

        long long ans =  (long long)largest * (long long)second_largest * 100000;
        return ans;
    }
};
