#include <iostream>
#include <string>
#include <map>


bool canConstruct(std::string s, int k) {
	std::map<char, int> count;
	if (s.length() == k) {
		return true;
	} else if (s.length() < k) {
            return false;
        }
        
        for (char c : s) {
            count[c]++;
        }
        
        int oneLetterEntry = 0;
        
        for (auto const& x : count) {
            if (x.second % 2) {
                oneLetterEntry++;
            }
        }
        
        if (oneLetterEntry > k) {
            return false;
        } 
        return true;
}


int main() {
	std::cout << canConstruct("annabelle", 2);
}
