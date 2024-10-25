class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        int n = folder.size();
        //we have to sort it lexicographically such that the parent folder comes at the front and check the subfolders then 
        vector<string>ans;

        string prev = "";
        for(auto curr:folder){
            if(prev.empty() || curr.find(prev + "/")!=0){
                   ans.push_back(curr);
                   prev = curr;
            }
        }
        return ans;
//         prev + "/" concatenates prev (the previous folder) with a slash "/". This way, it forms the path that any subfolder of prev would begin with.
// curr.find(prev + "/") tries to find this combined string (prev + "/") as a prefix in curr.
// If curr is a subfolder of prev, then curr would start with prev + "/" and this expression will return 0 (indicating the start index).
// != 0:

// The != 0 checks if the result of curr.find(prev + "/") is not 0, meaning prev + "/" does not appear at the beginning of curr.
// If curr.find(prev + "/") != 0, curr is not a subfolder of prev, so it can be added to the answer list (ans).
          
    }
};