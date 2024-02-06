class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        
        vector<double>ans;
        
        double Kelvin;
        double Farenheit;
        
        
        Kelvin = celsius + 273.15;
        Farenheit = celsius*1.80 +32.00;
        
        ans.push_back(Kelvin);
        ans.push_back(Farenheit);
        return ans;
    }
};