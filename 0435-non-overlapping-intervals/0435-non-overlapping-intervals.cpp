class Solution {
public:
    bool static comp(vector<int>& a, vector<int>& b)
    {
        return a[1] < b[1];
    }
   
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(), comp);
        int cnt =1;
        int lastendtime = intervals[0][1];

        for(int i=1;i<n;i++){
            if(intervals[i][0]>=lastendtime){
                cnt+=1;
                lastendtime = intervals[i][1];

            }
        }
        return (n - cnt);
    }
};