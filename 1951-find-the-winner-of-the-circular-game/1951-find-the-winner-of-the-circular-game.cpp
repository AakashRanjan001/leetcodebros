class Solution {
public:
    int findTheWinner(int n, int k) {
        
        vector<int>friends(n);
        for(int i=0;i<n;i++){
            friends[i] = i+1;
        }
        int index =0;
        while(n>1){
           index = (index+k-1)%n;
           friends.erase(friends.begin() + index);
           n--;
        }
        return friends[0];
    }
};