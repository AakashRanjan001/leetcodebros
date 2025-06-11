class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
           
           unordered_map<int,int>m;
           for(int i=0;i<x.size();i++){
              if(m.find(x[i]) == m.end()){
                   m[x[i]] = y[i];
              }
              else{
                  m[x[i]] = max(m[x[i]] , y[i]);
              }
           }
           if(m.size()<3)return -1;
           int sum =0;
           for(auto i:m){
               sum+=i.second;
           }
         return sum;
         
    }
};