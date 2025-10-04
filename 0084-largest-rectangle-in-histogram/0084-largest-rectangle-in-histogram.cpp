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

         // suppose after traversal some of the elemenst are still left 
          while(!st.empty()){
               int element = st.top();
               st.pop();
               int nse = n;
               int pse = st.empty() ? -1 : st.top();
               maxArea = max(maxArea , heights[element] * (nse - pse-1));
          }
          return maxArea;
    }
};