class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
         // Not able to solve saw the video , have to practice the prefix sum videos
         int leftmaxval = values[0];
         int maxscore =0;
         int n = values.size();
         for(int i=1;i<n;i++){
             int currval = values[i] - i;
             maxscore = max(maxscore , currval + leftmaxval);
             leftmaxval = max(leftmaxval , values[i] + i);
         }
      return maxscore;
    }
};