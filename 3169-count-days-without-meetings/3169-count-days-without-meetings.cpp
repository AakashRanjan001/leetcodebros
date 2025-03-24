typedef long long ll;
class Solution {
public:
//    static bool comp(vector<int> &a , vector<int>&b){
//          return a[0]<b[0];
//     }
    int countDays(int days, vector<vector<int>>& meetings) {
        
        //  int n = meetings.size();
        //  sort(meetings.begin(),meetings.end(),comp);
        //  int cnt =0;
        //  for(auto &i:meetings){
        //      int start = i[0];
        //      int end = i[1];

        //      cnt+=(end-start+1);
        //  }
        //  return abs(days - cnt);

        ll n = meetings.size();
        set<ll>st;

        for(auto &i:meetings){
             int start = i[0];
             int end = i[1];

             while(start<=end){
                 st.insert(start);
                 start++;
             }
        }

    return (days - st.size());

    }
};