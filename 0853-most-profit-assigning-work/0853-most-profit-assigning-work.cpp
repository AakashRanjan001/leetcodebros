class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        int n = difficulty.size();
        int m = worker.size();
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            p.push_back({difficulty[i],profit[i]});
        }
sort(p.begin(),p.end());
sort(worker.begin(),worker.end());

       int maxi = 0 ;
       long long sum =0;
      int i=0;
      int j=0;
    
    while(i<n && j<m){

        if(worker[j]<p[i].first){
            sum+=maxi;
            j++;
        }
        else{
            maxi = max(maxi,p[i].second);
            i++;
        }
    }
    while(j<m){
        sum+=maxi;
        j++;
    }
    return sum;

    }
};