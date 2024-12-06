// class Solution {
// public:
//     int maxCount(vector<int>& banned, int n, int maxSum) {
        
//         int n1 = banned.size();
//         set<int>st;
//         for(int i=0;i<n1;i++){
//             st.insert(banned[i]);
//         }
//         vector<int>temp;
//         for(int i=1;i<=n;i++){
//             if(st.find(i)==st.end()){
//                    temp.push_back(i);
//             }
//             else{
//                 continue;
//             }
//         }

//         int cnt=0;
//         int sum =0;
//         for(int i=0;i<temp.size();i++){
//             sum+=temp[i];
             
//              if(sum<=maxSum){
//                 cnt++;
//              }           
//         }
//         return cnt;
//     }
// };

 // we can optimise by not using the extra space that we are taking in the temp 
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Step 1: Store banned numbers in a set for quick lookup
        unordered_set<int> bannedSet(banned.begin(), banned.end());

        // Step 2: Iterate over numbers from 1 to n and calculate sum and count
        int cnt = 0;
        int sum = 0;

        for (int i = 1; i <= n; i++) {
            if (bannedSet.find(i) != bannedSet.end()) continue; // Skip banned numbers

            if (sum + i > maxSum) break; // Stop if adding the current number exceeds maxSum
            
            sum += i;
            cnt++;
        }

        return cnt;
    }
};
