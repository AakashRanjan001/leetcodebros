class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
          
          //BRUTE
         for(int i=0;i<shifts.size();i++){
             int st = shifts[i][0];
             int e = shifts[i][1];
             int dir = shifts[i][2];

             for(int j = st;j<=e;j++){
                 if(dir == 1){
                     s[j] = (s[j] -'a' + 1)%26 + 'a';
                 }
                 else{
                     s[j] = (s[j]-'a'+25) % 26 + 'a';
                 }
             }
         }
         return s;
    }
};