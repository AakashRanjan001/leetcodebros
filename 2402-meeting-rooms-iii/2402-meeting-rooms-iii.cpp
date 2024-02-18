
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long long> room(n, 0); // finish time of each room
        vector<int> count(n, 0); // held meeting numbers of each room
        for(auto &meeting: meetings) {
            long long Min = 1e15; // keep current earliest finish time
            int index = -1; // earliest finish room
            bool empty = false; // true -> has available room
            for(int i = 0; i < n; i++) {
                if(room[i] <= meeting[0]) { // find available room
                    index = i;
                    empty = true;
                    break;
                }
                if(room[i] < Min) { // update earliest finish time and room
                    Min = room[i], index = i;
                }
            }
            if(empty) room[index] = meeting[1]; // just use room[index]
            else { // reserve room[index] at time [state_time + Min, finish_time + Min)
                Min += meeting[1] - meeting[0]; // current meeting finish time
                room[index] = Min;
            }
            count[index]++;
        }
        int Max = 0, res = -1;
        for(int i = 0; i < n; i++) { // just to find the maximum of count
            if(count[i] > Max) {
                Max = count[i], res = i;
            }
        }
        return res;
    }
};