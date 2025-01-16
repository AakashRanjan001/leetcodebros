class Solution {
public:
    int findParent(vector<int>& parent , int node){
         
         if(parent[node] == node){
             return node;
             return parent[node] = findParent(parent,parent[node]); // path compression 
         }
         return parent[node];
    }
    void unionSet(int u,int v,vector<int> &parent, vector<int> &rank){
         u = findParent(parent,u);
         v = findParent(parent,v);

         if(rank[u]<rank[v]){
             parent[u] =v;
             rank[v]++;

         } 
         else{
            parent[v] = u;
            rank[u]++;
         }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        //need to find the no.of connected componets and no.of extra edges 
        vector<int>parent(n);
        vector<int>rank(n,0);

        for(int i=0;i<n;i++){
             parent[i] = i; //initialsisation ki sab khud ke hi parents hai 

        }
        int numberOfExtraEdges =0;
        //mai saari edges mei run karung aaur disjoint set wale operation karsunga 
        for(auto connection:connections){
             int u = connection[0];
             int v = connection[1];

             u = findParent(parent,u);
             v = findParent(parent,v);

             if(u!=v){ // matlab do alaga parents hai
               unionSet(u,v,parent,rank);
                 
             }
             else{
                 //extra edge 
                 numberOfExtraEdges++;
             }
        }
        int numberOFconnectedComponents = 0;
        for(int i=0;i<parent.size();i++){
             if(parent[i] == i){
                 numberOFconnectedComponents++; 
             }
          
        }
        int ans = numberOFconnectedComponents - 1;//no.of cables needed or number of oper
        return numberOfExtraEdges >=ans ? ans : -1;

    }
};