#include <iostream>
#include <vector>
#include <map>


int main() {

	int N;
	unsigned long totalCount = 0;
	std::vector<int> A;

	std::map<int, int> B;
	std::map<int, std::pair<unsigned long, unsigned long>> C;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int c;
		std::cin >> c;
		A.push_back(c);

		// [] Creates 0 if not exist
		B[c] += 1;
	}

	for (auto const& x: B) {
		unsigned long valueCount = (unsigned long) x.second;
		unsigned long firstValue = 0; 
		unsigned long secondValue = 0;

		if (valueCount >= 2) {
			unsigned long buffer = 1;
			for (unsigned long j = valueCount; j > valueCount - 2; j--) {
				buffer *= j;
			}

			firstValue = buffer / 2;
			secondValue = buffer * (valueCount - 2) / (valueCount * 2) ;
		}
		totalCount += firstValue;

		C.insert({x.first, {firstValue, secondValue}});
	}

	for (int i = 0; i < N; i++) {

		std::map<int, std::pair<unsigned long, unsigned long>>::iterator it;

		it = C.find(A[i]);

		std::cout << totalCount - it->second.first + it->second.second << "\n";
	}

	return 0;

}

