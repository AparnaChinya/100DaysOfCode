/*
CTCI 8.2 Robot in a Grid
Find the path for a robot sitting at top left till bottom right along with obstacles
*/

#include <iostream>

bool getPath(vector<vector<int>> Grid, vector<vector<int>> &resultPath, int row, int col) {
    if (row < 0 || col < 0 || !Grid[row][col]) {
        return false;
    }

    bool isOrigin = (row == 0) && (col == 0);


    if(isOrigin || getPath(Grid,resultPath,row-1,col) || getPath(Grid,resultPath,row,col-1))     {
        vector<int> temp ;
        temp.push_back(row);
        temp.push_back(col);
        resultPath.push_back(temp);
        return true;
    }
    return false;
}

int main() {
    std::cout << "Hello World!\n";

    vector<vector<int>> Grid = {{1,1,1,0},{0,1,0,0},{0,1,1,0},{0,0,1,1}};

    vector<vector<int>> resultPath;

    if(getPath(Grid,resultPath,Grid.size()-1,Grid[0].size()-1)) {
        for(int i = 0; i < resultPath.size(); i++) {
            cout<< "(";
            for(int j = 0; j < resultPath[0].size(); j++) {
                cout << resultPath[i][j];
            }
            cout<<  ")" << " -> ";
        }
    } else
        cout << "No Path Found";

}