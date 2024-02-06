
class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
                unordered_map<string,vector<string>>mp;
                        for(auto s:strs){
                                    string x=s;
                                                sort(x.begin(),x.end());
                                                            mp[x].push_back(s);
                                                                    }
                                                                            vector<vector<string>>answer;
                                                                                    for(auto x:mp){
                                                                                                answer.push_back(x.second);
                                                                                                        }
                                                                                                                return answer;
                                                                                                                    }
                                                                                                                    };