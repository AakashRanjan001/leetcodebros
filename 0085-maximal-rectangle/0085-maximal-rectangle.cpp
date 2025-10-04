class Solution {
public:
     int largestRectangleArea(vector<int>& heights) {
         int n = heights.size();
         stack<int>st;
         int maxArea = 0;

         for(int i=0;i<n;i++){
             while(!st.empty() && heights[st.top()] > heights[i]){
                  int element = st.top();
                  st.pop();

                  //matlab iss particular bar ke liye abb mujhe nse mil gya hai 
                  int nse = i;
                  int pse = st.empty() ? -1 : st.top();
                  int area = heights[element]*(nse - pse - 1);
                  maxArea = max(maxArea , area);
             }
             st.push(i);
         }

         // suppose after traversal some of the elemenst are still left  in the stack it means inka nse nhi hoga toh hypothetical index daalna padega 
          while(!st.empty()){
               int element = st.top();
               st.pop();
               int nse = n;
               int pse = st.empty() ? -1 : st.top();
               maxArea = max(maxArea , heights[element] * (nse - pse-1));
          }
          return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if (matrix.empty() || matrix[0].empty()) return 0; // edge case

           int n = matrix.size();
           int m = matrix[0].size();
           vector<vector<int>>prefsum(n,vector<int>(m,0));

           //traversing column wise to calculatye the prefsum 
           for(int j=0;j<m;j++){
               int sum =0;
               for(int i=0;i<n;i++){
                   if(matrix[i][j] == '0')sum =0;
                   else sum+=1;
                   prefsum[i][j] = sum;
               }
           }
           int maxArea = 0;
           for(int i=0;i<n;i++){
               maxArea = max(maxArea , largestRectangleArea(prefsum[i]));
           }
           return maxArea;
    }
};