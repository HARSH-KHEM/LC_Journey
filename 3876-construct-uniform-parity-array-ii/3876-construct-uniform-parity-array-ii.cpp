class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();

        int even = 0, odd = 0;
        int minOdd = INT_MAX;

        for (int x : nums) {
            if (x % 2 == 0) even++;
            else {
                odd++;
                minOdd = min(minOdd, x);
            }
        }

        if (even == 0 || odd == 0) return true;

        for (int x : nums) {
            if (x % 2 == 0) {
                if (x <= minOdd) return false;
            }
        }

        return true;
    }
};