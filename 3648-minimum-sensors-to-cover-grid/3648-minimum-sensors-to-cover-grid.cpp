class Solution {
public:
    int minSensors(int n, int m, int k) {
       int sensorinonerange = 2*k+1;
       int ans = ((n+sensorinonerange-1)/sensorinonerange) * ((m+sensorinonerange-1)/sensorinonerange);
       return ans;
    }
};