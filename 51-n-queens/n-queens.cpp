class Solution {
public:
    void solve(int col, int n, vector<string>& board, vector<vector<string>>& ans, vector<int>& rowUsed, vector<int>& upperDiag, vector<int>& lowerDiag){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(rowUsed[row] || upperDiag[n -1 + col - row] || lowerDiag[row + col]) continue;

            // PLace Queen
            board[row][col] = 'Q';
            rowUsed[row] = 1;
            upperDiag[n - 1 + col - row] = 1;
            lowerDiag[row + col] = 1;

            solve(col + 1, n, board, ans, rowUsed, upperDiag, lowerDiag);

            // Backtrack
            board[row][col] = '.';
            rowUsed[row] = 0;
            upperDiag[n - 1 + col - row] = 0;
            lowerDiag[row + col] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> rowUsed(n, 0);
        // 2n-1 possible diagonals
        vector<int> upperDiag(2 * n - 1, 0);
        vector<int> lowerDiag(2 * n - 1, 0);
        solve(0, n, board, ans, rowUsed, upperDiag, lowerDiag);
        return ans;
    }
};