#include <iostream>
#include <map>


// 0: No Change
// 1: Inverse
// 2: Swap
// 3: Swap + Inverse
int identifyChange(std::pair<int, int> same, std::pair<int, int> different, std::pair<int, int> changedDifferent) {
	if (different.first == changedDifferent.first && different.second == changedDifferent.second) {
		return 0;
	} else if (different.first == changedDifferent.second && different.second == changedDifferent.first) {
		return 1;
	} else if (changedDifferent.first == same.first && changedDifferent.second == same.second) {
		return 2;
	} else {
		return 3;
	}
}

void applyChange(std::map<int, int>& bits, int N, int changeType, int index) {
	switch(changeType) {
		case 1:
			for (auto& x : bits) {
				x.second = !x.second;
			}
			break;
		case 2:
			for (int i = 1; i < index + 1; i++) {
				int buffer = bits[i];
				bits[i] = bits[N+1-i];
				bits[N+1-i] = buffer;
			}
			break;
		case 3:
			for (int i = 1; i < index + 1; i++) {
				int buffer = bits[i];
				bits[i] = !bits[N+1-i];
				bits[N+1-i] = !buffer;
			}
			break;
		default:
			break;
	}
}





void guessBit(int B) {
	int queryCount = 0;
	int indexCount = 0;
	std::map<int, int> bits;
	int same = -1;
	int different = -1;

	while(1) {
	 	queryCount++;
		if (indexCount == B/2) {
			break;
		}
		if (queryCount % 10 == 1 && queryCount != 1) {
			int a, b;
			char c, d;

			if (same == -1 || different == -1) {
				std::cout << 1 << std::endl;
				std::cin >> c;
				if (c == 'N') {
					exit(0);
				}
				a = c - '0';
				std::cout << 2 << std::endl;
				std::cin >> d;
				if (d == 'N') {
					exit(0);
				}
				b = d - '0';

				if (a == bits[1] && b == bits[2]) {
					applyChange(bits, B, 0, indexCount);
				} else {
					applyChange(bits, B, 1, indexCount);
				}
				queryCount+=2;
			} else {
				if (bits[same] == bits[different]) {
					std::cout << B + 1 - same << std::endl;
					std::cin >> c;
					if (c == 'N') {
						exit(0);
					}
					a = c - '0';
					std::cout << B + 1 - different << std::endl;
					std::cin >> d;
					if (d == 'N') {
						exit(0);
					}
					b = d - '0';

					int status = identifyChange({bits[same], bits[different]}, {bits[B + 1 - same], bits[B + 1 - different]}, {a, b});

					applyChange(bits, B, status, indexCount);

					if (status == 2 || status == 3) {
						int buffer = same;
						same = different;
						different = buffer;
					}
					queryCount+=2;
				} else {
					std::cout << same << std::endl;
					std::cin >> c;
					if (c == 'N') {
						exit(0);
					}
					a = c - '0';
					std::cout << different << std::endl;
					std::cin >> d;
					if (d == 'N') {
						exit(0);
					}
					b = d - '0';

					int status = identifyChange({bits[B + 1 - same], bits[B + 1 - different]}, {bits[same], bits[different]}, {a, b});

					applyChange(bits, B, status, indexCount);

					if (status == 2 || status == 3) {
						int buffer = same;
						same = different;
						different = buffer;
					}
					queryCount+=2;
				}

			}
		}

	  	indexCount++;
	   	std::cout << indexCount << std::endl;
 		int value, oppValue;
		char e, f;
 		std::cin >> e;
		if (e == 'N') {
			exit(0);
		}
		value = e - '0';
 		bits.insert({indexCount, value});		
 		queryCount++;
		std::cout << B-indexCount+1 << std::endl;
 		std::cin >> f;
		if (f == 'N') {
			exit(0);
		}
		oppValue = f - '0';
 		bits.insert({B-indexCount+1, oppValue});
 		if (value == oppValue && same == -1) {
 			same = indexCount;
 		}

	 	if (value != oppValue && different == -1) {
 			different = indexCount;
		}
	}

	for (int i = 1; i <= B; i++) {
		std::cout << bits[i];
	}
	std::cout << std::endl;

	char response;
	std::cin >> response;

	if (response == 'N') {
		exit(0);
	}

}




int main() {
	int T, B;
	std::cin >> T >> B;


	std::cout << std::unitbuf;
	for (int i = 0; i < T; i++) {
		guessBit(B);
	}

}
