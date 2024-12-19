class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
 // a very nice appraoch that is useful 
        int maxi = -1;
        int cnt =0;
        for(int i=0;i<n;i++){
            maxi = max(arr[i],maxi);
            if(maxi == i)cnt++;
        }
        return cnt;
    }
};