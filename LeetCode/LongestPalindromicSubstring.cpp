#include <iostream>
#include <string>
#include <map>


// for s = abcbd
// a ab abc abcb abcbd
// b bc bcb bcbd
// c cb cd
// b bd
// d
std::string longestPalindromic(std::string s) {
	bool palindrome[1000][1000] = {{false}};
        int longestLength = 0;
	std::pair<int, int> index = {0, 0};


        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j <= i; j++) {
                palindrome[j][i] = (i==j) || ((i-j == 1) && s[i] == s[j]);

                if (i > 1) {
                    palindrome[j][i] = palindrome[j+1][i-1] && s[j] == s[i];
                }

		std::cout << "(i, j): " << i << ", " << j << "): " << palindrome[j][i] << "|" << s.substr(j, i + 1 - j) << "\n";

                if (palindrome[j][i] && i+1-j > longestLength) {
                    longestLength = i+1-j;
                    index = {i, j};
                }


            }
        }

	std::cout << index.first << ", " << index.second << "\n";

        return s.substr(index.first, index.first + 1 - index.second);

}


int main() {
	longestPalindromic("cbbd");
}
