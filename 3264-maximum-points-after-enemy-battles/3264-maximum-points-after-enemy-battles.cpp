class Solution {
public:
    long long maximumPoints(vector<int>& eE, int currentEnergy) {
        
        sort(eE.begin(),eE.end());
        long long points =0;
        int i=0;
        int j = eE.size()-1;

        while(i<=j){
            if(currentEnergy>=eE[i]){  //the enemy is unmarked
                int x = currentEnergy/eE[i];
                currentEnergy-=x*eE[i];
                points += x*1;
            }
            else if(points>=1){
                currentEnergy+=eE[j];
                j--;
            }
            else{
                break;
            }
           
           
        }
        return points;
    }
};