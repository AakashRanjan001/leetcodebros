class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //sliding windpw ka ek interseting quetsion 
        int i=0;
        int j=0;
        int maxi = 0;
        map<int,int>mp;

        while(j<fruits.size()){
             mp[fruits[j]]++;

             while(mp.size()>2){
                 mp[fruits[i]]--;
                  if(mp[fruits[i]] == 0){
                     mp.erase(fruits[i]);
                  }
                  i++;
             }
             maxi = max(maxi,j-i+1);
             j++;
        }
        return maxi;
    }
};