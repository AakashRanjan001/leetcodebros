class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
    int ans =0;
    int fullbottles = numBottles;
    int empty =0;
    while(fullbottles){
        int currBottles = fullbottles + empty;
        ans += fullbottles;

        fullbottles = currBottles/numExchange;
        empty = currBottles%numExchange;

        
    }
    return ans;
    }
};