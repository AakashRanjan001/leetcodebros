class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int n = arrays.size();
        int mini = arrays[0][0];
        int maxi = arrays[0].back();
        int max_dist =INT_MIN/2;

        for(int i=1;i<n;i++){
             max_dist = max(max_dist , max(abs(arrays[i].back() - mini) , abs(maxi - arrays[i][0])) );
             maxi = max(maxi , arrays[i].back());
             mini = min(mini , arrays[i][0]);
        }
       
       
        return max_dist;

    }
};