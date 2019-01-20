#pragma once

#define CUR_DIR "assets/"
#define FPS 15

#define CELL_LENGTH 31
#define BOARD_X CELL_LENGTH*29
#define BOARD_Y CELL_LENGTH*32


#define NORMAL_CELL column * CELL_LENGTH, row * CELL_LENGTH, CELL_LENGTH, CELL_LENGTH
#define SMALL_DOT_CELL column * CELL_LENGTH + CELL_LENGTH / 2, row * CELL_LENGTH + CELL_LENGTH / 2, CELL_LENGTH / 6, CELL_LENGTH / 6
#define BIG_DOT_CELL column * CELL_LENGTH + CELL_LENGTH / 2 - CELL_LENGTH / 16, row * CELL_LENGTH + CELL_LENGTH / 2 - CELL_LENGTH / 16, CELL_LENGTH / 3, CELL_LENGTH / 3
#define POSITION  column * CELL_LENGTH, row * CELL_LENGTH

#define CREATURES_POSITION column * CELL_LENGTH, row * CELL_LENGTH
#define CREATURES_CELL CELL_LENGTH

#define SMALL_DOT_THICKNESS 2
#define BIG_DOT_THICKNESS 3
#define BIG_DOT_POINTS 5
#define SMALL_DOT_POINTS 1
#define MAX_SCORE 320

#define EATING_TIME 300

#define UP std::pair<int, int>(0, -1)
#define DOWN std::pair<int, int>(0, 1)
#define RIGHT std::pair<int, int>(1, 0)
#define LEFT std::pair<int, int>(-1, 0)
#define SLOW_DOWN 1
#define PINK_STRATEGY_OFFSET 60

#define ROTATION_LEFT 180
#define ROTATION_RIGHT 0
#define ROTATION_UP 270
#define ROTATION_DOWN 90

#define COUNTER_X_POSITION CELL_LENGTH
#define COUNTER_Y_POSITION CELL_LENGTH*29.2
#define FONT_NAME "times"
#define FONT_SIZE 40

#define RESPAWN 14*CELL_LENGTH, 13*CELL_LENGTH 
#define RESPAWN_TIME 50

#define MODES_BOTH "both"
#define MODES_SPAWN "spawn"
#define MODES_WALLS "walls"

#define PACMAN_IMG_FILE "pacman.png"
#define BLUE_IMG_FILE "blue.png"
#define PINK_IMG_FILE "pink.png"
#define RED_IMG_FILE "red.png"
#define YELLOW_IMG_FILE "yellow.png"
#define GREY_IMG_FILE "grey.png"
#define DEFAULT  "default"

#define LOSE_STRING "You lose!!!  Tap R to restart"
#define WIN_STRING "You won!!!   Tap R to restart"
#define SCORE_STRING QString("Score: ") + QString::number(score) + QString("                    ESC to exit")
