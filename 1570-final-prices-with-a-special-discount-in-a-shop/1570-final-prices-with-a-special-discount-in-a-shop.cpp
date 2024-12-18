class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int i=0;
        int j=1;

        int n = prices.size();
        while(i<n-1){
             if(j<n && prices[j]<=prices[i]){
                prices[i]-=prices[j];
                i++;
                j=i+1;
             }
             else{
                 if(j>=n){
                     i++;
                     j=i+1;
                 }
                 else{
                     j++;
                 }
             }
        }
        return prices;
    }
};