
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
       
        for(auto &vec:queries){
             int xors=0;
            int s=vec[0];
            int e=vec[1];
            if(s==e) ans.push_back(arr[s]);
            else{
                for(int i=s;i<=e;i++){
                    xors^=arr[i];
                }
                ans.push_back(xors);
            }
        }
        return ans;
    }
    
};