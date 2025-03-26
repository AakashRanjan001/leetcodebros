typedef long long ll;
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
         ll n = grid.size();
          // how to find the target value it must be the emdian of the value 
          vector<int>temp;
          for(auto i:grid){
             for(auto j:i){
                 temp.push_back(j);
             }
          }
          sort(temp.begin(),temp.end());

          // for the case of -1 
          //saare convertible hone chahiye isi kaaran ye kiya to check for -1
          for(auto i:temp){
             if(abs(i-temp[0])%x !=0){
                 return -1;
             }
          }
            
          ll median = temp[temp.size()/2];
          int oper =0;
          for(auto i:temp){
             oper+=abs(i-median)/x;
          }
          return oper;

    }
};