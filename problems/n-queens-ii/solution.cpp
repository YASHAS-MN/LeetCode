class Solution {
public:
    private:
    int total_solutions = 0;
    
    // Arrays to track occupied columns and both diagonal orientations
    bool cols[9] = {false};
    bool diag1[17] = {false}; // Principal diagonals: row + col (Max index: 8 + 8 = 16)
    bool diag2[17] = {false}; // Anti-diagonals: row - col + n - 1 (Max index: 8 - 0 + 9 - 1 = 16)

    void backtrack(int row, int n) {
        // Base case: All queens are successfully placed
        if (row == n) {
            total_solutions++;
            return;
        }

        for (int col = 0; col < n; ++col) {
            int d1 = row + col;
            int d2 = row - col + n - 1;

            // If the current column or diagonals are under attack, skip
            if (cols[col] || diag1[d1] || diag2[d2]) {
                continue;
            }

            // Place the queen (Mark positions)
            cols[col] = diag1[d1] = diag2[d2] = true;

            // Recurse to the next row
            backtrack(row + 1, n);

            // Backtrack (Remove the queen)
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }

public:
    int totalNQueens(int n) {
        total_solutions = 0;
        backtrack(0, n);
        return total_solutions;
    }
};