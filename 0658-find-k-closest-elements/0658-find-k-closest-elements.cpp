class Solution {
public:
    vector<int>TwoPtrMethod(vector<int>&arr,int k ,int x){
        int l =0;
        int h = arr.size()-1;         //l = low and h = high
        while(h-l>=k){
            if(abs(arr[l]-x)>abs(x-arr[h])){    //by using two pointer approach
                l++;       
            }
               else{
                   h--;
               }
        }
               vector<int>ans;
               for(int i=l;i<=h;i++){
                   ans.push_back(arr[i]);
               }
               return ans;
    }
    
    
    
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return TwoPtrMethod(arr,k,x);
    }
};