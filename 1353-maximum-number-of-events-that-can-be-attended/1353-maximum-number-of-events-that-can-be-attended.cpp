// class Solution {
// public: 
                     // MY WRONG APPROACH WHICH WAS ONLY GREEDY
//    static bool cmp(vector<int>& a, vector<int>& b){
//          if(a[0] == b[0])return a[1]<b[1];
//          else return a[0]<b[0];
//     }
//     int maxEvents(vector<vector<int>>& events) {
//          int n = events.size();
//          sort(events.begin(),events.end(),cmp);
         

//          int initialstart = events[0][0];
//          int initialend = events[0][1];
//          int cnt =1;

//          for(int i=1;i<n;i++){
//              int start = events[i][0];
//              int end = events[i][1];
//              if(start>=initialend){
//                  cnt++;
//                  initialend = end;
//              }
//              else if(start == initialstart && end == initialend){
//                  cnt++;
//              }

//          }
//          return cnt;
         
//     }
// };

// ONE CORRECT SOLUTION BUT GAVE ME TLE
// class Solution {
// public:
//     static bool cmp(const vector<int>& a, const vector<int>& b) {
//         if (a[1] == b[1]) return a[0] < b[0];
//         return a[1] < b[1];
//     }

//     int maxEvents(vector<vector<int>>& events) {
//         sort(events.begin(), events.end(), cmp);

//         set<int> usedDays;
//         int maxDay = 0;
//         for (auto& e : events) {
//             maxDay = max(maxDay, e[1]);
//         }

//         vector<bool> attended(maxDay + 2, false);
//         int cnt = 0;

//         for (auto& e : events) {
//             for (int d = e[0]; d <= e[1]; d++) {
//                 if (!attended[d]) {
//                     attended[d] = true;
//                     cnt++;
//                     break;
//                 }
//             }
//         }
//         return cnt;
//     }
// };
class Solution {
public:
   static bool cmp(vector<int>&a ,vector<int>& b){
         if(a[0] == b[0]) return a[1] < b[1];
         return a[0] < b[0];
    }

    int maxEvents(vector<vector<int>>& events) {
         int n = events.size();
         sort(events.begin(), events.end(), cmp);
         
         int day = 1;
         priority_queue<int, vector<int>, greater<int>> pq;
         int cnt = 0;
         int i = 0;

         while (!pq.empty() || i < n) {
              if (pq.empty() && i < n) {
                  day = max(day, events[i][0]);
              }

              while (i < n && events[i][0] == day) {
                   pq.push(events[i][1]);
                   i++;
              }

              while (!pq.empty() && pq.top() < day) {
                  pq.pop(); // remove expired events
              }

              if (!pq.empty()) {
                  pq.pop(); // attend one event
                  cnt++;
              }

              day++;
         }

         return cnt;
    }
};
