class Solution {
public:
   bool isPallindrome(string &s, int start,int end){
       while(start<end){
           if(s[start]!=s[end]){
              return false;
           }
           start++;
           end--;
       }
       return true;
   }
    string longestPalindrome(string s) {
        string ans = "";
        for(int i=0;i<s.size();i++){
             for(int j=i;j<s.size();j++){
            if(isPallindrome(s,i,j)){
                string temp = s.substr(i,j-i+1);//pehla starting index ,dusra length
                ans = temp.size() > ans.size() ? temp:ans; // agar temp mei jab ek elemnt aaya tab dekha ki uska size
                //ans se bada hai tab usko ans mei daal do
                 }
             }
        }
        return ans;
    }
};