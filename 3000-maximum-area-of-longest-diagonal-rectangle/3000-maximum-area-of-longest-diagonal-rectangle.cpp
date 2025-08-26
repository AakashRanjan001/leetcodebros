class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
         int n = dimensions.size();
         int m = dimensions[0].size();

         int maxArea = 0;
         double maxD = 0;

         for(int i=0;i<n;i++){
             int l = dimensions[i][0];
             int b = dimensions[i][1];

             maxD = max(maxD, sqrt(l*l + b*b));
             if(sqrt(l*l + b*b) == maxD){
                 maxArea = max(maxArea, l*b);
             }
         }
         return maxArea;
    }
};