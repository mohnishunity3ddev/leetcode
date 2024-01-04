#if !defined(SUDOKU_SOLVER_H)

#include <vector>
#include <assert.h>

using namespace std;

class Solution
{
  public:
    void
    removeFromVector(vector<int> &v, int toRemove)
    {
        for (int i = 0; i < v.size(); ++i)
        {
            if(v[i] == toRemove) {
                v.erase(std::remove(v.begin(), v.end(), toRemove));
                break;
            }
        }
    }

    void
    getPossibleSols(int numsBoard[9][9], vector<int> &sols, int i, int j)
    {
        // get sub-block
        int x = i / 3;
        int y = j / 3;

        int row = i;
        int col = j;

        vector<int> temp = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        // elimintating from rows.
        for (int r = 0; r < 9; ++r)
        {
            if(numsBoard[row][r] != 0) {
                removeFromVector(temp, (numsBoard[row][r]));
            }
        }
        if(temp.size() == 1) {
            numsBoard[i][j] = temp[0];
            sols.clear();
            return;
        }
        for (int c = 0; c < 9; ++c) {
            if(numsBoard[c][col] != 0) {
                removeFromVector(temp, (numsBoard[c][col]));
            }
        }
        if(temp.size() == 1) {
            numsBoard[i][j] = temp[0];
            sols.clear();
            return;
        }

        for(int si = x*3; si < (x*3 + 3); ++si) {
            for (int sj = y*3; sj < (y*3 +3); ++sj) {
                int n = (numsBoard[si][sj]);
                removeFromVector(temp, n);
            }
        }

        for (int t = 0; t < temp.size(); ++t) {
            bool contains = false;
            for (int ti = 0; ti < sols.size(); ++ti) {
                if(sols[ti] == temp[t]) {
                    contains = true;
                    break;
                }
            }
            if(!contains) {
                sols.push_back(temp[t]);
            }
        }

        if(sols.size() == 1) {
            numsBoard[i][j] = sols[0];
            sols.clear();
        }
    }

    void
    SolveSudoku(vector<vector<char>> &board)
    {
        assert(board.size() == 9);
        for (int i = 0; i < board.size(); ++i){
            assert(board[i].size() == 9);
        }

        int numsBoard[9][9];
        int potentialSols[81][9];
        vector<int> a[81];
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j)
            {
                if(board[i][j] == '.') {
                    numsBoard[i][j] = 0;
                }
                else {
                    char c = board[i][j];
                    numsBoard[i][j] = (int)(c - '0');
                }
            }
        }
        numsBoard[5][6] = 8;

        while(true) {
            for (int i = 0; i < 9; ++i){
                for (int j = 0; j < 9; ++j)
                {
                    if(numsBoard[i][j] == 0) {
                        getPossibleSols(numsBoard, a[9*i + j], i, j);
                    }
                }
            }

            for (int i = 0; i < 81; ++i) {
                if(a[i].size() == 1) {
                    int x = 0;
                }
            }
        }
    }

    void
    driver()
    {
        vector<vector<char>> board = {
            { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
            { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
            { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
            { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
            { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
            { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
            { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
            { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
            { '.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };

        SolveSudoku(board);
    }


};

#define SUDOKU_SOLVER_H
#endif