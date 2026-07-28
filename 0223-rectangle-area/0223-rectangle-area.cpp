class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int rec1L = abs(ay1-ay2);
        int rec1W = abs(ax1-ax2);
        int rec2L = abs(by1-by2);
        int rec2W = abs(bx1-bx2);
        
        int area1 = rec1L*rec1W;
        int area2 = rec2L*rec2W;

        if (ax2 <= bx1 || ax1 >= bx2 || ay2 <= by1 || ay1 >= by2) {
            return area1+area2;
        }

        // intersection coordinates
        int leftCornerX = max(ax1, bx1);
        int leftCornerY = max(ay1, by1);

        int rightCornerX = min(ax2, bx2);
        int rightCornerY = min(ay2, by2);

        int interSectionArea = abs(leftCornerX-rightCornerX)* abs(leftCornerY-rightCornerY);

        int finalArea = area1+area2-interSectionArea;

        return finalArea;
    }
};