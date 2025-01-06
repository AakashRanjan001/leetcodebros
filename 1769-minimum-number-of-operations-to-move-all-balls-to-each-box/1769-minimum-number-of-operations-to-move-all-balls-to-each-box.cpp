class Solution {
public:
    vector<int> minOperations(string boxes) {
        // hame harr ke index mei jo 1 hai yusko harr ek index mei laana hai 
        // kinda prefix si=um 

        // first i will calculate all the ones in the string 
        int n = boxes.size();
        vector<int>ones;
        for(int i=0;i<n;i++){
             if(boxes[i] == '1'){
                 ones.push_back(i);
             }
        }
        vector<int>res(n);
  
        for(int i=0;i<n;i++){
                   int cnt =0;
            for(int j=0;j<ones.size();j++){
                 cnt+=abs(i - ones[j]);
            }
            res[i] = cnt;
        }
        return res;
    }
};