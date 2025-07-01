class Solution {
public:
    int possibleStringCount(string word) {
         
         int n = word.size();
         int cnt =1;
         for(int i=n-1;i>0;i--){
              if(word[i]!=word[i-1]){
                 continue;
              }
              else{
                 cnt++;
              }
         }
         return cnt;

    }
};