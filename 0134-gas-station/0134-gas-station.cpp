class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int deficit =0;
        //petrol kitna kam pad gya ki aage nhi badh apaaye
        int balance =0;
        //extra petrol we have 
        int start =0;
        //we started from 0th index for checkung the circular route 

        for(int i=0;i<gas.size();i++){

            balance = gas[i]-cost[i]+balance; //extra petrol kitna bacha 
            if(balance<0){//matlab aage nhi badh paayenge 

            //maine deficit = balance kiya tha dhyan dena yaha par 2nd test case ko dekhna samjh aa kayega 
              deficit += abs(balance);//jo balance hoga utna hi deficit hoga -ve mei
              start = i+1;//so aage wale index se check akrenge 
              balance =0;//wapsa se balance ko 0 kar denge 

            }
        }
        if(balance>=deficit){
            return start; // janb pura execute ho gya tab check kiye ki balance kitna hai aur bada hai hence circle complete ho jayega 
        }else{
            return -1;
        }
    
    }
};