class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        for(int i=0;i<words.size();i++){
             for(int j=0;j<words[i].size();j++){
                 if(words[i][j] == x){
                     int ind = i;
                     ans.push_back(ind);
                     break;
                 }
             }
        }
        return ans;
    }
};