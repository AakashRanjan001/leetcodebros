class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        int color_dist=0;
    int max_color_dist = INT_MIN;
    for(int i=0;i<colors.size();i++){
        for(int j=i+1;j<colors.size();j++){
           if(colors[i]!=colors[j]) {
           color_dist=abs(i-j);
           max_color_dist= max(color_dist,max_color_dist);
           }
        }
    }
 return max_color_dist;


    }
};