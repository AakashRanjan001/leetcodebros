class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
    int i=0;
    int j = arr.size()-1;
    vector<vector<double>>temp;
    for(int i=0;i<arr.size();i++){
        for(int j=arr.size()-1;j>0;j--){
        temp.push_back({arr[i]*1.0 / arr[j]*1.0,arr[i]*1.0 ,arr[j]*1.0});

        }
    }
    vector<int>ans(2);
    sort(temp.begin(),temp.end());
    int first = temp[k-1][1];
    int sec = temp[k-1][2];
    return {first,sec};

    }
};