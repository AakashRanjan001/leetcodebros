class Solution {
public:

int peakindexelement(vector<int>arr){
int start =0;
int end = arr.size()-1;
int mid = start + (end -start)/2;

for(;start<end;){
if(arr[mid]<arr[mid +1]){
    start = mid +1;

}
else {
    end = mid;
}
mid = start + (end -start)/2;

}

return start;
}


    int peakIndexInMountainArray(vector<int>& arr) {
        return peakindexelement(arr);
    }
};