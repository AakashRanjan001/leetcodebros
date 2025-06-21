// class Solution {
// public:
//     int minimumDeletions(string word, int k) {
//          int n = word.size();
//           map<char,int>mp;
//           for(int i=0;i<n;i++){
//              mp[word[i]]++;
//           }
//           int mini = INT_MAX;
//           for(int i=0;i<n;i++){
//               int freq_q = mp[word[i]];
//               int del =0;

//               for(int j=0;j<n;j++){
//                   if(j == i)continue;
//                   else if(mp[word[j]] < freq_q){
//                       del+=mp[word[j]];
//                   }
//                   else if(abs(freq_q - mp[word[j]])>k){
//                      del+=abs( mp[word[j]] - (freq_q + k));
//                   }
//               }
//               mini = min(del,mini);
//           }
//           return mini;
//     }
// };


class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();
        map<char, int> mp;

        for (int i = 0; i < n; i++) {
            mp[word[i]]++;
        }

        vector<int> freq;
        for (auto it : mp) {
            freq.push_back(it.second);
        }

        int mini = INT_MAX;

        for (int i = 0; i < freq.size(); i++) {
            int freq_q = freq[i];
            int del = 0;

            for (int j = 0; j < freq.size(); j++) {
                if (freq[j] < freq_q) {
                    del += freq[j]; // delete all occurrences
                } else if (freq[j] - freq_q > k) {
                    del += freq[j] - (freq_q + k); // reduce to freq_q + k
                }
            }

            mini = min(del, mini);
        }

        return mini;
    }
};
