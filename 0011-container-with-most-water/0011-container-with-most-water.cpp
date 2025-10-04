class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxi = -1;
        int area = 0;
        int i=0;
        int j = n-1;
        while(i<j){
             if(height[i]<height[j]){
                area = height[i]*(j-i);
                 i++;
             }
             else{
                area = height[j]*(j-i);
                j--;
                 
             }
             maxi = max(maxi,area);
        }
        return maxi;
    }
};