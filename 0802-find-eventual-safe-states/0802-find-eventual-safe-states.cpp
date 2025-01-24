class Solution {
public:
   bool checkCyclicGraphUsingDFS(vector<vector<int>>& graph,int src,unordered_map<int,bool> &visited ,unordered_map<int,bool> &dfsVisited,vector<int> &safeNode){
        visited[src] = true;
        dfsVisited[src] = true;
        safeNode[src] = 0;
        
        for(auto nbr:graph[src]){
            if(!visited[nbr]){
                 bool aagekaAns = checkCyclicGraphUsingDFS(graph,nbr,visited,dfsVisited,safeNode);
                 if(aagekaAns == true){
                      return true;
                 }
            }
            if(visited[nbr] == true && dfsVisited[nbr] == true){
                 return true ; // yes a cycle is present there 
            }
        }
        //wapas jaate hue backtrack karna hai 
        //matalba apon aise path mei pahuch gye jaha hame terminal node mil gya aur koi cycle nhi hai 
        dfsVisited[src] = false;
        safeNode[src] = 1;
        return false;
        
        
    } 
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
           vector<int>ans;
        unordered_map<int,bool>visited ,dfsVisited;
         vector<int>safeNode(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                checkCyclicGraphUsingDFS(graph,i,visited,dfsVisited,safeNode); 
            }
        }
        for(int i=0;i<V;i++){
          if(safeNode[i] == 1){ 
              ans.push_back(i);
        }
        }
        return ans;
    }
};