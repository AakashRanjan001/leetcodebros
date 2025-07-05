class Solution {
public:
    int findLucky(vector<int>& arr) {
         int maxelement = *max_element(arr.begin(),arr.end());
         vector<int>hash(maxelement+1,0);
         for(int i=0;i<arr.size();i++){ 
             hash[arr[i]]++;
         }
         int maxi = -1;
         for(int i=0;i<arr.size();i++){
              if(arr[i] == hash[arr[i]]){
                 maxi = max(maxi , arr[i]);
              }
         }
         return maxi;

    }
};