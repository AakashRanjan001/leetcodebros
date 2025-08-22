class Solution {
public:
    bool isAnagram(string s, string t) {
         int n = s.size();
         int m = t.size();

         sort(s.begin(),s.end());
         sort(t.begin(),t.end());

         if(n!=m)return false;
         int i=0,j=0;
         while(i<n && j<m){
              if(s[i] != t[j]){
                 return false;
              }
              i++;
              j++;
         }
         return true;
    }
};