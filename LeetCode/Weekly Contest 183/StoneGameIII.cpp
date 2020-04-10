#include <iostream>
#include <vector>
#include <string>
std::pair<int, int> pickHowMany(int a, int b, int c) {
        int ab = a+b;
        int abc = a+b+c;

        if (a >= ab && a >= abc) {
            return {a, 1};
        } else if (ab >= abc && ab >= a) {
            return {ab, 2};
        } else {
            return {abc, 3};
        }
    }




std::string stoneGameIII(std::vector<int>& stoneValue) {
        int alice = 0;
        int bob = 0;
        int turn = 1;

        int currentIndex = 0;
	int size = (int) stoneValue.size();

        if (size == 3) {
		std::cout << "1" << "\n";
            if ((stoneValue[0]+stoneValue[1]+stoneValue[2] > 0) || (stoneValue[0] + stoneValue[1] > stoneValue[2])) {
                return "Alice";
            } else if ((stoneValue[0]+stoneValue[1]+stoneValue[2] == 0) || (stoneValue[0] + stoneValue[1] == stoneValue[2])) {
                return "Tie";
            } else {
                return "Bob";
            }
        }

        while (currentIndex < size - 2) {
		std::pair<int, int> buffer = pickHowMany(stoneValue[currentIndex], stoneValue[currentIndex+1], stoneValue[currentIndex+ 2]);
            currentIndex += buffer.second;

            if (turn) {
                alice += buffer.first;
		std::cout << "Alice picked: " << buffer.first << "|" << buffer.second << "\n";
            } else {
                bob += buffer.first;
		std::cout << "Bob picked: " << buffer.first << "|" << buffer.second << "\n";
            }

            turn = !turn;
        }

        if (currentIndex == size - 1) {
		std::cout << "3" << "\n";
            if (turn) {
                alice += stoneValue[currentIndex];
            } else {
                bob += stoneValue[currentIndex];
            }
        } else if (currentIndex == size - 2) {
		std::cout << "4" << "\n";
            int secondLast = stoneValue[currentIndex];
            int last = stoneValue[currentIndex];

            if ((secondLast >= 0 && last >= 0) || (secondLast <= 0 && last >= 0)) {
                if (turn) {
                    alice = alice + secondLast + last;
                } else {
                    bob = bob + secondLast + last;
                }
            } else {
                if (turn) {
                    alice += secondLast;
                    bob += last;
                } else {
                    alice += last;
                    bob += secondLast;
                }
            }
        }
	std::cout << alice << "|" << bob << "\n";

        if (alice > bob) {
            return "Alice";
        } else if (bob > alice) {
            return "Bob";
        } else {
            return "Tie";
        }
    }

int main() {
	std::vector<int> a = {6,-9,11,6,9,-3,-17,-10,15,-14,-10,9,3,4,-4,17,2,3,-9,-16,17,2,5};
	std::cout << stoneGameIII(a);
}
