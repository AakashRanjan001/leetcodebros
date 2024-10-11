
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
           
            vector<pair<vector<int>,int>>v;
            int l=0;

            for(auto it : times){
                 
                 v.push_back({it,l});
                 l++;
            }

            sort(v.begin(),v.end());


            vector<int>chair(10000,-1);
            
            vector<int>arr = v[0].first;
            int a = arr[0];
            int d = arr[1];
            int t = v[0].second;
            chair[0] = d;

            if(t == targetFriend){
                return 0;
            }


            for(int i=1;i<v.size();i++){

                    vector<int>arr = v[i].first;
                     int a = arr[0];
                     int d = arr[1];
                     int t = v[i].second;
                    

                     for(int j=0;j<10000;j++){
                          
                           if(a >= chair[j] ){
                               chair[j] = d;
                               if(t == targetFriend){
                                return j;
                               }

                               break;
                              
                           }
                     }

                
            }



        

            return -1;
    }
};