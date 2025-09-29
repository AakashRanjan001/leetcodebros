class Solution {
public:
    string majorityFrequencyGroup(string s) {
         
       int n = s.size();
       unordered_map<char,int>mp;
       for(auto i: s){
         mp[i]++;
       }

       unordered_map<int,vector<char>>groups;
       for(auto &it:mp){
          groups[it.second].push_back(it.first);
       }
       vector<char>bestg;
       int bestsize = -1;
       int bestfreq = -1;
       for(auto &i:groups){
         int k = i.first;
         int size = i.second.size();

         if(size>bestsize || (size == bestsize && k>bestfreq)){
             bestsize = size;
             bestfreq = k;
             bestg = i.second;
         }
       }

       string ans(bestg.begin(),bestg.end());
       return ans;
    }

};