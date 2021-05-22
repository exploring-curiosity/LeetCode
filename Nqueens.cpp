class Solution {
public:
    vector<vector<string>> res;
    void appendBoard(vector<int> board)
    {
        int n=board.size();
        string s(n,'.');
        vector<string> qboard;
        for(auto itr:board)
        {
            s[itr]='Q';
            qboard.push_back(s);
            s[itr]='.';
        }
        res.push_back(qboard);
    }
    bool isSafe(vector<int> board,int r2,int c2)
    {
        for(int r1=0;r1<r2;r1++)
        {
            int c1 =  board[r1];
            if((c1==c2)||(abs(c1-c2)==abs(r1-r2)))
                return false;
        }
        return true;
    }
    void n_queens(vector<int> board,int row)
    {   
        int n=board.size();
        if(row==n)
        {
            appendBoard(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(find(board.begin(),board.end(),i)==board.end())
            {
                if(isSafe(board,row,i))
                {
                    board[row]=i;
                    n_queens(board,row+1);
                }    
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> board(n,-1);
        n_queens(board,0);
        return res;
    }
};