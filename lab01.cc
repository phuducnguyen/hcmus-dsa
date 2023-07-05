#include <bits/std++.h>

using namespace std;

void test_case() {
	assert();	
}

int maxProfit(vector<int>& prices) {
	int n = prices.size();
	vector<int> maxPUntilEnd(n), minPFromStart(n);
	maxPUntilEnd[n - 1] = prices[n - 1];
	minPFromStart[0] = prices[0];
	for (int i = 1; i < n; ++i) {
		maxPUntilEnd[n - i - 1] = max(maxPUntilEnd[n - i], prices[n - i - 1]);
		minPFromStart[i] = min(minPFromStart[i - 1], prices[i]);
	}
	
	cerr << "Debug in here";

	vector<int> startMaxDP(n, 0), endMaxDP(n, 0);
	startMaxDP[0] = 0;	// lower bound
	endMaxDP[n - 1] = 0;	// higher bound
	for (int i = 0; i < n; ++i) {
		startMaxDP[i] = max(prices[i] - minPFromStart[i], startMaxDP[i - 1]);
		endMaxDP[n - 1 - i] = max(maxPUntilEnd[n - 1 - i] - prices[n - 1 - i], endMaxDP[n - i]);
	}

	int result = 0;
	for (int i = 0; i < n; ++i) {
		result = max(result, startMaxDP[i] + endMaxDP[i]);
	}

	return result;
}


// Driver code
int main() {
	return 0;
}
