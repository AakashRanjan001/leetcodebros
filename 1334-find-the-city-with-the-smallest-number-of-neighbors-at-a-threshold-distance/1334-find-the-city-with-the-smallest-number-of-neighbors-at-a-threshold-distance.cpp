// class Solution {
// public:
//     int Dijkstra(int src,int n, unordered_map<int,list<pair<int,int>>> &adjList, int &distanceThreshold){
//         vector<int>dist(n, INT_MAX);
//         set<pair<int,int>>st;

//          dist[src] = 0;
//          st.insert({0,src});
//          int reachabaleCities =0; // cities having atmost having distance threshold distance


//          while(!st.empty()){
//              auto top = *st.begin();
//              int nodeDist = top.first;
//              int node = top.second;

//              //mujhe unn sab cities ka count chahiye jo reacahable hai within threshold val
//              //node!=src matlab mai 0--->0 nmhi jaana chaata 
//              if(node!=src &&  nodeDist<=distanceThreshold){
//                   reachabaleCities++;
//              }

//              //update neighbor 
//              for(auto nbr:adjList[node]){
//                  int currDist = nodeDist + nbr.second;
//                  if(currDist<dist[nbr.first]){
//                      auto it = st.find({dist[nbr.first], nbr.first});
//                      if(it!=st.end()){
//                         st.erase(it);//remove the current entry
//                         dist[nbr.first] = currDist;
//                         st.insert({dist[nbr.first], nbr.first});
//                      }
//                  }
//              }
//          }

//          return reachabaleCities;

//     }
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         unordered_map<int,list<pair<int,int>>> adjList;
//         // create the Adjacency list 
//          for(auto edge : edges){
//              int&u = edges[0];
//              int&v = edges[1];
//              int&wt = edges[2];

//              adjList[u].push_back(make_pair(v,wt)); // as bidirectional and undirected 
//              adjList[v].push_back(make_pair(u,wt));
//          }

//          //mujhe harr node ke correspomding karna hia 
//          int city =0;
//         int minreachabaleCities = INT_MAX;
//         for(int u=0;u<n;u++){
//             int reachabaleCitiesCount = Dijkstra(u,n,adjList,distanceThreshold);
//             if(reachabaleCitiesCount <= minreachabaleCities){
//                 minreachabaleCities = reachabaleCitiesCount;
//                 city = u;
//             }
//         }
//         return city;
//     }
// };


class Solution {
public:
    int Dijkstra(int src, int n, unordered_map<int, list<pair<int, int>>> &adjList, int distanceThreshold) {
        vector<int> dist(n, INT_MAX);
        set<pair<int, int>> st;

        dist[src] = 0;
        st.insert({0, src});
        int reachableCities = 0;

        while (!st.empty()) {
            auto top = *st.begin();
            st.erase(st.begin());

            int nodeDist = top.first;
            int node = top.second;

            if (node != src && nodeDist <= distanceThreshold) {
                reachableCities++;
            }

            for (auto nbr : adjList[node]) {
                int currDist = nodeDist + nbr.second;
                if (currDist < dist[nbr.first]) {
                    auto it = st.find({dist[nbr.first], nbr.first});
                    if (it != st.end()) {
                        st.erase(it);
                    }
                    dist[nbr.first] = currDist;
                    st.insert({dist[nbr.first], nbr.first});
                }
            }
        }
        return reachableCities;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, list<pair<int, int>>> adjList;

        // Create adjacency list
        for (auto edge : edges) {
            int u = edge[0];  
            int v = edge[1];  
            int wt = edge[2];

            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        int city = 0;
        int minReachableCities = INT_MAX;

        for (int u = 0; u < n; u++) {
            int reachableCitiesCount = Dijkstra(u, n, adjList, distanceThreshold);
            if (reachableCitiesCount <= minReachableCities) {
                minReachableCities = reachableCitiesCount;
                city = u;
            }
        }
        return city;
    }
};
