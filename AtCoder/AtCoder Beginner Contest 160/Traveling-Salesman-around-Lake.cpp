#include <iostream>


int main() {
	int K, N;
	int previousBuffer = -1;
	int buffer;
	int firstElement = 0;
	int maxGap = 0;
	int result = 0;
	int count = 0;
	int flag = 0;

	std::cin >> K >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> buffer;
		if (i == 0) {
			firstElement = buffer;
		}
		if (previousBuffer != -1) {
			int bufferFlag = 1;
			int distance = std::abs(buffer - previousBuffer);
			int otherDistance = std::abs(K - std::max(buffer, previousBuffer) + std::min(buffer, previousBuffer));

			if (distance > otherDistance) {
				bufferFlag = -1;
				distance = otherDistance;
			} else {
				distance = distance;
			}

			distance = std::min(distance, std::abs(K - std::max(buffer, previousBuffer) + std::min(buffer, previousBuffer)));
			if (distance > maxGap) {
				count = i;
				maxGap = distance;
				flag = bufferFlag;
			}
		}
		previousBuffer = buffer;
	}

	if (N == 2) {
		std::cout << maxGap;
		return 0;
	}

	int distance = std::abs(previousBuffer - firstElement);
	distance = std::min(distance, std::abs(K - std::max(firstElement, previousBuffer) + std::min(firstElement, previousBuffer)));
	if (distance >= maxGap) {
		maxGap = distance;
		result = flag == -1 ? maxGap : K - maxGap;
		std::cout << result;
		return 0;
	}

	if (count == N - 1) {
		result = flag != 1 ? maxGap : K - maxGap;
	} else {
		result = K - maxGap;
	}


        std::cout << result;

}
