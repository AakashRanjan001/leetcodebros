class Solution {
public:
    int divisorSubstrings(int num, int k) {
        // string temp = to_string(num);
        // int oper = 0;
        // string var ="";
        // for(int i=0;i<temp.size();i++){
        //     var = "";
        //     for(int j=i;j<i+k;j++){
        //          var+=temp[j];
        //     }
        //     int val = stoi(var);
        //     if(val!=0 && num%val == 0){
        //          oper++;
        //     }
          
        // }
        // return oper; 

        string temp = to_string(num);
        int oper =0;
        for(int i=0;i<=temp.size() - k;i++){
             string var = temp.substr(i,k);
             int val = stoi(var);

             if(val!=0 && num % val == 0){
                 oper++;
             }
        }
        return oper;
    }
};