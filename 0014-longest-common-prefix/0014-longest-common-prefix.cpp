class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            string temp = "";

            for(auto j: strs[i]){
                temp+=j;
                mp[temp]++;
            }
        }
        string temp;
        int res =0;
        for(auto i:mp){
            if(i.second == n && i.first.size() > res){
                   res = i.first.size();
                   temp = i.first;
            }
        }
        return temp;
    }
};