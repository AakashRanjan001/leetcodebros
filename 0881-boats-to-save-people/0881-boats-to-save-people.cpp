class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
         int n = people.size();
         sort(people.rbegin(),people.rend());
         int i=0,j = n-1;
         int boat =0;
         while(i<=j){
             if(people[i]+ people[j]<=limit){
                 boat+=1;
                 i++;
                 j--;
             }else if(people[i] == limit || people[i] + people[j]>limit) {
                 boat+=1;
                 i++;
             }else if(people[j] == limit){
                 boat+=1;
                 j--;
             }
         }
         return boat;
    }
};