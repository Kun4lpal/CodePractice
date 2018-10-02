//array is sorted

vector<int> twoSum(vector<int>& numbers, int target) {
        int m = numbers.size()-1;
	vector<int> res;
	int i = 0;
	while (i < numbers.size())
	{
		if (numbers[i] + numbers[m] < target)
		{
			i++;
		}
		else if (numbers[i] + numbers[m] > target)
		{
			m--;
		}
		else
		{
			res.push_back(i+1);
			res.push_back(m+1);
			return res;
		}
	}
	return res;        
}