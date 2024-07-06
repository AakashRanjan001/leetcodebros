class Solution {
public:
    int passThePillow(int n, int time) {
        int rounds=time/(n-1);
        int remaining=time%(n-1);
        if(rounds%2!=0) return n-remaining;
        return 1+remaining;        
    }
};
