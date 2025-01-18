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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        //for cfeation of disjoint sets 
        vector<int>parent(n);
        vector<int>rank(n,0);

        // shuru mei saare nodes khudke hi parents hote gau 
        for(int i=0;i<n;i++)parent[i] = i;

        // union karne ke loye ek map ki jarroorat hai 
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
             auto account = accounts[i];
             for(int j=1;j<account.size();j++){
                  string &mail = account[j];
                  auto it = mp.find(mail);
                  //mail id ko map mei doondho 
                   if(it == mp.end()){
                     mp[mail] = i;// agar mail nhi hia map mei tab push kar dte the 
                   }
                   else{
                      //same mail id wpaas se aa gya matlab inn ka unionk karna padega
                      unionSet(i,it->second,parent,rank);
                   }
             }
        }
          unordered_map<int,set<string>>preAns;// after performing the union operartions we are doing this 
          for(auto it:mp){
             int accountNumber = it.second;
             auto mail = it.first;
             accountNumber = findParent(parent , accountNumber);
             preAns[accountNumber].insert(mail);
          }

          //abb preAns use karke final ans bana dnega hai
           vector<vector<string>>ans;
           for(auto it:preAns){
               auto accountNumber = it.first;
               auto st = it.second;

               vector<string>v; //naam lagane ke liye 
               v.push_back(accounts[accountNumber][0]);
               for(auto mail:st){
                  v.push_back(mail);
               }
               ans.push_back(v);
           }
        
         return ans;
    }
};