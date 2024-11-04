#include "Piece.h"
#include <iostream>

Piece::Piece() : x(4), y(0), rotation(0) {
    blocks = {{0, 0}, {1, 0}, {0, 1}, {1, 1}}; // O shape
    updateBlocks();
}

void Piece::draw() {
    for (const auto &block : blocks) {
        std::cout << "Block at (" << x + block.first << ", " << y + block.second << ")\n";
    }
}

void Piece::move(int dx, int dy) {
    x += dx;
    y += dy;
    updateBlocks();
}

void Piece::rotate() {
    rotation = (rotation + 1) % 4;
    updateBlocks();
}

void Piece::updateBlocks() {
    // Update block positions based on rotation and position
    // This is a simplified example, you can add more shapes and rotations
}