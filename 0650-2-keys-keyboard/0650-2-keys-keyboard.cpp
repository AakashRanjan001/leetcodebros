
class Solution {
public:
    int helper(int i, int icr, int n){
        if(i==n) return 0;
        if(i>n) return 1e9;
        int minSteps = 1e9;
        minSteps = min(minSteps, 1+helper(i+icr,icr,n));
        if(i!=icr){
            minSteps = min(minSteps, 2+helper(i+i,i,n));
        }
        return minSteps;
    }
    int minSteps(int n) {
        if(n==1) return 0;
        return 1+helper(1,1,n);
    }
};