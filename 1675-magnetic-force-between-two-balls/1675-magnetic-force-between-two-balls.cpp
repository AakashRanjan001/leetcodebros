class Solution {


public:
    int maxDistance(vector<int>& position, int m) {

        int n= position.size();

        

        sort(position.begin(), position.end());

        

       int maxel= position[n-1]-position[0];
       int minel=0;

       int ans=0;

       while(minel<=maxel){
        int curr= (minel+maxel)/2;

        int cnt=1;
        int last= position[0];
        bool chk=false;
        for(int i=1;i<n;i++){
                if(position[i]-last>= curr){
                    cnt++;
                    last=position[i];
                }
                if(cnt>=m){
                    chk=true;
                    break;
                }
        }

        if(chk){
            minel=curr+1;
        }
        else maxel=curr-1;

       }

       return maxel;

       
    }
};
