class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.begin(),h.end());

        int n = h.size();
        int x =0;
        long long sum = 0;
        for(int i=n-1;i>=0;i--){
         if(x==k)break;
         if(h[i]-x>0){
         sum+=h[i]-x;
         
         }
     x++;
        }
        return sum;
    }
};