// class Solution {
// public:
//     long long maximumTotalSum(vector<int>& mH) {
        
//         long long n = mH.size();
//         sort(mH.rbegin(),mH.rend());
//         vector<int>ans;
//         ans.push_back(mH[0]);
//         for(int i=1;i<n;i++){
//              if (ans.back()>mH[i]){
//                  ans.push_back(mH[i]);
//              }
//              else if(ans.back()<mH[i]){
//                 return -1;
//              }
//              else{
//                 ans.push_back(mH[i] - 1);
//              }
//         }
        
//         int sum =0;
//         for(int i=0;i<ans.size();i++){
//             if(ans[i] == 0)return -1;
//             else{
//             sum+=ans[i];
//             }
//         }
//         return sum;

//     }
// };
class Solution {
public:
    long long maximumTotalSum(vector<int>& mH) {
        long long n = mH.size();
        sort(mH.rbegin(), mH.rend()); // Sort in descending order
        vector<int> ans;
        
        ans.push_back(mH[0]);
        for(int i = 1; i < n; i++) {
            if (ans.back() > mH[i]) {
                ans.push_back(mH[i]);
            } 
            else if (ans.back() <= mH[i] && ans.back() > 1) {
                ans.push_back(ans.back() - 1); // Decrement to ensure uniqueness and stay positive
            } 
            else {
                return -1; // If no valid height can be assigned, return -1
            }
        }

        long long sum = 0;
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] <= 0) return -1; // Heights must be positive
            sum += ans[i];
        }
        return sum;
    }
};
