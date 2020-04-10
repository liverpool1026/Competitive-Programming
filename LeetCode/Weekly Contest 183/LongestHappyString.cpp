#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//std::cout << "Pair: " << pair.second << pair.first << "\n";

void putResult(std::string& str, char c, int count) {
	for (int i = 0; i < count; i++) {
		str = str + c;
	}
}


std::string longestDiverseString(int a, int b, int c) {
        std::string result = "";
        std::vector<std::pair<int, char>> vec = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
	char ch = 'd';

        int size = (int) vec.size();
        while (size > 1) {
	    std::sort(vec.rbegin(), vec.rend());
	    int indicator = (vec[0].first - vec[1].first > 2);

	    if (vec[0].first > 1) {
		    putResult(result, vec[0].second, 2);
		    ch = vec[0].second;
		    vec[0].first -= 2;
            } else {
		    putResult(result, vec[0].second, 1);
		    ch = vec[0].second;
		    vec[0].first -= 1;
	    }

	    if (vec[1].first > 1 && !indicator) {
		    putResult(result, vec[1].second, 2);
		    ch = vec[1].second;
		    vec[1].first -= 2;
            } else {
		    putResult(result, vec[1].second, 1);
		    ch = vec[1].second;
		    vec[1].first -= 1;
	    }

	    std::vector<std::pair<int, char>>::iterator it;

	    int flag = 0;
	    for (it = vec.begin(); it < vec.end(); it++) {
		    std::pair<int, char> p = *it;
		    if (flag) {
			    vec.erase(it-1);
			    flag = 0;
		    }
		    if (p.first == 0) {
			    flag = 1;
		    }
	    }
	    if (flag) {
		    for (it = vec.begin(); it < vec.end(); it++) {
			    std::pair<int, char> ab = *it;
			    if (ab.first == 0) {
				    vec.erase(it);
				    flag = 0;
			    }
		    }
	    }

	    size = (int) vec.size();
	}

	if (vec[0].second != ch) {
		if (vec[0].first > 1) {
			putResult(result, vec[0].second, 2);
		} else {
			putResult(result, vec[0].second, 1);
		}
	}


        return result;
}


int main() {
	std::cout << longestDiverseString(1, 1, 7) << "\n";
	std::cout << longestDiverseString(2, 2, 1) << "\n";
	std::cout << longestDiverseString(7, 1, 0) << "\n";
}


