class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int testDevices = 0;
     for(int i = 0; i < batteryPercentages.size(); i++){
        if(batteryPercentages[i] > 0){
            testDevices++;
            for(int j = i+1; j < batteryPercentages.size(); j++)
            {
                batteryPercentages[j] = max(batteryPercentages[j]-1, 0);
            }
        }
     }   
     return testDevices;
    }
};
