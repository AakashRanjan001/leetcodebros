// class Solution {
// public:
//     int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
//         map<int,pair<int,int>>mp; // was not able to solve by myself !! 
//         map<int,int>row;
//         map<int,int>col;

//         for(int i=0;i<mat.size();i++){
//             for(int j=0;j<mat[0].size();j++){
//                  mp[mat[i][j]] = {i,j};
//             }
//         }
        
//         for(int i=0;i<arr.size();i++){
//              auto p = mp[arr[i]];
//              row[p.first]++;
//              col[p.second]++;

//              if(row[p.first] == mat.size()){
//                 return i;
//              }
//              if(col[p.second] == mat[0].size()){
//                 return i;
//              }
//         }
      
//         return -1;
//     }
// };


class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int, pair<int, int>> find;
        map<int, int> mp;
        map<int, int> mpp;
        int m = mat.size();
        int n = mat[0].size();
        int s = arr.size();

        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                find[mat[i][j]] = {i, j};
            }
        }

        for (int i = 0; i < s; i++) 
        {  
            pair p=find[arr[i]];
            mp[p.first]++;
            mpp[p.second]++;
            if(mp[p.first]==n){
            return i;
            }
            if(mpp[p.second]==m){
            return i;
            }
        }
        return -1;
    }
};