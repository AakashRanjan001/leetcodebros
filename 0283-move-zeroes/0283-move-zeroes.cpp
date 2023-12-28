class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>temp;
         for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0)
            temp.push_back(nums[i]);
    }

    // number of non-zero elements.
    int nz = temp.size();

    //copy elements from temp
    //fill first nz fields of
    //original array:
    for (int i = 0; i < nz; i++) {
        nums[i] = temp[i];
    }

    //fill rest of the cells with 0:
    for (int i = nz; i < nums.size(); i++) {
        nums[i] = 0;
    }
    }
};