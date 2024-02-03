class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        vector<vector<int>>ans;
        
        for(int i=0;i<n;i++){
            for(int j= i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(0<=i<j<k<n && abs(arr[i]-arr[j])<=a && abs(arr[j]-arr[k])<=b && abs(arr[i]-arr[k])<=c){
                       vector<int>temp={arr[i],arr[j],arr[k]}; 
                        ans.push_back(temp);
                    }
                }
            }
        }
    return ans.size();
        
    }
};