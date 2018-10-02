// You are climbing a stair case. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 


int climbStairs(int n) {
    int a = 1, b = 1;
    while (n--)
        a = (b += a) - a;
    return a;
}


int climb(int n){
	vector<int> vec(n+1);
	vec[0]=0;
	vec[1]=1;
	vec[2]=2;
	for(int i=3;vec.size();i++){
		vec[i] = vec[i-1] + vec[i-2];
	}
	return vec[n];
}