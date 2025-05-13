typedef long long ll;
class Solution {
public:
    string makeSmallestPalindrome(string s) {
         ll n = s.size();
         int i=0,j=n-1;

         while(i<=j){
             if(s[i] == s[j]){
                 i++;
                 j--;
             }
             else if(s[j]<s[i]){
                 s[i] = s[j];
                 i++;
                 j--;
             }
             else{
                 s[j] = s[i];
                 i++;
                 j--;
             }
         }
         return s;
    }
};