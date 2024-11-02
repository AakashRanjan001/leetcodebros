// class Solution {
// public:
//     bool isCircularSentence(string sentence) {
//         int n = sentence.size();
//         // ye vector nhi hai ye ek string hai
//         if(sentence[0] != sentence[n-1]){
//             return false;
//         }

//         for(int i=0;i<n;i++){
//             if(sentence[i] = ' '){
//                 if(sentence[i-1] != sentence[i+1]){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        // Check if first and last characters match
        if (sentence[0] != sentence[n - 1]) {
            return false;
        }
        
        // Check each word's last character with the next word's first character
        for (int i = 0; i < n; i++) {
            if (sentence[i] == ' ') {
                // Compare last character of the current word with the first of the next word
                if (sentence[i - 1] != sentence[i + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
