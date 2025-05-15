class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {    
        int ind =0;
        vector<string>ans;
        ans.push_back(words[0]);           
        for(int i=1;i<groups.size();i++){
             if(groups[i]!=groups[i-1]){
                 ind = i;
                 ans.push_back(words[ind]);
             }
        }
        return ans;
        
    }
};