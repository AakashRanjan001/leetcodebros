class Solution {
public:
    int compareVersion(string version1, string version2) {
        
       int n1 = version1.size();
       int n2 = version2.size();

       int i=0;int j=0;
       while(i<n1 ||j<n2){
       int val1=0;int val2=0;
       while(i<n1 && version1[i]!='.'){
            val1 = val1*10 + (version1[i]-'0'); 
            i++;
       }
       i++;
       while(j<n2 && version2[j]!='.'){
        val2 = val2*10 + (version2[j]-'0');
        j++;
       }
       j++;

       if(val1<val2)return -1;
       else if(val1>val2)return 1;
       
       }
       return 0;

    }
};