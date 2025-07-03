// class Solution {
// public:
//    bool canplaceBalls(vector<int>& position,int dist,int m){
//       int cntballs = 1;
//       int lastplaceball = position[0];
//       for(int i=1;i<position.size();i++){
//          if(position[i] - lastplaceball >=dist){
//              cntballs++;
//              lastplaceball = position[i];
//          }
//       }
//       if(cntballs>=m)return true;
//       return false;
//    }
//   // AGGRESSIVE COWS wla question
//     int maxDistance(vector<int>& position, int m) {
//         int n = position.size();
//         sort(position.begin(),position.end());
//         int maxDistPossible = position[n-1]-position[0];
//         for(int i=1;i<=maxDistPossible;i++){
//              if(canplaceBalls(position,i,m) == true){
//                  continue;
//              }
//              else{
//                  return i-1;
//              }
//         }
//         return 0;
//     }
// };
class Solution {
public:
       bool canplaceBalls(vector<int>& position,int dist,int m){
      int cntballs = 1;
      int lastplaceball = position[0];
      for(int i=1;i<position.size();i++){
         if(position[i] - lastplaceball >=dist){
             cntballs++;
             lastplaceball = position[i];
         }
      }
      if(cntballs>=m)return true;
      return false;
   }
    int maxDistance(vector<int>& position, int m) {

         int n = position.size();
        sort(position.begin(),position.end());
        int maxDistPossible = position[n-1]-position[0];

        int low = 1;
        int high = maxDistPossible;
        int ans = -1;
        while(low<=high){
             int mid = low+(high-low)/2;

             if(canplaceBalls(position,mid,m)== true){
                 ans = mid;
                 low= mid+1;
             }
             else{
                 high = mid-1;
             }
        }
        return ans;
    }
};