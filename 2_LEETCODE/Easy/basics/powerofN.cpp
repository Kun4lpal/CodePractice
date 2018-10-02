

bool isPowerOfThree(int n) {
    return n>0 && (n==1 || (n%3==0 && isPowerOfThree(n/3)));
}


class Solution {
public:
    bool isPowerOfTwo(int n) {
        //if(n==0) return false;
        if(n>1) {while(n%2==0){ n = n/2;}}
        return n==1;
    }
};


bool isPowerOfFour(int num) {
        if(num>0){
        while(num%4==0){
            num = num/4;
        }
        }
        return num==1;
    }


bool isPowerOfFour(int num) {
        while(num>0){
            if(num==1) return true;
            if((num&3)!=0) return false;
            num=num>>2;
        }
        return false;
}