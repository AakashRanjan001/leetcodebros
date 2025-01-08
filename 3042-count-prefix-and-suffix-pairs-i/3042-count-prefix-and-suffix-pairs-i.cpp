class Solution {
public:
    bool isPrefixAndSuffix(string &words1,string &words2){
         int len1 = words1.size();
        int len2 = words2.size();
         
         if(len1>len2)return false;

         if(words2.substr(0,len1) == words1 && words2.substr(len2-len1) == words1){
             return true;
            }
            return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt =0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                 if(isPrefixAndSuffix(words[i] , words[j])){
                     cnt++;
                 }
            }
        }
        return cnt;
    }
};