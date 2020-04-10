#include <iostream>
#include <string>

bool backspaceCompare(std::string S, std::string T) {
	int sIndex = (int) S.length() - 1;
	int tIndex = (int) T.length() - 1;
        int sCount = 0;
        int tCount = 0;

	while (true) {
            if (S[sIndex] == '#') {
		sIndex--;
                sCount++;
            }

            if (T[tIndex] == '#') {
		tIndex--;
                tCount++;
            }

            if (S[sIndex] != '#') {
                if (sCount) {
			if (sCount >= sIndex) {
				sCount-=sIndex;
				sIndex = -1;
			} else {
				sIndex -= sCount;
				sCount = 0;
			}
                }
            }

            if (T[tIndex] != '#') {
                if (tCount) {
			if (tCount >= tIndex) {
				tCount-=tIndex;
				tIndex = -1;
			} else {
				tIndex -= tCount;
				tCount = 0;
			}
                }
            }

	    if (S[sIndex] != '#' && T[tIndex] != '#') {
                if (S[sIndex] != T[tIndex]) {
                    return false;
                }
		sIndex--;
		tIndex--;
            }
	    
	    if (sIndex <= 0 || tIndex <= 0) {
	    	    break;
	    }
        }

	if (sCount > 0 && tCount > 0) {
		return true;
	} else {
		return S[sIndex] == T[tIndex];
	}

}

int main() {
	std::cout << backspaceCompare("ab##", "c#d#") << "\n";
}


