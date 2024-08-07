
class Solution {

    string ones[10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"} ;
    string teens[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" } ;
    string tys[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"} ;
    string keys[3] = {" Billion ", " Million ", " Thousand " } ;

    string one_to_hubdred(int num){
        if(num >= 10 && num <= 19){
            return teens[num-10] ;
        }

        string result = "" ;

        int num_ten = num / 10 ;
        
        int num_one = num % 10 ;

        result = tys[num_ten] ; 

        if(num_ten && num_one)
            result+= " " ;

        result+= ones[num_one] ;

        return result ; 
    }

    string one_to_thousand(int num){
        string result = "" ;
        int sum_hundred = num / 100 ;
        int sum_rest = num % 100 ;
        
        if(sum_hundred)
            result += one_to_hubdred(sum_hundred) + " Hundred" ;
        if(sum_hundred && sum_rest)
            result +=" " ;
        if(sum_rest)
            result += one_to_hubdred(sum_rest)  ;
        return result ;
    }
public:
    string numberToWords(int num) {
        if(num == 0)
            return "Zero" ;
        int count = 0 ;
        string result = "" ;

        int key = 1000000000 ;
        int index = 0 ;

        while(num >= 1000){
            if(num >= key){
                int count = num / key ;
                result += one_to_thousand(count) + keys[index] ;
                num-= (count * key) ;
            }
            key /= 1000 ;
            index++;
        }

        if(num)
            result+= one_to_thousand(num) ;
        
        if(result[result.length()-1] == ' ')
            result.pop_back() ;
       
        return result ; 
    }
};