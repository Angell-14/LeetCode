class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> triangle;
    
    // Loop through rows
    for (int i = 0; i < numRows; i++) {
        vector<int> row(i + 1, 1);  // Create a row with 'i + 1' elements, initialized to 1
        
        // Fill in the middle values of the row (excluding the 1's at both ends)
        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        
        // Add the current row to the triangle
        triangle.push_back(row);
    }
    
    return triangle;
} 
    
};