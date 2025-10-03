class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
         int n = asteroids.size();
         stack<int>st;
         for(int i=0;i<n;i++){
             
             if(asteroids[i]>0){
                 st.push(asteroids[i]);
             }
             else{
                 while(!st.empty() &&st.top()>0 &&  abs(asteroids[i])> st.top()){
                     st.pop();
                 }
                 //chcek condtition if the size of the asteroids in array and stack are same
                 if(!st.empty() && abs(asteroids[i]) == st.top()){
                     st.pop(); 
                 }
                 else if(st.empty() || st.top()<0){
                     st.push(asteroids[i]);
                 }

             }
         }
         vector<int>ans;
         while(!st.empty()){
             ans.push_back(st.top());
             st.pop();
         }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};