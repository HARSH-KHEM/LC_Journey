
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int prev1 = 0, prev2 = 1e9, prev3 = 1e9;
        for(int i = 1; i <= n; i++) {
            int cost = costs[i-1] + prev1 + 1;
            cost = min(cost, costs[i-1] + prev2 + 4);
            cost = min(cost, costs[i-1] + prev3 + 9);
            prev3 = prev2;
            prev2 = prev1;
            prev1 = cost;
        }
        return prev1;
    }
};
