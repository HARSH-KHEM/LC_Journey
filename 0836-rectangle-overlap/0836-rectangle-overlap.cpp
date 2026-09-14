class Solution {
public:
    bool isRectangleOverlap(vector<int>& rect1, vector<int>& rect2) {
        int x1 = rect1[0];
        int x2 = rect1[2];
        int x3 = rect2[0];
        int x4 = rect2[2];
        int y1 = rect1[1];
        int y2 = rect1[3];
        int y3 = rect2[1];
        int y4 = rect2[3];
        bool xoverlap = max(x3,x1)<min(x2,x4);
        bool yoverlap = max(y3,y1)<min(y2,y4);
        return xoverlap && yoverlap ;
    }
};