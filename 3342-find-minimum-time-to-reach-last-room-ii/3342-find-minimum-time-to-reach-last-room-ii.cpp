class Solution {
public:
    vector<vector<int>>dir{{1,0} , {-1,0} ,{0,1} ,{0,-1}};

     // priority queue mei kya stire karte the 
      //{ t , {i,j}};
      typedef pair<int , pair<int , int>>P;

    int minTimeToReach(vector<vector<int>>& moveTime) {
        
        int m = moveTime.size();
        int n = moveTime[0].size();

        vector<vector<int>>res(m, vector<int>(n , INT_MAX));
        priority_queue<P, vector<P>, greater<P>>pq;

        res[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
             int currTime = pq.top().first;
              auto cell = pq.top().second;

             int i = cell.first;
             int j = cell.second;

             pq.pop();

             if( i == m-1 && j == n-1){
                 return currTime;  // if you have reachef the location 
             }
            for(auto &dirr : dir){
                 int i_ = i+ dirr[0];
                 int j_ = j+ dirr[1];

                 // naya cell mil gya 
                 if(i_ >=0 && i_<m && j_ >=0 && j_< n){

                     int MoveCost = (i_+j_);  // finding the ManhaTTan Distance 
                     if(MoveCost%2 ==0)MoveCost = 2;
                     else MoveCost = 1;

                     int wait = max(moveTime[i_][j_] - currTime, 0 );
                     int arrivalTime = currTime + wait + MoveCost;

                     if(res[i_][j_] > arrivalTime){
                         res[i_][j_] = arrivalTime;
                         pq.push({arrivalTime , {i_, j_}});
                     }

                 }
            }

        }
        return -1;
    }
};