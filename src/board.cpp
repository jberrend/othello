#include "board.h"

board::board() { load_default_board(); }

// create new board instance, copying the board state from the passed board into the new one.
board::board(board& b) {
    for (int x = 0; x < BOARD_WIDTH; x++)
        for (int y = 0; y < BOARD_HEIGHT; y++) {
            board_array[x][y] = b.get_at_position(x, y);
        }
}

void board::load_default_board() {
    for (int x = 0; x < BOARD_WIDTH; x++) {
        for (int y = 0; y < BOARD_HEIGHT; y++) {
            board_array[x][y] = default_board_state[x][y];
        }
    }
}

bool board::place_move(position *pos, space_types player) {
    board_array[pos->x][pos->y] = player;

    return false;
}

space_types board::get_at_position(int x, int y) { return board_array[x][y]; }

space_types board::get_at_position(position pos) { return board_array[pos.x][pos.y]; }
