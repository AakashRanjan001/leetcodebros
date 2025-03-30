class Solution {
public:
    bool isPallindrome(string s){
         int n = s.size();
         int i=0;
         int j=n-1;

         while(i<j){
             if(s[i]!=s[j])return false;
             i++;
             j--;
         }
         return true;
    }
    int longestPalindrome(string s, string t) {
         
      int n = s.size();
      int m = t.size();
      int len = 1;

         for(int i=0;i<n;i++){
             string s1 = "";
             for(int j=i;j<n;j++){
                 s1+=s[j];

                 if(isPallindrome(s1))len = max(len,j-i+1);
                 for(int k=0;k<m;k++){
                     string t1 = "";
                     for(int r = k;r<m;r++){
                         t1+=t[r];

                         if(isPallindrome(t1))len = max(len , r-k+1);

                         if(isPallindrome(s1 + t1)){
                             int temp = s1.size() + t1.size();
                             len = max(len , temp);
                         }
                     }
                 }

             }
         }
         return len;
    }
};