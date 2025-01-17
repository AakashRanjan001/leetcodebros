class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int cnt =0;  // general observation by running many test cases 
        for(int i=0;i<derived.size();i++){
            if(derived[i] == 1){
                 cnt++;
            }
        }
        if(cnt%2 ==0)return true;
        return false;
    }
};