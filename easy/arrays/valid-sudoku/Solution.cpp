class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row = checkRow(board);
        if (!row) {
            return false;
        }
        bool col = checkCol(board);
        if (!col) {
            return false;
        }
        bool sqs = checkSqs(board);
        if (!sqs) {
            return false;
        }
        return true;
    }
    
    bool checkRow(vector<vector<char>> &board) {
        
        for (int i = 0; i < board.size(); i++) {
            vector<int> arr(9, 0);
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    // it is a number
                    int curr = board[i][j] - '0';
                    if (arr[curr - 1] == 1) {
                        // number already exists
                        return false; 
                    } else {
                        arr[curr - 1] = 1;
                    }
                    
                }
                
            }
            
        }
        
        return true;
    }
    
    bool checkCol(vector<vector<char>> &board) {
        
        for (int j = 0; j < board.size(); j++) {
            vector<int> arr(9,0);
            for (int i = 0; i < board[j].size(); i++) {
                if (board[i][j] != '.') {
                    // it is a number
                    int curr = board[i][j] - '0';
                    if (arr[curr - 1] == 1) {
                        // number already exists
                        return false; 
                    } else {
                        arr[curr - 1] = 1;
                    }
                }
            }
        }
        
        return true;
    }
    
    bool checkSqs(vector<vector<char>> &board) {
        
        for (int i = 0; i < board.size() / 3; i++) {
            for (int j = 0; j < board[i].size() / 3; j++) {
                bool res = checkSq(board, i, j);
                if (!res) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool checkSq(vector<vector<char>> &board, int i, int j) {
        
        int startRow = i * 3;
        int endRow = i * 3 + 2;
        int startCol = j * 3;
        int endCol = j * 3 + 2;
        vector<int> arr(9,0);
        
        for (int r = startRow; r <= endRow; r++) {
            
            for (int c = startCol; c <= endCol; c++) {
                if (board[r][c] != '.') {
                    int curr = board[r][c] - '0';
                
                    if (arr[curr - 1] == 1) {
                        return false;
                    } else {
                        arr[curr - 1] = 1;
                    }
                }

                
            }
            
        }
        
        return true;
    }
};
