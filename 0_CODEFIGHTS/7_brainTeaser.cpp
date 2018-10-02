//
//f and g function is sum of all f
int productExceptSelf(std::vector<int> nums, int m) {
    int sum=0;
    int product =1;
    for(int i=0;i<nums.size();i++){
        sum = (nums[i]*sum + product)%m;
        product = (product*nums[i])%m;
    }
    return sum;
}

//
static bool optimalChange(long s, Change &c) {
	c.coin2 = 0;
	c.bill5 = 0;
	c.bill10 = 0;

	int numberOfTen = s / 10;
	for (int tens = s / 10; tens >= 0; tens--) {
		int numberOfFive = (s - (tens * 10)) / 5; // as tens have already been counted
		for (int fives = numberOfFive; fives >= 0; fives--) {

			int numberOfTwo = (s - (tens * 10) - (fives * 5)) / 2; // as tens and fives have already been counted
			for (int twos = numberOfTwo; twos > 0; twos--) {
				if ((2 * twos + 5 * fives + 10 * tens) == s) {
					c.coin2 = twos;
					c.bill5 = fives;
					c.bill10 = tens;
					return true;

				}
			}
		}
	}
	return false;
}