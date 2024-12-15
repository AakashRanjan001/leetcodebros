class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
            int index = events[0][0];
            int ans = events[0][1];

            for(int i=1;i<events.size();i++){
                 int diff = events[i][1] - events[i-1][1];

                 if(diff>ans){
                     ans = diff;
                     index = events[i][0];
                 }
                 else if(diff == ans){
                    ans = diff;
                    index = min(index , events[i][0]);
                 }

            }
            return index;
    }
};