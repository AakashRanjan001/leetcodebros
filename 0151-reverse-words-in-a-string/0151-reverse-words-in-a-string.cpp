class Solution {
public:
    string reverseWords(string s) {
        // int n = s.size();
        // // tareek 1 : using string stream which is used in tokenisation 
        // stringstream ss(s);
        // string tokenstored = "";
        // string res = "";

        // while(ss>>tokenstored){
        //      res = tokenstored + ' ' + res;
        // }
        // return res.substr(0,res.size()-1);

        //tareeka 2 : using two pinter 
        // i pointer check karega ki aage space hai ya character 
        // l and r pointer jab ek word milevga tab apon uss word ko reverse karenge 
    
     int n = s.size();
     int i=0;
    reverse(s.begin(),s.end());
     int l =0,r=0;

     while(i<n){
         while(i<n && s[i]!=' '){
             s[r] = s[i];
             r++;
             i++;
         }
        if(l<r){
         reverse(s.begin()+l, s.begin()+r);

         s[r] = ' ';
         r++;
         l = r;
     }
      i++;

     }
     return s.substr(0,r-1);

    }
};