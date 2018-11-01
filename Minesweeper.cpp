class Solution {
public:
    vector<vector<int>> directions = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

    void dfs(vector<vector<char>>& board, int x, int y) {
        //If the starting point doesnt fit the rules, return
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != 'E') {
            return;
        }

        int count = 0;
        //for all the 8 directions
        for(int i = 0; i < directions.size(); i++) {
            //update the x and y
            int r = x + directions[i][0];
            int c = y + directions[i][1];

            //if the rules fit and if the cell has an unrevealed mine, increment the count
            if(r >= 0 && r < board.size() && c >= 0 && c < board[0].size() && board[r][c] == 'M') {
                count++;
            }
        }

        //if the count is greater than 0, update the count of the cell else its a revealed blank square
        board[x][y] = (count > 0) ? (count + '0') : 'B';

        //If its not a revealed blank square return
        if(board[x][y] != 'B') {
            return;
        }

        //For all the 8 directions call the dfs
        for(int i = 0; i < directions.size(); i++) {
            dfs(board,x+directions[i][0],y+directions[i][1]);
        }

    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0];
        int y = click[1];

        //If the starting click is an unrevealed mine, return X
        if(board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        //DFS
        dfs(board,x,y);
        return board;
    }
};