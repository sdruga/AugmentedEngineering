#ifndef TETRIS_H
#define TETRIS_H

#include <vector>
#include "Piece.h"

class Tetris {
public:
    Tetris();
    void update();
    void draw();
    void movePieceLeft();
    void movePieceRight();
    void movePieceDown();
    void rotatePiece();

private:
    Piece currentPiece;
    std::vector<std::vector<int>> board;
    const int boardWidth = 10;
    const int boardHeight = 20;

    void checkForCompletedLines();
    void spawnNewPiece();
};

#endif