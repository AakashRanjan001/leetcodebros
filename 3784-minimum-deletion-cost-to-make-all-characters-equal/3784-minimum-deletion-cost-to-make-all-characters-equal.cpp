typedef long long ll;
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
          vector<ll>storecost(26,0);
          ll totalcost =0;
          int n = s.size();
          for(int i=0;i<n;i++){
             storecost[s[i] - 'a']+=cost[i];
            totalcost+=cost[i];
          }
          ll maxcostfordel = *max_element(storecost.begin(),storecost.end());
          return totalcost - maxcostfordel;
    }
};