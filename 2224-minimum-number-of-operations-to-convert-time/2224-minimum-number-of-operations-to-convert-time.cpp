class Solution {
public:
    int convertTime(string current, string correct) {
     int currentMin = 60*stoi(current.substr(0,2)) + stoi(current.substr(3,2));
     int targetMin  = 60*stoi(correct.substr(0,2)) + stoi(correct.substr(3,2));

     int difference = targetMin - currentMin;
     int cnt =0;
     vector<int>steps = {60,15,5,1};
     for(int s:steps){
         cnt += difference/s;
         difference = difference%s;
     }
     return cnt;
       
    }
};