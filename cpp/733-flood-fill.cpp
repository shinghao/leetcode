// Time -> O(row * col), Space -> O(row * col);

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        fill(image, sr, sc, color, image[sr][sc]);
        return image;
    }
    void fill(vector<vector<int>>& image, int sr, int sc, int color, int connectColor) {
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) {
            return;
        } 
        if(image[sr][sc] != connectColor || image[sr][sc] == color) {
            return;
        }
        
        image[sr][sc] = color;
        
        fill(image, sr, sc + 1, color, connectColor);
        fill(image, sr, sc - 1, color, connectColor);
        fill(image, sr + 1, sc, color, connectColor);
        fill(image, sr - 1, sc, color, connectColor);
    }
};