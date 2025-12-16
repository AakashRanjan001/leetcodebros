class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // means the error her withe the problem of set is that , we have to modify the array also , therefore we have to think it otherwise 

        // it is a two pointer approach 
        // i jo hai woh sirf unique element mei hi point karta hai 
        // j jo hai woh unique element i ko laake dega 

        int n = nums.size();
        int i=0,j=1;

        while(j<n){
            //  if(nums[i] == nums[j]){ j ko tab tak aage badhao jab tak nums[i]!=nums[j] na ho jjaye
              if(nums[i] == nums[j]){
                 j++;
             }
             else{ // j ko unique lement mila hai 
                 i++;
                 nums[i] = nums[j];
                 j++;
                 
             }
        }
        return i+1;
        
    }
};