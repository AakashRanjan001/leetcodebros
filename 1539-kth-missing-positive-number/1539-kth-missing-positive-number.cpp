class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // int maxi = *max_element(arr.begin(),arr.end());
        // vector<bool>temp(maxi+1,0);
        // for(int i=0;i<arr.size();i++){
        //      temp[arr[i]] = 1;
        // }
        // int ans = -1;
        // int cnt =0;
        // for(int i=1;i<=maxi;i++){
        //       if(temp[i] == 0){
        //          cnt++;
        //            if(cnt == k){
        //            ans = i;
        //           return ans;
        //         }
        //  }
            
        // }
        // return maxi +(k-cnt);

        //METHOD 2 ------> BRUTE FORCe

        // for(int i=0;i<arr.size();i++){
        //      if(arr[i]<=k)k++;
        //      else break;
        // }
        // return k;


  int l =0;
  int h = arr.size()-1;

  while(l<=h){
     int mid = l+(h-l)/2;
     int missing = arr[mid] - (mid+1);
     if(missing<k)l = mid+1;
     else h = mid-1;
  }
 return h+1+k;
       
    }
};