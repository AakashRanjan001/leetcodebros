// class Solution {
// public:
//     string reverseWords(string s) {
//         int n = s.size();
//         string temp = "";
//         vector<string>arr;
//         for(int i=0;i<n;i++){
//             temp+=s[i];
//              if(s[i] == ' '){
//                 arr.push_back(temp); 
//                 temp.clear();
//              }
//         }
//          if (!temp.empty()) arr.push_back(temp);
//          int i=0;
//          int j = arr.size()-1;
//          while(i<j){
//              swap(arr[i],arr[j]);
//              i++;
//              j--;
//          }
//         string ans = "";
//         for(int k=0;k<(int)arr.size();k++){
//              if(k>0)ans+=' ';
//              ans+=arr[k];
//         }
//         return ans;

//     }
// };
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> arr;
        string temp = "";

        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if (!temp.empty()) {      // avoid pushing empty words
                    arr.push_back(temp);
                    temp.clear();
                }
            } else {
                temp += s[i];
            }
        }
        if (!temp.empty()) arr.push_back(temp); // push last word

        int i = 0, j = (int)arr.size() - 1;
        while (i < j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }

        string ans = "";
        for (int k = 0; k < (int)arr.size(); k++) {
            if (k > 0) ans += ' ';
            ans += arr[k];
        }
        return ans;
    }
};
