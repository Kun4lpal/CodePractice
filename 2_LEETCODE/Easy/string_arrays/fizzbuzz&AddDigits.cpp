vector<string> fizzBuzz(int n) {
        vector<string> res;

        for(int i=1;i<=n;i++){
            string str = "";
            if(i%3==0){str.append("Fizz");}
            if(i%5==0) {str.append("Buzz");}
            else if(str == "") {str.append(to_string(i));}
            res.push_back(str);
        }
        return res;
    }


Given a non-negative integer num, repeatedly add all its digits until the result has only one digit. 

int addDigits(int num) {
        int nums = num;
        while(nums>9){
            int a = nums%10;
            int b = nums/10;
            while(b){
                a += b%10;
                b = b/10;
            }
            nums = a;
        }
        return nums;
    }