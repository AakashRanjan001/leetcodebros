class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
         vector<int>ans;
         unordered_map<int,bool>mp;
         for(auto i:friends){
             mp[i] = true;
         }

         for(int i=0;i<order.size();i++){
             if(mp.find(order[i])!=mp.end()){
                 ans.push_back(order[i]);
             }
         }
         return ans;
    }
};