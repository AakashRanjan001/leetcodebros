// class Solution {
// public: // this is the Brute Force approach 
// BY ARYAN MITTAL ------------------------------>

// bool canRepairInTime(vector<int>& ranks, int cars, int time) {
//     long long repaired = 0;
//     for (int r : ranks) {
//         repaired += sqrt(time / r);  // Max cars this mechanic can repair
//         if (repaired >= cars) return true;
//     }
//     return false;
// }
//     long long repairCars(vector<int>& ranks, int cars) {
//     long long maxRank = *max_element(ranks.begin(), ranks.end());
//     long long left = 1, right = maxRank * cars * cars;  

//     for (int t = left; t <= right; t++) {
//         if (canRepairInTime(ranks, cars, t)) {
//             return t;  
//         }
//     }
//     return -1; // Should never reach here
//     }
// };


 class Solution {
public:
   bool time_is_sufficient(vector<int>& ranks,int &cars,long long min_given){
      long long cars_done = 0;
      for(auto r:ranks){
         // c is the no.of cars performed in mid minutes 
         long long c = floor(sqrt(min_given/r));
         cars_done+=c;

      }
      if(cars_done>=cars)return true;
      return false;
   }
  long long repairCars(vector<int>& ranks, int cars) {
       // same approach just we apply the binary search to reduce tthe search space 

    //    long long maxRank = *max_element(ranks.begin(),ranks.end());
       long long left = 1 , right = 1e14;
        while(left<right){
             long long mid = left+(right-left)/2;
             //abb iss mid ke hisaab se calculate karo total cars 

             if(time_is_sufficient(ranks,cars,mid)){
                right = mid;
             }
             else{
                left = mid+1;
             }
        }
       return left;
          
    }
};


 