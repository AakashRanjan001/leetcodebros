// class Solution {
// public:
//     int minSwaps(string s) {
      
//      int n = s.size();
//      int i=0;
//      int j = n-1;
//     int swap_cnt =0;
//      while(i<j){
//          if(i == 0 &&  j== n-1){
//             if(s[i] == ']' && s[j] =='['){
//                 swap(s[i],s[j]);
//                 i++;
//                 j--;
//                 swap_cnt++;
//             }
//          }
//          if(i>0 && j<n-1){
//             if((s[i] == ']' && s[i-1] == '[') && (s[j] =='[' && s[j+1] ==']') ){
//                 i++;
//                 j--;
//             }
//             else if(s[i] =='[' && s[j] == ']'){
//                 i++;
//                 j--;
//             }
//             else{
//                 swap_cnt++;
//             }
//          }
//      }
//      return swap_cnt;

//     }
// };
// class Solution {
// public:
//     int minSwaps(string s) {
//         int imbalance = 0, maxImbalance = 0;

//         // Traverse the string to find the maximum imbalance
//         for (char c : s) {
//             if (c == '[') {
//                 imbalance++;  // Increase imbalance when you encounter an opening bracket
//             } else {
//                 imbalance--;  // Decrease imbalance for a closing bracket
//             }

//             // Keep track of the maximum imbalance
//             maxImbalance = min(maxImbalance, imbalance);
//         }

//         // The number of swaps required is half of the max imbalance
//         // Because one swap fixes two imbalanced brackets
//         return (-maxImbalance + 1) / 2;
//     }
// };

class Solution{
    public:
    int minSwaps(string s){

        stack<char>st;
        for(char ch : s){
            if(ch == '['){
                st.push(ch);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        return (st.size()+1)/2;
    }
};



