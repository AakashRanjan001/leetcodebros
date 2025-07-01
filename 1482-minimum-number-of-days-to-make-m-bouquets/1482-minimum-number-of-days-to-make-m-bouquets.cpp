class Solution {
public:
    bool isPossible(vector<int>&arr, int day, int m,int k){
         int cnt =0,numberofbouquets = 0;
         for(int i=0;i<arr.size();i++){      
             if(arr[i]<=day){
                 cnt++;
             }
             else{
                numberofbouquets+=(cnt/k);
                cnt =0;       
             }
         }
         numberofbouquets+=(cnt/k);
         if(numberofbouquets >=m)return true;
         return false;
    }
    int minDays(vector<int>& arr, int m, int k) {
         // n is teh no.of  flowers that is the size of array 
         int n = arr.size();
         if(n<m*k)return -1;
         //minimum of days chahiye to be able to amke m bouquets
         int mini = *min_element(arr.begin(),arr.end());
         int maxi = *max_element(arr.begin(),arr.end());

         for(int i= mini;i<=maxi;i++){
             if(isPossible(arr,i,m,k) == true){
                 return i;
             }
         }
         return -1;

    }
};