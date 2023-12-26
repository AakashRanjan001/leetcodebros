class Solution {
public:

int peakelementindex(vector<int>nums){
int s=0;
int e=nums.size()-1;
int mid = s+ (e-s)/2;

for(;s<e;){
    if(nums[mid]<nums[mid+1]){
        s = mid +1;
    }
    else{
        e = mid;
    }
    mid = s + (e-s)/2;
}
return s;
}

    int findPeakElement(vector<int>& nums) {
        return peakelementindex(nums);
    }
};