class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
unordered_map<string,int>mpp;

for(int i=0;i<paths.size();i++){
    mpp[paths[i][0]]++;
}

for(int i=0;i<paths.size();i++){
    if(mpp.find(paths[i][1])==mpp.end()){
        return paths[i][1];
    }
}
  return "";
    }
};