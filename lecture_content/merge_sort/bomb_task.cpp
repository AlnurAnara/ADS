//扫雷游戏 
/*

*/
#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

const int W= 10; //width
const int H = 10;//heigh
const int N = 15;//nums of bombs

// 棋盘结构
struct Cell {
    bool isMine = false;
    bool isRevealed = false;
    bool isFlagged = false;
    int adjacentMines = 0;
};

// 打印棋盘
void printBoard(const vector<vector<Cell>>& board, bool gameOver = false) {
    cout << "   ";
    for (int i = 0; i < W; ++i) {
        cout << i << " ";
    }
    cout << endl << "  ---------------------" << endl;

    for (int i = 0; i < H; ++i) {
        cout << i << "| ";
        for (int j = 0; j < W; ++j) {
            if (gameOver && board[i][j].isMine) {
                cout << "* "; // 游戏结束时显示所有雷
            } else if (board[i][j].isRevealed) {
                if (board[i][j].isMine) {
                    cout << "* "; // 踩到雷
                } else {
                    cout << board[i][j].adjacentMines << " ";
                }
            } else {
                cout << "# "; // 未揭开的格子
            }
        }
        cout << endl;
    }
}

// 递归揭开格子 (Flood Fill)
void revealCell(vector<vector<Cell>>& board, int r, int c) {
    // 边界检查或如果已经揭开，则返回
    if (r < 0 || r >= H || c < 0 || c >= W || board[r][c].isRevealed) {
        return;
    }

    board[r][c].isRevealed = true;

    // 如果揭开的是 '0'，则递归揭开所有邻居
    if (board[r][c].adjacentMines == 0) {
        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                if (dr == 0 && dc == 0) continue;
                revealCell(board, r + dr, c + dc);
            }
        }
    }
}

// 检查胜利条件
bool checkWin(const vector<vector<Cell>>& board) {
    int revealedCount = 0;
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            if (board[i][j].isRevealed) {
                revealedCount++;
            }
        }
    }
    // 如果所有非雷格子都被揭开，则胜利
    return revealedCount == (BOARD_WIDTH * BOARD_HEIGHT - NUM_MINES);
}


int main() {
    srand(time(0)); // 初始化随机数种子

    vector<vector<Cell>> board(BOARD_HEIGHT, vector<Cell>(BOARD_WIDTH));

    // 1. 随机布雷
    int minesPlaced = 0;
    while (minesPlaced < NUM_MINES) {
        int r = rand() % BOARD_HEIGHT;
        int c = rand() % BOARD_WIDTH;
        if (!board[r][c].isMine) {
            board[r][c].isMine = true;
            minesPlaced++;
        }
    }

    // 2. 计算每个格子周围的雷数
    for (int r = 0; r < BOARD_HEIGHT; ++r) {
        for (int c = 0; c < BOARD_WIDTH; ++c) {
            if (board[r][c].isMine) continue;
            int count = 0;
            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {
                    if (dr == 0 && dc == 0) continue;
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr >= 0 && nr < BOARD_HEIGHT && nc >= 0 && nc < BOARD_WIDTH && board[nr][nc].isMine) {
                        count++;
                    }
                }
            }
            board[r][c].adjacentMines = count;
        }
    }

    bool gameOver = false;
    while (!gameOver) {
        printBoard(board);

        int r, c;
        cout << "Enter row and column to reveal: ";
        cin >> r >> c;

        // 输入合法性检查
        if (r < 0 || r >= BOARD_HEIGHT || c < 0 || c >= BOARD_WIDTH || board[r][c].isRevealed) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // 踩到雷
        if (board[r][c].isMine) {
            gameOver = true;
            cout << "You hit a mine! GAME OVER." << endl;
            printBoard(board, true); // 显示所有雷
        } else {
            revealCell(board, r, c);
            if (checkWin(board)) {
                gameOver = true;
                cout << "Congratulations! You've cleared all the mines!" << endl;
                printBoard(board, true);
            }
        }
    }

    return 0;
}