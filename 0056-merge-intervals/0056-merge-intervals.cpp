class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
         sort(intervals.begin(),intervals.end());
         
         int s = intervals[0][0];
         int e = intervals[0][1];

         vector<vector<int>>ans;
         ans.push_back({s,e});
         for(int i=1;i<intervals.size();i++){
              int curr_s = intervals[i][0];
              int curr_e = intervals[i][1];

              if(curr_s > e){
                 ans.push_back({curr_s,curr_e});
                 s = curr_s;
                 e = curr_e;
              }

             else{
                 e = max(curr_e,e);
                 s = min(curr_s,s);
                 ans.back()[0] = s;
                 ans.back()[1] = e;
             }
             
         }
         
     return ans;
     
    }
};