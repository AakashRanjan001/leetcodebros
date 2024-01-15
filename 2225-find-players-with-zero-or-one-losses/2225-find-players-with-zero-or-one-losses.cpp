class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int,int>wincount;
        map<int,int>losscount;
        
        for(int i=0;i<matches.size();i++){
            
            wincount[matches[i][0]]++;
            losscount[matches[i][1]]++;
        }
        vector<int>noloss;;
        vector<int>oneloss;
        
        for(auto it1:losscount){
            if(it1.second==1){
                oneloss.push_back(it1.first);
                
            }
        }
        for(auto it2:wincount){
            if(losscount.find(it2.first)==losscount.end()){
                noloss.push_back(it2.first);
               
            }
        }
        return {noloss,oneloss};
        
    }
};