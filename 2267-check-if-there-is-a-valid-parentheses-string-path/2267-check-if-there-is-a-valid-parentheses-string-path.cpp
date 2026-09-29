class Solution {
public:
    int dp[101][101][202];
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp, -1, sizeof(dp));
        return solve(grid);
    }
    bool solve(vector<vector<char>>& grid, int i = 0, int j = 0, int balance = 0){
        if(i >= grid.size() || j >= grid[0].size()) return false;

        if(grid[i][j] == '(') balance++;
        else balance--;

        if(balance < 0) return false;

        if(dp[i][j][balance] != -1) return dp[i][j][balance];

        if(i == grid.size() -1 && j == grid[0].size() - 1){
            if(balance == 0) return true;
            else return false;
        }

        return dp[i][j][balance] = solve(grid, i + 1, j, balance) || solve(grid, i, j + 1, balance);
    }
};