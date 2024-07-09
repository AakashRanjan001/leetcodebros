
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double sum = 0;
        int time = 0,n = customers.size();
        for(int i = 0;i < n;i++){
            if(customers[i][0] > time){
                time = customers[i][0] + customers[i][1];
            }else{
                time += customers[i][1];
            }
            sum += (time - customers[i][0]);
        }

        return sum / n;
    }
};