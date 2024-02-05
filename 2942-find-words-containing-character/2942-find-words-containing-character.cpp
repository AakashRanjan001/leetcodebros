class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int pos =words[i].find(x);
           if (pos!=string::npos){

           ans.push_back(i);
           pos=words[i].find(x);
           }
        }
        return ans;
    }
};