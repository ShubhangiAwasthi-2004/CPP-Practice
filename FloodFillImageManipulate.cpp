/*You are given a 2D grid image[][] of size n*m, where each image[i][j] represents the color of a pixel in the image.
Also provided a coordinate(sr, sc) representing the starting pixel (row and column) and a new color value newColor.

Your task is to perform a flood fill starting from the pixel (sr, sc), changing its color to newColor
and the color of all the connected pixels that have the same original color. 
Two pixels are considered connected if they are adjacent horizontally or vertically (not diagonally) and have the same original color.*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // If the starting pixel already has the new color, no need to proceed
        if (image[sr][sc] == newColor) {
            return image;
        }
        
        // Get the original color and start DFS
        int originalColor = image[sr][sc];
        dfs(image, sr, sc, originalColor, newColor);
        
        return image;
    }
    
private:
    void dfs(vector<vector<int>>& image, int row, int col, int originalColor, int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        // Check if current position is out of bounds or has a different color
        if (row < 0 || row >= n || col < 0 || col >= m || image[row][col] != originalColor) {
            return;
        }
        
        // Change the color of the current pixel
        image[row][col] = newColor;
        
        // Recursively visit all four adjacent cells
        dfs(image, row + 1, col, originalColor, newColor); // Down
        dfs(image, row - 1, col, originalColor, newColor); // Up
        dfs(image, row, col + 1, originalColor, newColor); // Right
        dfs(image, row, col - 1, originalColor, newColor); // Left
    }
};
