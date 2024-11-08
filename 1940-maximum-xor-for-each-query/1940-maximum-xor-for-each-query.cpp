
class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {

// get k first

        int k = (1<<maximumBit)- 1;

        int n = nums.length;
       
       int xor=nums[0];


        for (int i = 1; i < n; i++) {
// get xor of all elements
           xor^=nums[i];
        }
     int []res=new int[n];
        for (int i =0; i <n; i++) {
      // do xor with k
            res[i] = xor ^ k;
//now update xor to remove last element beacuse xor of same no will be zero
            xor^=nums[n-1-i];
        }

        return res;

    }

    
}