// class info{
//      public:
//       int data;
//       int index;

//    info(int d , int i){
//        data = d;
//        index =i;
//    }
// };
// class compare{
//     public:
//       bool operator()(int a , int b){
//          return a>b;
//       }
// };
// class Solution {
// public:
//     long long findScore(vector<int>& nums) {
//         int n = nums.size();
//         vector<bool>marked(1e6 +10,false);
//         priority_queue<info* , vector<info*>,compare>MinHeap;
        
//         for(int i=0;i<n;i++){
//              info* val = new info(nums[i],i);
//              MinHeap.push(val);
//         }
//         long long res =0;
//         while(!MinHeap.empty()){
//             info* temp =  MinHeap.top();
//             MinHeap.pop();
//             if(!marked[temp->index]){
//                     res+=temp->data;
//                     marked[temp->index] = true;
//                     int prev = temp->index -1 ;
//                     int next = temp->index +1;

//                     if(prev>=0){
//                         marked[prev] = true;
//                     }
//                     if(next<nums.size()){
//                         marked[next] = true;
//                     }

//             }
//         }
// return res;

//     }
// };




// class info {
// public:
//     int data;
//     int index;

//     info(int d, int i) {
//         data = d;
//         index = i;
//     }
// };

// class compare {
// public:
//     bool operator()(info* a, info* b) {
//         return a->data > b->data; // Min-heap: prioritize smaller `data`
//     }
// };

// class Solution {
// public:
//     long long findScore(vector<int>& nums) {
//         int n = nums.size();
//         vector<bool> marked(n, false); // Track processed indices
//         priority_queue<info*, vector<info*>, compare> MinHeap;

//         // Populate the priority queue
//         for (int i = 0; i < n; i++) {
//             MinHeap.push(new info(nums[i], i));
//         }

//         long long res = 0;
//         while (!MinHeap.empty()) {
//             info* temp = MinHeap.top();
//             MinHeap.pop();

//             // Process only if the current index is not marked
//             if (!marked[temp->index]) {
//                 res += temp->data;
//                 marked[temp->index] = true;

//                 // Mark adjacent indices
//                 if (temp->index - 1 >= 0) {
//                     marked[temp->index - 1] = true;
//                 }
//                 if (temp->index + 1 < n) {
//                     marked[temp->index + 1] = true;
//                 }
//             }

//             delete temp; // Free memory
//         }

//         return res;
//     }
// };
class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<bool> marked(1e6 + 10, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        long long res = 0;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            if (!marked[p.second]) {
                res += p.first;
                marked[p.second] = true;
                int prev = p.second - 1, next = p.second + 1;
                if (prev >= 0) {
                    marked[prev] = true;
                }
                if (next < nums.size()) {
                    marked[next] = true;
                }
            }
        }

        return res;
    }
};