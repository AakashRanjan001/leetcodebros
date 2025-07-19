class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
         // sort lexicographically 
         int n = folder.size();
         sort(folder.begin(),folder.end());
         string prev  = "";
         vector<string>ans;
         for(auto curr: folder){
              auto it = curr.find(prev+'/');
              if(prev.empty() || it!=0){
                 ans.push_back(curr);
                 prev = curr;
            

              }
         }
         return ans;

    }
};