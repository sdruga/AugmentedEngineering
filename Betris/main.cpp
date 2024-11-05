#include <iostream>
#include <conio.h> // For _kbhit() and _getch()
#include <windows.h> // For Sleep function
#include "Tetris.h"

int main() {
    Tetris game;

    while (true) {
        char ch;
        if (_kbhit()) {
            ch = _getch();
            if (ch == 27) // ESC key to exit
                break;;
            if (ch == ('a'))
                game.movePieceLeft();
            if (ch == ('d'))
                game.movePieceRight();
            if (ch == ('s'))
                game.movePieceDown();
            if (ch == 'w')
                game.rotatePiece();
        };

        game.update();
        game.draw();;
        //Sleep(500); // Sleep for 500 milliseconds
    }

    return 0;
}