//
// Created by c on 17.03.2022.
//

#ifndef SAPPER_MINESWEEPERBOARD_H
#define SAPPER_MINESWEEPERBOARD_H

struct Field{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

enum GameMode { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS};

class MinesweeperBoard {
    Field board[100][100];
    int width;
    int height;
    int countOfMines;
    int countRevealField;
    bool first_action;
    GameMode gmode;
    GameState state;
    void clear_board();
    void create_mine();

public:
    MinesweeperBoard(int w, int h);
    void debug_display() const;
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    bool isRevealed(int row, int col) const;
    bool inBoard(int row, int col) const;
    int countMines(int row, int col) const;
    bool hasFlag(int row, int col) const;
    void toggleFlag(int row, int col);
    void revealField(int row, int col);
    GameState getGameState() const;
    char getFieldInfo(int row, int col) const;
    bool getHasMine(int row, int col) const;
    void chcekAroud(int row,int col);
    void setSize(int swidth, int sheight);
    void startGame();
    void setGameMode(GameMode mode);
    GameMode getGameMode() const;
    int getCountRevealField() const;
    int getCountOfMines() const;
};


#endif //SAPPER_MINESWEEPERBOARD_H
