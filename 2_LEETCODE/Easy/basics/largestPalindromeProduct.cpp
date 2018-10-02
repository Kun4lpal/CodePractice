// Find the largest palindrome made from the product of two n-digit numbers.

// Since the result could be very large, you should return the largest palindrome mod 1337.

// Example:

// Input: 2

// Output: 987

// Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

// Note:

// The range of n is [1,8].



long long buildPal(int n){
        string s=to_string(n);
        reverse(s.begin(),s.end());
        return stoll(to_string(n)+s);
}
    
int largestPalindrome(int n) {
        if(n==1)
            return 9;
        int low=pow(10,n-1),high=pow(10,n);
        for(int i=high-1;i>=low;i--){
            long long tp=buildPal(i);
            for(long long j=high-1;j*j>=tp;j--){
                if(tp%j==0 && tp/j<high){
                    return tp%1337;
                }
            }
        }
        
    }