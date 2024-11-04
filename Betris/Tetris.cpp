#include "Tetris.h"
#include <iostream>

Tetris::Tetris() {
    board.resize(boardHeight, std::vector<int>(boardWidth, 0));
    spawnNewPiece();
}

void Tetris::update() {
    movePieceDown();
    checkForCompletedLines();
}

void Tetris::draw() {
    system("cls"); // Clear the console
    for (int y = 0; y < boardHeight; ++y) {
        for (int x = 0; x < boardWidth; ++x) {
            if (board[y][x] != 0) {
                std::cout << "#";
            } else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
    currentPiece.draw();
}

void Tetris::movePieceLeft() {
    currentPiece.move(-1, 0);
}

void Tetris::movePieceRight() {
    currentPiece.move(1, 0);
}

void Tetris::movePieceDown() {
    currentPiece.move(0, 1);
}

void Tetris::rotatePiece() {
    currentPiece.rotate();
}

void Tetris::checkForCompletedLines() {
    for (int y = 0; y < boardHeight; ++y) {
        bool lineComplete = true;
        for (int x = 0; x < boardWidth; ++x) {
            if (board[y][x] == 0) {
                lineComplete = false;
                break;
            }
        }
        if (lineComplete) {
            for (int yy = y; yy > 0; --yy) {
                for (int xx = 0; xx < boardWidth; ++xx) {
                    board[yy][xx] = board[yy - 1][xx];
                }
            }
            for (int xx = 0; xx < boardWidth; ++xx) {
                board[0][xx] = 0;
            }
        }
    }
}

void Tetris::spawnNewPiece() {
    currentPiece = Piece();
}