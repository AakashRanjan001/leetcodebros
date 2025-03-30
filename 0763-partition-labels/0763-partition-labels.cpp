// typedef long long ll;
// class Solution {
// public:
//     vector<int> partitionLabels(string s) {
//         ll n = s.size();
//         map<char,int>mp;
//         // this map stores the char ---> last index of that character
//         for(int i=0;i<n;i++){
//              int ind = s[i] - 'a';
//              if(mp.find(s[i])==mp.end()){
//                  mp[s[i]] = ind;
//              }
//              else{
//                  ind = i; // agar dubara same char aa gya tab
//              }
//         }
//         vector<int>ans;
//         int i=0;
//         while(i<n){
//              int currlen = 1;
//              int j = mp[s[i]];
//              while(i<j){
//                  j = max(j , mp[s[i]]);
//                  currlen++;
//                  i++;
//              }
//              ans.push_back(currlen);
//              i++;
//         }
//          return ans;
//     }
// };


typedef long long ll;
class Solution {
public:
    vector<int> partitionLabels(string s) {
         
         ll n = s.size();
         map<char,int>mp;
         //store the ;ast index of each caharacter 
         for(int i=0;i<n;i++){
             mp[s[i]] = i;
         }

         int maxInd = 0;
         vector<int>ans;
         int last_partition = 0;
         for(int i=0;i<n;i++){
             maxInd =  max(maxInd,mp[s[i]]);

             if(i == maxInd){
                 ans.push_back(i - last_partition +1);
                 last_partition = i+1;
             }
             
         }
         return ans;
         
    }
};
