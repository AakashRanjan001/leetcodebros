class Solution {
public:
   bool topoSortBFS(int n,unordered_map<int,list<int>> &adjList){
         queue<int>q;
         vector<int>ans;//jaha ans store kareng e
         unordered_map<int,int>indegree;

         //step 1: now first we have to calculate the indegree first 
         for(auto i:adjList){
             int src = i.first;
             for(auto nbr:i.second){
                 indegree[nbr]++;
             }
         }
         // n--> no.of nodes 
         //step 2: push he nodes into the queue whose indegree will become zero 
         for(int i=0;i<n;i++){
             if(indegree[i] == 0){
                 q.push(i);
             }
         }
     

     //step 3: Normal BFS 
       while( !q.empty()){
          int fnode = q.front();
          q.pop();
          ans.push_back(fnode);

           for(auto nbr:adjList[fnode]){
               indegree[nbr]--;

               if(indegree[nbr] == 0){
                   q.push(nbr);
               }
           }
       }

       if(ans.size() == n)return true ; // matlab no cycle is present , valid toposort
       else{
           return false; // not a valid toposort 
       }
   }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         //It is a Toposort Question 
       unordered_map<int,list<int>> adjList;

       for(auto task: prerequisites){
            int u = task[0];
            int v = task[1];

            //hame edge banani hai v-->u ulta here as depenedency ulti ihai 
            adjList[v].push_back(u);
       }
       bool ans = topoSortBFS(numCourses,adjList);
       return ans;


    }
};