
// class Solution {
// public:
//     void GeneratePermutations(string &s1, int ind, vector<string> &ans, int n) {
//         // Base case
//         if (ind == n - 1) {
//             ans.push_back(s1);
//             return;
//         }

//         for (int i = ind; i < n; i++) {
//             swap(s1[ind], s1[i]);

//             // Recursive call
//             GeneratePermutations(s1, ind + 1, ans, n);

//             // Backtrack
//             swap(s1[ind], s1[i]);
//         }
//     }

//     bool checkInclusion(string s1, string s2) {
//         int n = s1.size();
//         int m = s2.size();

//         // Generate all the permutations of s1
//         int ind = 0;
//         vector<string> ans;
//         GeneratePermutations(s1, ind, ans, n);

//         // Check if any permutation of s1 is a substring of s2
//         for (const string &perm : ans) {
//             if (s2.find(perm) != string::npos) {
//                 return true;
//             }
//         }

//         return false;
//     }
// };
// class Solution {
// public:

//    bool checkInclusion(string s1, string s2) {
//     int n = s1.size();
//     int m = s2.size();

//     if(n>m)return false; // agar ulta ho gya size for the edge case 

//      vector<char>freq_s1(26,0);
//      vector<char>freq_window(26,0);

//      for(char ch:s1){
//         freq_s1[ch-'a']++;
//      }

//      for(int i=0;i<n;i++){
//         freq_window[s2[i] - 'a']++;
//      }

//      if(freq_s1 == freq_window)return true;

//      //aur agar nhi hai tab window aage badaho aur shuruat se window ka size kam kar do 
//      for(int i=n;i<m;i++){
//         //add the next element
//         freq_window[s2[i]-'a']++;
//         //shrink from the first 
//         freq_window[s2[i-n]-'a']--;

//      }
//      if(freq_s1 == freq_window){
//         return true;
//      }
//      return false;


//      }
//    };


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        // Edge case: if s1 is longer than s2, s1 cannot be a permutation of any substring of s2
        if (n > m) return false;

        // Frequency arrays for s1 and the current window in s2
        vector<int> freq_s1(26, 0), freq_window(26, 0);

        // Fill frequency array for s1
        for (char c : s1) {
            freq_s1[c - 'a']++;
        }

        // Sliding window initialization: fill freq_window with the first n characters of s2
        for (int i = 0; i < n; i++) {
            freq_window[s2[i] - 'a']++;
        }

        // Check if the first window is a permutation
        if (freq_s1 == freq_window) return true;

        // Slide the window across s2
        for (int i = n; i < m; i++) {
            // Add the next character in the window
            freq_window[s2[i] - 'a']++;
            // Remove the first character of the previous window
            freq_window[s2[i - n] - 'a']--;

            // Check if the current window is a permutation
            if (freq_s1 == freq_window) return true;
        }

        return false;
    }
};

