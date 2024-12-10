// class Solution {
// public:
//     int maximumLength(string s) {
//         // brute is to generate all the substrings 
//         int n = s.size();
//         if(n<3)return -1;
//         vector<string>substrings;
        
//         for(int i=0;i<n;i++){
//             string temp ="";
//             for(int j=i;j<n;j++){
//                   temp+=s[j];
//                   substrings.push_back(temp);
//             }
//         }

//         unordered_map<string,int>countHash;
//         for(string x:substrings){
//             countHash[x]++;
//         }
//         int res = -1;
        
//         for(auto &[key,count]:countHash){
//             if(count>=3){
//                 res = max(res, (int)key.size());
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        if (n < 3) return -1;

        unordered_map<string, int> countHash;

        // Generate substrings and count their frequencies
        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = i; j < n; j++) {
                temp += s[j];
                countHash[temp]++;
            }
        }

        // Find the maximum length of substrings appearing at least 3 times
        int res = -1;
        for (auto &[key, count] : countHash) {
            if (count >= 3) {
                res = max(res, (int)key.size());
            }
        }

        return res;
    }
};
