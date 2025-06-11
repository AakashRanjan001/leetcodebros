class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
           
        //    unordered_map<int,int>m;    // BY USING MAP
        //    for(int i=0;i<x.size();i++){
        //       if(m.find(x[i]) == m.end()){
        //            m[x[i]] = y[i];
        //       }
        //       else{
        //           m[x[i]] = max(m[x[i]] , y[i]);
        //       }
        //    }
        //    vector<int>res;
        //    for(auto i:m){
        //      res.push_back(i.second);
        //    }
        //    if(res.size()<3)return -1;
        //    sort(res.rbegin(),res.rend());
        //    int sum =0;
        //    for(int i=0;i<3;i++){
        //      sum+=res[i];
        //    }
           
        //  return sum;
           
        unordered_map<int,int>m;
        for(int i=0;i<x.size();i++){
             if(m.find(x[i]) == m.end()){
                  m[x[i]] = y[i];
             }
             else{
              m[x[i]] = max(m[x[i]], y[i]);
             }
        }
        priority_queue<int>pq;
        for(auto i:m){
             pq.push(i.second);
        }
        if(pq.size()<3)return -1;
        int sum =0;
        for(int i=0;i<3;i++){
             sum+=pq.top();
             pq.pop();
        }
        return sum;

    }
};