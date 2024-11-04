#ifndef PIECE_H
#define PIECE_H

#include <vector>

class Piece {
public:
    Piece();
    void draw();
    void move(int dx, int dy);
    void rotate();

private:
    std::vector<std::pair<int, int>> blocks;
    int x, y;
    int rotation;

    void updateBlocks();
};

#endif