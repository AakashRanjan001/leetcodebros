typedef long long ll;
ll MOD = 1e9 + 7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
      //dijkstra algo ka use lag rga 
      //first create the adj list 
      vector<vector<pair<int,int>>>adj(n);
      for(auto &it : roads){
          adj[it[0]].push_back({it[1] , it[2]});    
          adj[it[1]].push_back({it[0] , it[2]});

      }     

      //ek distance array banao for the shortest distrance from one to the next node that is the singke source Shortest path 
      vector<ll>dist(n,LLONG_MAX);
      vector<ll>ways(n,0);

      dist[0] = 0;
      ways[0] = 1; 

      //dijkstra ke loye minheap ka use hoga 
      priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<>>pq;
      pq.push({0,0});

      while(!pq.empty()){
          auto [d,u] = pq.top();
          pq.pop();

          if(d > dist[u])continue;
          for(auto &[v,w] : adj[u]){
             ll new_dist = d + w;

             if(new_dist < dist[v]){
                 dist[v] = new_dist;
                 ways[v] = ways[u];
                 pq.push({new_dist , v});
             }
             // importany case 
             else if(new_dist == dist[v]){ 
                ways[v] = (ways[u] + ways[v]) % MOD;
             }
          } 
      }
          return ways[n-1];
    }  
};