class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
    int n = nums.size();
    int i =0;
    int j=0;
    int count =0;
    
    int product = 1;
    while(i<=j && j<n){
        
        product = product*nums[j];

        if(product<k){
            count += j-i+1;
            j++;
        }
        else{
            while(i<=j && product>=k){
                product/=nums[i];
                i++;
                

            }
            if(i<=j && product<k){
               count += j-i+1;
            j++;
            }
        }
       
        
    }
    
return count;
    }
};