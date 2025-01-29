class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>mp;
        int n = s.size();
        int i=0;
        int j=0;
        int maxlen =0;
        int maxFreq = 0;

        while(j<n){
             //calcukation 
            mp[s[j]]++;
            maxFreq = max(maxFreq, mp[s[j]]);

            while((j-i+1) - maxFreq > k){
                 mp[s[i]]--;
                 i++;
            }
            maxlen = max(maxlen,j-i+1);
            j++;

        }
        return maxlen;
    
         
    }
};