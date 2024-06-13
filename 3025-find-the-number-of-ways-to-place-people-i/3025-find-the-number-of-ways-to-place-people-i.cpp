class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans =0;

        for(int i=0;i<n;i++){  //c point le liya 
            int cx = points[i][0] ,cy = points[i][1];
            for(int j=0;j<n;j++){ // t ka point le liya 
                int tx = points[j][0] , ty = points[j][1];
                if(i==j || cx>tx || ty>cy)continue; //means valid pais nhi hia dono
                   
                   bool flag = true; //ki teesra point lie nhi kareg abeech mei ya perimeter mei 
                for(int k=0;k<n;k++){
                    if(k==i || k== j)continue; //inn dono points ke lawa check karna hai
                    if(points[k][0]>=cx && points[k][0]<=tx  &&  points[k][1]<=cy && points[k][1]>=ty)
                        flag = false; //matlab andar lie kar rha hai kx and ky
             
                }
                if(flag==true)ans++;
            
            }
        

        }
        return ans;
    }
};