class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int n= costs.size();
        int count =0;
        for(int i=0;i<n;i++){
            if(costs[i]<=coins){
                count++;
                coins-=costs[i];
            }
            else{
                break;
            }
        }
         return count;

    }
};