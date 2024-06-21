class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int gi = 0, ge = minutes;
        int sumg = 0;
        int sumng=0;
        int res = 0;
        for(int i=gi; i<ge; i++){
            sumg += customers[i];
        }
        for(int i=ge; i<customers.size(); i++){
            if(grumpy[i]==0){
                sumng += customers[i];
            }
        }
        res = sumg + sumng;
        gi ++;

        for(int i=0; i<customers.size()-ge; i++){
            sumg -= customers[i];
            sumg += customers[ge+i];
            if(!grumpy[ge+i]) sumng -= customers[ge+i];
            if(!grumpy[i]) sumng += customers[i];
            if(res<(sumg+sumng)) res = sumg+sumng;
        }

        return res;
    }
};
