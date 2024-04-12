class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int i = 0;
        int j = height.size() - 1;

        int left_max = height[0];
        int right_max = height[j];

        while (i < j) {
            if(left_max <= right_max){
                water += left_max - height[i];
                i++;
                left_max = max(left_max ,height[i]);
                
            }
            else{
                water += right_max - height[j];
                j--;
                right_max = max(right_max ,height[j]);
                
            }
        }
        return water;
    }
};
