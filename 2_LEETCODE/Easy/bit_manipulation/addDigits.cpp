// get the sum of 2 digits


// 101
// 010

// 111
// 01

int getSum(int a, int b) {
        int sum =a;
        while(b!=0){
            sum = a^b;
            b = (a&b)<<1;
            a = sum;
        }
        return sum;
}