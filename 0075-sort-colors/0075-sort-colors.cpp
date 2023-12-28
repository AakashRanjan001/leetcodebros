class Solution {
public:
    void sortColors(vector<int>& nums) {
          for(int i=0;i<nums.size()-1;i++){  //selection sort 

    int minindex = i;  //we assume that first index is our minimum element
    //For the inner loop in order to find min elemenyt corressponding to the value of i
    for(int j=i+1;j<nums.size();j++){
      if(nums[j]<nums[minindex]){
        minindex = j;//if we found that j is muchminimum than arr[minindex] then store j
      }       //new minimum then store it
    }
    //after finding the new minelemnt we will swap the corresponding value of i
    swap(nums[i],nums[minindex]);
  }
    }
};