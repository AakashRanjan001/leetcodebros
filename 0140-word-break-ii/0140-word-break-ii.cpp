class Solution {
public:
    void solve(string s,int index, unordered_set<string>& wordDict, vector<string> &current, vector<string> &ans) {
        int n = wordDict.size();
        int m = s.size();
        if(index==m){
            string sentence="";
            for(int i =0;i<current.size();i++){
                sentence+=current[i];
                if(i!=current.size()-1){
                    sentence+=" ";
                }
            }
            ans.push_back(sentence);
        }

        for (int i = index; i < m; i++) {
            string a = s.substr(index, i-index+1);
            if (wordDict.find(a) != wordDict.end()) {
                current.push_back(a);
                solve(s, i + 1, wordDict, current, ans);
                current.pop_back();
            }

        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordset(wordDict.begin(),wordDict.end());
        vector<string> ans;
        vector<string>current;
        solve(s,0,wordset, current,ans);
        return ans;
    }
};
