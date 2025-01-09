class Solution {
public:
    bool hasMatch(string s, string p) {
        
        string pref = "";
        string suff = "";
        int n = p.size();
        int star_pos ;
        for(int i=0;i<n;i++){
            if(p[i] =='*'){
              star_pos = i;
            }
        }
            pref = p.substr(0,star_pos);
            suff = p.substr(star_pos+1);
        
        auto t = s.find(pref);
        if(t==-1)return false;
        else{
            //agar pref mil gya toh baaki bache hue string mei meko dekhna padega
            s = s.substr(t + pref.size());
              if(s.find(suff)!=string::npos){
             return true;
        }
      }
      
        return false;
      
    }
};