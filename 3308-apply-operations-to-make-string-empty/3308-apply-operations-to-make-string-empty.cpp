class Solution {
public:
    string lastNonEmptyString(string s) {
      int maxi = INT_MIN;
      unordered_map<char,int>mp;  
    for(auto it:s){
        mp[it]++;
        maxi = max(maxi,mp[it]);
    }
    string ans ="";
    for(int i=s.size()-1;i>=0;i--){
        if(maxi==mp[s[i]]){
              ans+=s[i];
             mp[s[i]]--;
        }
    }
    reverse(ans.begin(),ans.end());
    
return ans;

    }
};