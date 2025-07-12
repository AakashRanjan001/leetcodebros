class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
         // i have to calculate the longest continous free time 
         //thod abahut sliding windoe ka concept lag rha hai 

         vector<int>freetime;
         //origin se stating time tak bhi gap ho sakyta hai 
         freetime.push_back(startTime[0]);
         // ith index ka end time and (i-1)th index ka start time
         for(int i=1;i<startTime.size();i++){
             int gap = startTime[i] - endTime[i-1];
             freetime.push_back(gap);
         }

         freetime.push_back(eventTime - endTime[endTime.size()-1])

         // abb hame maximum sum subarray nikalna hai od size K+1
         int i=0;
         int j=0;
         int maxi = 0;
         int sum =0;

         while(j<freetime.size()){
             sum+=freetime[j];
             if(j-i+1<k+1){
              
             }
             else if(j-i+1 == k+1){
                  maxi = max(maxi,sum);
                  sum-=freetime[i];
                  i++;
             } 
             j++;
         }
         return maxi;

    }
};


