class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();
        unordered_map<char,int>mp;

        for(int i=0;i<n;i++){
             mp[s[i]]++;
        }
        int odd =0;
        int even =INT_MAX;
        for(auto it:mp){
            if(it.second % 2 !=0){
                 odd = max(it.second,odd);
            }
            else{
                 even = min(it.second,even);
            }
        }
        return odd-even;
    }
};