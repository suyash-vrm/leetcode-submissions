class Solution {
public:
    bool checkDivisibility(int n) {
        int add = 0;
        int mult = 1;
        int num = n;
        while(num !=0){
            add += num%10;
            mult *= num%10;
            num = num/10;
        }

        if(n % (add + mult) == 0){
            return true;
        }else{
            return false;
        }
        
    }
};