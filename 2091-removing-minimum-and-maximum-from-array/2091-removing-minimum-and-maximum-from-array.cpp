class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        int minel = INT_MAX;
        int maxel = INT_MIN;

        int minl = 0;
        int maxl = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] < minel) {
                minel = nums[i];
                minl = i;
            }

            if (nums[i] > maxel) {
                maxel = nums[i];
                maxl = i;
            }
        }


        int front = max(minl, maxl) + 1;

        int back = n - min(minl, maxl);

        int mixed = min(
            minl + 1 + n - maxl,
            maxl + 1 + n - minl
        );

        return min({front, back, mixed});
    }
};