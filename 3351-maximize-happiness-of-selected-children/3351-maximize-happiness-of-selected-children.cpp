class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        

        int n = h.size();
        sort(h.rbegin(),h.rend());
         long long sum = 0;
        for(int i=0;i<k;i++){
            int a = h[i]-i;
            
            if(a>0)
            sum+=a;
            
            
        }
        return sum;
    }
};