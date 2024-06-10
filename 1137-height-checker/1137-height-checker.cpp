class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>curr = heights;
        int cnt =0;
        sort(heights.begin(),heights.end());
        for(int i=0;i<heights.size();i++){
            if(curr[i]!=heights[i]){
                cnt++;
            }
        }
        return cnt;
    }
};