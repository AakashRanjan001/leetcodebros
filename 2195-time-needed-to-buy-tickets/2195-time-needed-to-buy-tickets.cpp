class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int total = 0;
        int num = tickets[k];
        //time of [0,k]
        for (int i = 0; i <= k; i++) {
            total += min(num, tickets[i]);
        }
        //time of (k, n) where final pass stops early
        for (int i = k + 1; i < tickets.size(); i++) {
            total += min(num - 1, tickets[i]);
        }
        return total;
    }
};
