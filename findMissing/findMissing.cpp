#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

typedef unsigned int uint;


int find_missing(const std::vector<int>& bigger, const std::vector<int>& smaller) {
	uint h1 = 0, h2 = 0;
	int sum = 0;
	while (h1 < bigger.size() && h2 < smaller.size()) {
		if (sum < 0) {
			sum += bigger[h1];
			h1++;
		}
		else {
			sum -= smaller[h2];
			h2++;
		}
	}
	while (h1 < bigger.size()) {
		sum += bigger[h1];
		h1++;
	}
	while (h2 < smaller.size()) {
		sum -= bigger[h2];
		h2++;
	}
	return sum;
}
int main() {
	std::cout << "Missing: " << find_missing({ INT_MAX, INT_MAX - 5, 12, 6, 8 }, { 6, 8, INT_MAX, INT_MAX - 5 }) << "\n"; // 12 should be missing
}
