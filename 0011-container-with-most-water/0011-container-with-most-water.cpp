
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0;
        int right = height.size()-1;
        int maxArea = INT_MIN;
        
        while(left<right){
            
            int currentArea = min(height[left],height[right])*(right-left);
            maxArea = max(currentArea,maxArea);
            
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
            
        
        }
        return maxArea;
        
    }
};