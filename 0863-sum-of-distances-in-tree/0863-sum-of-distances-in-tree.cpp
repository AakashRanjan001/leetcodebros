class Solution {
public:
    vector<int> cn;

    int fun1(int node, int par, vector<vector<int>>& vp) {
        int c = 0;
        for (auto it : vp[node]) {
            if (it != par) {
                c += fun1(it, node, vp);
            }
        }
        cn[node] = c;
        return cn[node]+1;
    }

    int fun2(int node, int par, vector<vector<int>>& vp) {
        int c = 0;
        for (auto it : vp[node]) {
            if (it != par) {
                c += fun2(it, node, vp);
            }
        }
        c += cn[node];
        return c;
    }

    void fun3(int node, int par, vector<vector<int>>& vp, vector<int>& ans, int n) {
        ans[node] = (ans[par] + n - 2 - cn[node]-cn[node]);
        for (auto it : vp[node]) {
            if (it != par) {
                fun3(it, node, vp, ans, n);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n, 0);
        cn.resize(n);
        vector<vector<int>> vp(n);

        for (int i = 0; i < edges.size(); i++) {
            vp[edges[i][0]].push_back(edges[i][1]);
            vp[edges[i][1]].push_back(edges[i][0]);
        }

        fun1(0, -1, vp);
        int c = fun2(0, -1, vp);
        ans[0] = c;

        for (auto it : vp[0]) {
            fun3(it, 0, vp, ans, n);
        }

        return ans;
    }
};
