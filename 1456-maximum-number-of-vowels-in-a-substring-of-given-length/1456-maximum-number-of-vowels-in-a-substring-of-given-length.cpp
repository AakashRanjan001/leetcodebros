class Solution {
public:
   bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
              
    }
    int maxVowels(string s, int k) {
         
         int n = s.size();
         int maxi = INT_MIN;
         for(int i=0;i<=n-k;i++){
            int cnt =0;
            for(int j=i;j<i+k;j++){
                 if(isVowel(s[j])){
                     cnt++;
                 }
            }
            maxi = max(maxi,cnt);
         }
         return maxi;
    }
};