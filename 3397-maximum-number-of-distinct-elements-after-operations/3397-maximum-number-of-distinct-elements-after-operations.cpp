// class Solution {
// public:
//     int maxDistinctElements(vector<int>& nums, int k) {

//         int n = nums.size();
//         sort(nums.begin(),nums.end());
//         unordered_set<int>st;
    
//           int element = nums[0] - k;
//            nums[0] = element ;
//            st.insert(nums[0]);
           
        
//         for(int i=1;i<n;i++){
//            element = nums[i]  - k;
//             if( st.find(element) == st.end()){
//                  nums[i] = element;
//                  st.insert(nums[i]);
//             }
//             else{
//                 nums[i] = element +1;
//                 st.insert(nums[i]);
//             }
            

            
//         }
//     }
// };

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
      
      int n = nums.size();
      sort(nums.begin(),nums.end());
      nums[0] = nums[0] - k;
      int prev;
      int oper =1;
      for(int i=1;i<n;i++){
         prev = nums[i-1];
         int mini = nums[i] - k;
         int maxi = nums[i] + k;

         if(nums[i] >= mini && nums[i] <= maxi){
            nums[i] = prev +1;
             if(nums[i]<=maxi){
                oper++;
             }
         }
      }
      return oper;

   }
};

