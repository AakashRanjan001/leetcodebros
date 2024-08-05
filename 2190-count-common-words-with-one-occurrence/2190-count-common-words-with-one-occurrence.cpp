class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
       unordered_map<string,int>mp1;
        unordered_map<string,int>mp2;

        for(auto i:words1){
            mp1[i]++;
        }
        for(auto it:words2){
            mp2[it]++;
        }
       int cnt =0;
       for(auto i:mp1){
        if(mp2.find(i.first)!=mp2.end() && i.second ==1 && mp2[i.first]==1){
            cnt++;
        }
       }
       return cnt;
    }
};