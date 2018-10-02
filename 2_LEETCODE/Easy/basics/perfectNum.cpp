// We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.
// Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not. 

bool checkPerfectNumber(int num) {
        int sum = 1;
    for (int i=2;i<pow(num,0.5);i++) 
        if (num % i == 0) sum += i + (num/i == i ? 0 : num/i);
    return num != 1 && sum == num;
  }