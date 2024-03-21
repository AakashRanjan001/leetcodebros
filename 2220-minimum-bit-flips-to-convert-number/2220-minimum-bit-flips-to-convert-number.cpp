class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start^goal;
        int count =0;   //the no .of set bits will be equal to the no.of flips required 
                     
        for(int i=0;i<31;i++){
            if(ans &(1<<i)){
                count++;
            }
        }
        return count;
    }
};