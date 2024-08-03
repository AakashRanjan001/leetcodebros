class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto &i:target){
            mp[i]++;
        }
        for(auto &i:arr){
            mp[i]--;
        }
      for(auto it:mp){
        if(it.second!=0)return false;
      }
      return true;
    }
};