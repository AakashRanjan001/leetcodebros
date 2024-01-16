class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
             int a=0;
        while(a<mat.size()*2)
        {
            if(equal(mat.begin(),mat.end(),target.begin()))
        {
            return true;
        }
        else
        {

        int n=mat.size();
            
        reverse(mat.begin(),mat.end());
            
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                swap(mat[i][j],mat[j][i]);
            }
        }
        a++;
        }
        }
        return false;
    }
};