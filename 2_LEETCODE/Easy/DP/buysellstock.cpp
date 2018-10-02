// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one 
// and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the 
// same time (ie, you must sell the stock before you buy again)

int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) return 0;
    int total = 0;
	for (int i = 0; i<prices.size() - 1; i++) {
		if (prices[i + 1]>prices[i]) { total += prices[i + 1] - prices[i]; }
	}
	return total;
}


// Say you have an array for which the ith element is the price of a given stock on day i.
// If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
// design an algorithm to find the maximum profit.


int maxProfit(vector<int>& prices) {
         int maxPro = 0;
    int minPrice = INT_MAX;
    for(int i = 0; i < prices.size(); i++){
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }
    return maxPro;
}