class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        unordered_map<int, vector<int>> reserved;
        for(auto &p : rs) {
            reserved[p[0]].push_back(p[1]);
        }
        int cnt = 2 * n;
        for(auto &[row, seats] : reserved) {

            bool left = true;   // 2,3,4,5
            bool middle = true; // 4,5,6,7
            bool right = true;  // 6,7,8,9

            for(int seat : seats) {

                if(seat >= 2 && seat <= 5)
                    left = false;

                if(seat >= 4 && seat <= 7)
                    middle = false;

                if(seat >= 6 && seat <= 9)
                    right = false;
            }
            cnt -= 2;

            if(left && right)
                cnt += 2;
            else if(left || middle || right)
                cnt += 1;
        }

        return cnt;
    }
};