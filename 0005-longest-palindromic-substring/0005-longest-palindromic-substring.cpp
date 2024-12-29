// class Solution {
// public:
//    bool isPallindrome(string &s, int start,int end){
//        while(start<end){
//            if(s[start]!=s[end]){
//               return false;
//            }
//            start++;
//            end--;
//        }
//        return true;
//    }
//     string longestPalindrome(string s) {
//         string ans = "";
//         for(int i=0;i<s.size();i++){
//              for(int j=i;j<s.size();j++){
//             if(isPallindrome(s,i,j)){
//                 string temp = s.substr(i,j-i+1);//pehla starting index ,dusra length
//                 ans = temp.size() > ans.size() ? temp:ans; // agar temp mei jab ek elemnt aaya tab dekha ki uska size
//                 //ans se bada hai tab usko ans mei daal do
//                  }
//              }
//         }
//         return ans;
//     }
// };

class Solution {
public:
int maxlen = 1;// single char is also a pallindrome
int start =0; // it is the index of the largest pallindrome present  
bool solve(string &s, int i,int j){
     //base case
     if(i>=j)return true;

     bool flag = false;
     if(s[i] == s[j]){
         flag = solve(s,i+1,j-1);
     }
     if(flag == true){
         int currlen = j-i+1;
         if(currlen > maxlen) {
             maxlen = currlen;
             start = i; // storing the starting point of index of the larhgest pallindrome presebt
         }
     }
     return flag;
}

string longestPalindrome(string s) {
     int n = s.size();
     for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
             bool t = solve(s,i,j); // ham har ek substring ko uthake check karr rhe ki woh pallindrome hai ki nhi
        }
     }
     return s.substr(start,maxlen);

   }
};