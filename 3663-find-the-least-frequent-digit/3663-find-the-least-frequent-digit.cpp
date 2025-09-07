class Solution {
public:
    int getLeastFrequentDigit(int n) {
        string temp = to_string(n);
        unordered_map<char,int>mp;
        for(auto c: temp){
             mp[c]++;
        }
         int mini = INT_MAX;
         int ans;
        for(auto it: mp){
            if(it.second<mini){
                 mini = (int)it.second;
                 ans =  it.first - '0';
            }
            else if(it.second == mini){
                 ans = min(it.first - '0' , ans);
            }
        }
        return ans;
    }
};