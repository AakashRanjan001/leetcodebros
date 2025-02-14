class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

    priority_queue <long long int, vector<long long int>, greater<long long int>> pq;

    for(auto i : nums)
    {
        pq.push(i);
    }        

    int count = 0;
    while( pq.top() < k )
    {
        long long int p1 = pq.top();
        pq.pop();
        long long int p2 = pq.top();
        pq.pop();

        pq.push( min(p1, p2) * 2 + max(p1, p2) );
        count++;
    }
    return count;

    }
};
