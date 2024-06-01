class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int>mpp;
        for(int i=0;i<stones.size();i++){
            mpp[stones[i]]++;
        }
        int sum =0;
        for(int i=0;i<jewels.size();i++){
            if(jewels[i]==stones[i]){
               sum+= mpp[stones[i]];
            }
        }
        return sum;
    }
};