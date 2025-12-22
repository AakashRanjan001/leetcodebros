class Solution {
public:
    int mirrorDistance(int n) {
         string temp = to_string(n);
         reverse(temp.begin(),temp.end());

         int a = stoi(temp);
         return abs(n - a);
    }
};