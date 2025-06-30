// class Solution {
// public:   // THIS ANSWER IS CORRECTTTTTT---_____-------->>>>>
//     long long func(vector<int>& piles,int speed){
//           long long hours =0;
//           for(int i=0;i<piles.size();i++){
//              hours+=(piles[i]+speed-1)/speed;
//           }
//           return hours;
//     }
//     int minEatingSpeed(vector<int>& piles, int h) {


//         // BRUTE FORCE , will gicve the TLE---->> 
//         //  int n = piles.size();
//         //  int maxBanana = *max_element(piles.begin(),piles.end());
//         //  for(int k=1;k<=maxBanana;k++){
//         //      long long cnt =0;
//         //      for(int i=0;i<n;i++){
//         //          cnt+=(piles[i]+k-1)/k;// ceil(piles[i]/k);
//         //      }
//         //      if(cnt<=h)return k;
//         //  }
//         //  return maxBanana; 
        
//         int n = piles.size();
//         int maxelement = *max_element(piles.begin(),piles.end());
//         int low = 1, high =  maxelement;
//         long long ans = INT_MAX;

//         while(low<=high){
//              int mid = low+(high-low)/2;

//             int total_hrs = func(piles,mid);
//              if(total_hrs<=h){
//                  ans = mid;
//                  high = mid-1;
//              }
//              else{
//                  low = mid+1;
//              }
//         }
//          return ans;
//     }
// };



class Solution {
public:
    int hourstaken(int mid,vector<int>&piles,int h){
        int n=piles.size();
        long long hours=0;
        int remaining=0;
        for(int i=0;i<n;i++){
            hours+=(piles[i]+mid-1)/mid;
            if(hours>h) return -1;
        }
        return 1;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxi=0;
        int ans=maxi;
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        int low=1;
        int high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            int hours=hourstaken(mid,piles,h);
            if(hours==1){
                high=mid-1;
                ans=mid;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};

