class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
       
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));  // Initialize an empty board
        unordered_set<int> cols, diag1, diag2;  // Sets to track columns and diagonals
        backtrack(n, 0, board, result, cols, diag1, diag2);
        return result;
    }

    void backtrack(int n, int row, vector<string>& board, vector<vector<string>>& result,
                   unordered_set<int>& cols, unordered_set<int>& diag1, unordered_set<int>& diag2) {
        if (row == n) {
            result.push_back(board);  // All queens are placed, add solution to result
            return;
        }

        for (int col = 0; col < n; col++) {
            // Check if the column or diagonals are already occupied
            if (cols.count(col) || diag1.count(row - col) || diag2.count(row + col)) {
                continue;  // Skip if queen cannot be placed in this cell
            }

            // Place the queen
            board[row][col] = 'Q';
            cols.insert(col);  // Mark column as occupied
            diag1.insert(row - col);  // Mark main diagonal as occupied
            diag2.insert(row + col);  // Mark anti-diagonal as occupied

            // Recurse to place queens in the next row
            backtrack(n, row + 1, board, result, cols, diag1, diag2);

            // Backtrack: remove the queen and undo the marks
            board[row][col] = '.';
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }
};