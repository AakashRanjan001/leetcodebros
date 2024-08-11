class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int row =0;
        int col =0;

        for(int i=0;i<commands.size();i++){
            if(commands[i] == "UP"){
                 if(row>0){
                     row--;
                 }
            }
            else if(commands[i]== "DOWN"){
                if(row<n-1){
                    row++;
                }
            }
            else if(commands[i]=="LEFT"){
                if(col>0){
                    col--;
                }
            }
            else if(commands[i]=="RIGHT"){
                if(col<n-1){
                    col++;
                }
            }
        }
        return (row*n )+ col;
    }
};