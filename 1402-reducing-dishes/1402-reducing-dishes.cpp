class Solution {
public:
    int solveUsingRec(vector<int>& sat, int i,int time){
        //base case
        if(i == sat.size())return 0;

        //including the current dish
        int includelikeTimeCoeff = time*sat[i] + solveUsingRec(sat,i+1,time+1);
        int excludelikeTimeCoeff = 0 + solveUsingRec(sat,i+1,time);//jab tak include nhi karemge tab tak time aage nhi badhega 
        return max(includelikeTimeCoeff,excludelikeTimeCoeff);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int ans = solveUsingRec(satisfaction,0,1);
        return ans;
    }
};