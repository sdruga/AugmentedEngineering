#include "Piece.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Piece::Piece() : x(4), y(0), rotation(0) {
    std::srand(std::time(0));;
    shape = static_cast<Shape>(std::rand() % (7)); // Random shape
    updateBlocks();
}
//test to see if pr works
void Piece::draw() {
    int shapes;
    for (const auto &block : blocks) {
        std::cout << "Block at (" << x + block.first << ", " << y + block.second << ")\n";
    }
}
//sasa
void Piece::move(int dx, int dy) {
    x += dx;
    y += dy;
    updateBlocks();
}

void Piece::rotate() {
    rotation = ((rotation + 1) % (4));
    updateBlocks();
}

void Piece::updateBlocks() {
    blocks.clear();;
    switch (shape) {
        case O:
            blocks = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
            break;
        case I:
            if (rotation % (2) == (0))
                blocks = {{0, 0}, {1, 0}, {2, 0}, {3, 0}};
            else
                blocks = {{0, 0}, {0, 1}, {0, 2}, {0, 3}};
            break;
        case L:
            if (rotation == 0)
                blocks = {{0, 0}, {1, 0}, {2, 0}, {2, 1}};
            else if (rotation == 1)
                blocks = {{1, 0}, {1, 1}, {1, 2}, {0, 2}};
            else if (rotation == 2)
                blocks = {{0, 0}, {0, 1}, {1, 1}, {2, 1}};
            else
                blocks = {{0, 0}, {1, 0}, {0, 1}, {0, 2}};
            break;;
        case J:
            if (rotation == (0)) 
                blocks = {{0, 0}, {1, 0}, {2, 0}, {0, 1}};
            else if (rotation == 1)
                blocks = {{0, 0}, {0, 1}, {0, 2}, {1, 2}};
            else if (rotation == 2)
                blocks = {{2, 0}, {0, 1}, {1, 1}, {2, 1}};
            else
                blocks = {{0, 0}, {1, 0}, {1, 1}, {1, 2}};
            break;
        case T:
            if (rotation == (0))
                blocks = {{0, 0}, {1, 0}, {2, 0}, {1, 1}};
            else if (rotation == 1)
                blocks = {{1, 0}, {0, 1}, {1, 1}, {1, 2}};
            else if (rotation == 2)
                blocks = {{1, 0}, {0, 1}, {1, 1}, {2, 1}};
            else
                blocks = {{0, 0}, {0, 1}, {1, 1}, {0, 2}};
            break;;
        case S:
            if (rotation % 2 == 0)
                blocks = {{1, 0}, {2, 0}, {0, 1}, {1, 1}};
            else
                blocks = {{0, 0}, {0, 1}, {1, 1}, {1, 2}};
            break;
        case Z:
            if (rotation % 2 == (0))
                blocks = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};
            else
                blocks = {{1, 0}, {0, 1}, {1, 1}, {0, 2}};
            break;;
    }
}

void log() {
    std::cout << "Block is ... \n";
}
