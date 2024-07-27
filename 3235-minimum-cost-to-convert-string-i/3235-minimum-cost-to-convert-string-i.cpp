
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int, int>>> adj(26, vector<pair<int, int>>());
        for(int i=0; i<cost.size(); i++){
            adj[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }
        vector<vector<long long>> dis(26, vector<long long>(26, 10000000));
        for(int i=0; i<26; i++){
            dis[i][i] = 0;
            priority_queue<pair<int,int>, vector<pair<int, int>>,greater<pair<int,int>>> pq;
            pq.push({0,i});
            while(!pq.empty()){
                int a = pq.top().first;
                int b = pq.top().second;
                pq.pop();
                for(auto c: adj[b]){
                    int d = c.first;
                    int e = c.second;
                    if(a + e < dis[i][d]){
                        dis[i][d] = a + e;
                        pq.push({a+e, d});
                    }
                }
            }
        }
        int m = source.size();
        long long ans = 0;
        for(int i=0; i<m; i++){
            long long val = dis[source[i]-'a'][target[i]-'a'];
            if(source[i] != target[i]){
                if(val == 10000000) return -1;
                ans += dis[source[i]-'a'][target[i]-'a'];
            }
        }
        return ans;
    }
};