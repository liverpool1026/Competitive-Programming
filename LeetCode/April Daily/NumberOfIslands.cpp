#include <iostream>
#include <vector>

void repopulate(std::vector<std::vector<char>>& grid, int x, int y);

int numIslands(std::vector<std::vector<char>>& grid) {
        int count = 0;
        
        if (grid.size()) {
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    if (grid[i][j] == '1') {
                        count++;
                        
                        // DSF: L / T / R / D
                        repopulate(grid, i, j);
                        
                        
                    }
                }
            }
            
            return count;

            
        } else {
            return 0;
        }
        
        
}
    
void repopulate(std::vector<std::vector<char>>& grid, int x, int y) {
        //vector<pair<int,int>> visited;
        
        //visited.emplace_back(x, y);
        grid[x][y] = '0';
        
        
        if (y != 0 && grid[x][y-1] == '1') {
            repopulate(grid, x, y-1);
        } 
        
        if (x != 0 && grid[x-1][y] == '1') {
            repopulate(grid, x-1, y);
        }
        
        if (y != grid[0].size() - 1 && grid[x][y+1] == '1') {
            repopulate(grid, x, y+1);
        }
        
        if (x != grid.size() - 1 && grid[x+1][y] == '1') {
            repopulate(grid, x+1, y);
        }    
}


int main() {
	std::vector<std::vector<char>> vec;

	vec.emplace_back(std::vector<char>({'1', '1', '0', '0', '0'}));
	vec.emplace_back(std::vector<char>({'1', '1', '0', '0', '0'}));
	vec.emplace_back(std::vector<char>({'0', '0', '1', '0', '0'}));
	vec.emplace_back(std::vector<char>({'0', '0', '0', '1', '1'}));

	std::cout << numIslands(vec) << "\n";

}


