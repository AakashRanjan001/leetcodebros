class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int cnt =0;
             for(int j=0;j<m;j++){
                 int prod = 1LL*spells[i]* potions[j];
                 if(prod>=success){
                     cnt++;
                 }
             }
             ans.push_back(cnt);
        }
        return ans;
    }
};