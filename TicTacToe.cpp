/* 348. Design Tic-Tac-Toe
Design a Tic-tac-toe game that is played between two players on a n x n grid.
You may assume the following rules:
	1. A move is guaranteed to be valid and is placed on an empty block.
	2. Once a winning condition is reached, no more moves is allowed.
	3. A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Example:
Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.
TicTacToe toe = new TicTacToe(3);
toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |
toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |
toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|
toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|
toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|
toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|
toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|

From <https://leetcode.com/problems/design-tic-tac-toe/description/>
*/

class TicTacToe {
public:
    /** Initialize your data structure here. */
    map<int,pair<int,int>> rowMap;
    map<int,pair<int,int>> colMap;
    pair<int,int> diagonal1, diagonal2;
    int N;

    TicTacToe(int n) {
        diagonal1 = make_pair(0,0);
        diagonal2 = make_pair(0,0);
        this->N = n;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(rowMap.find(row) == rowMap.end()) rowMap[row] = make_pair(0,0);
        if(colMap.find(col) == colMap.end()) colMap[col] = make_pair(0,0);
        if(player == 1) {
            rowMap[row].first++;
            colMap[col].first++;
            if(row == col) {
                diagonal1.first++;
            }
            if(row + col == N-1) {
                diagonal2.first++;
            }
            if(rowMap[row].first == N || colMap[col].first == N
               || (row == col && diagonal1.first == N) || (((row + col) == N-1) && diagonal2.first == N)) {
                return 1;
            }

        }
        if(player == 2) {
            rowMap[row].second++;
            colMap[col].second++;
            if(row == col) {
                diagonal1.second++;
            }
            if(row + col == N-1) {
                diagonal2.second++;
            }
            if(rowMap[row].second == N || colMap[col].second == N
               || (row == col && diagonal1.second == N) || (((row + col) == N-1) && diagonal2.second == N)) {
                return 2;
            }

        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */

