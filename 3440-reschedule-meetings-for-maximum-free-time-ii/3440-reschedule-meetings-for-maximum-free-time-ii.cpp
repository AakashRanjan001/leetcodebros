class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
         // ye bhi arrau aur  greedy ka ho skat ahia 
         vector<int>freeArr;
         freeArr.push_back(startTime[0] - 0);
         for(int i=1;i<startTime.size();i++){
             int gap = startTime[i] - endTime[i-1];
             freeArr.push_back(gap); 
         }
         freeArr.push_back(eventTime - endTime[endTime.size()-1]);

         int n = freeArr.size();
         //case1 : jab event ko dusre event ke uss parr karna hai either left or right
          // case 2 : jab evenet ko adjacent right ya left mei shift karna hai , no change in the relative order in between the evenets 
          vector<int>maxleftFree(n,0);
          vector<int>maxrightFree(n,0);

          for(int i=n-2;i>=0;i--){
             maxrightFree[i] = max(maxrightFree[i+1] , freeArr[i+1]);
          }
          for(int i = 1;i<n;i++){
             maxleftFree[i] = max(maxleftFree[i-1],freeArr[i-1]);
          }

          int res =0;
          for(int i=1;i<n;i++){
             int curreventTime = endTime[i-1] - startTime[i-1]; 
             // case 1 : moving completeley out 
             if(curreventTime <= max(maxleftFree[i-1],maxrightFree[i])){
                  res = max(res , freeArr[i-1] + curreventTime + freeArr[i]);
             } 

             // case 2 : shift left or right adjacnet 
              res = max(res, freeArr[i-1]+freeArr[i]);
          }
          return res;
    }
};