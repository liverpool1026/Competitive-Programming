#include <map>
#include <iostream>


// My Solution
int main() {
	std::map<int, int> sequence;
	int a[] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
	for (int i=0; i < 32; i++) {
		sequence.insert({i+1, a[i]});
	}

	int k;
	std::cin >> k;

	std::cout << sequence[k];
}

// Better Solution
int main() {
	int k;
	std::cin >> k;

	int a[] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

	cout << a[k-1];

	return 0;
}


// Note:
// There is no need to insert into a map. The indexing is faster than map search O(1) : O(nlogn)

