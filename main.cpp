#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <Board.h>


int main(int argc, char *argv[])
{
	QApplication app(argc, argv);



	// create a game of pacman
	Board* board = new Board();
	//	board.setGeometry(0, 0, BOARD_X, BOARD_Y + CELL_LENGTH * 3);
	board->show();

	return app.exec();
}