/*
Given a 2D board and a word, find if the word exists in the grid. 
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once. 
For example,
Given board = 
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:
   
bool CheckExists(vector<vector<char>>& board,string word,int i, int j,int index,vector<vector<bool>> visited) {
    
    if(index==word.length()) return true;
    
     int m = board.size();
     int n = board[0].size();
    
    if(i<0 || j <0 || i >=m || j >= n) return false;
    
    if(board[i][j] != word[index] || visited[i][j] == true) return false;
   
    visited[i][j] = true;
    
    return CheckExists(board,word,i,j+1,index+1,visited) ||
           CheckExists(board,word,i,j-1,index+1,visited) ||
           CheckExists(board,word,i+1,j,index+1,visited) ||
           CheckExists(board,word,i-1,j,index+1,visited) ;
        
        
}
    

    
bool exist(vector<vector<char>>& board, string word) {
    
    int b = word.length();
    if(b==0) return true;
        
       int m = board.size();
       if(m==0) return false;
    
       int n = board[0].size();
       if(n==0) return false;

    
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(word[0]==board[i][j])
                {
                    vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
   
                   if(CheckExists(board,word,i,j,0,visited))
                     {
                         return true;
                     } 
                }
                
            }
        
        return false;
        
    }
                      
    
   
};
                      
                      
                      
                      
                      
                      
                      
                      
                      