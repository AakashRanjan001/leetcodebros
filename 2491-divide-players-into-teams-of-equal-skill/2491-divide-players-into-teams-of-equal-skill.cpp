class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long n = skill.size();
        long long i=0;
        long long j =n-1;
        long long sum =0;
        while(i<j){
            long long num = skill[i]+skill[j];
          if(skill[i+1] +skill[j-1]!=num){
             return -1;
    
          }
          else{
            
            
           sum += skill[i]*skill[j];
           i++;
           j--;
          }

        } 
        return sum;
    }
};