class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        //  int n = c.size();
        //  int ini_x = c[0][0];
        //  int ini_y = c[0][1];

        //  int x = c[1][0];
        //  int y = c[1][1];
        // int ini_slope = (y - ini_y)/(x - ini_x);

        //  for(int i=2;i<n;i++){
        //       int new_x = c[i][0];
        //       int new_y = c[i][1];

        //       int new_slope = (new_y - ini_y)/(new_x - ini_x);
        //       if(new_slope !=ini_slope){
        //         return false;
        //       }
              
        //  }
        //  return true;

        int n = c.size();
        int dx_i = c[1][0] - c[0][0];
        int dy_i = c[1][1] - c[0][1];

        for(int i=2;i<n;i++){
             int dx = c[i][0] - c[0][0];
             int dy = c[i][1] - c[0][1];

             if(dy_i* dx !=dx_i* dy)return false;
        }
        return true;
    }
};