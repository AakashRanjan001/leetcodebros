class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n,0);

        for(auto &vec : roads){
            int u = vec[0];   //idhr se nikla
            int v = vec[1];   // idhr aake end hua

            degree[u]++;
            degree[v]++;
        }

        sort(begin(degree), end(degree));

        long long value = 1; // jiska jitna jada degree utni jada value assign krege i.e "n"

        long long sum = 0;

        for(int i =0; i<n; i++){
            sum += degree[i]*value;
            value++;                // vertices value to badhate jaenge 1,2,3,4...
        }
        return sum;
    }
};
