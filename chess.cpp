#include "chess.h"


Square::Square()
{
	piece = EMPTY;
	color = NONE;
}
//
void Square::setSpace(Square* space)
{
	color = space->getColor();
	piece = space->getPiece();
}

void Square::setEmpty()
{
	color = NONE;
	piece = EMPTY;
}

Piece Square::getPiece()
{
	return piece;
}

Color Square::getColor()
{
	return color;
}

void Square::setPieceAndColor(Piece p, Color c)
{
	piece = p;
	color = c;

}


void Board::printBoard() {
	using namespace std;
	cout << "   y: 0  1  2  3  4     " << endl << "x:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << " " << i << "   ";
		for (int j = 0; j < 5; j++)
		{
			Piece p = square[i][j].getPiece();
			Color c = square[i][j].getColor();

			switch (p)
			{

			case PAWN: (c == WHITE) ? cout << " P " : cout << " p ";
				break;
			case EMPTY: cout << " " << "\21" << " ";
				break;
			default: cout << "XXX";
				break;
			}

		}
		cout << endl;
	}

}

bool Board::doMove() {
	using namespace std;
	string move;
	int x1, x2, y1, y2;
	bool stop = false;
	while (!stop)
	{
		(turn == WHITE) ? cout << "White's turn" << endl : cout << "Black's turn" << endl;
		cout << "Type in your move as a single four character string. Use x-coordinates first in each pair." << endl;
		cin >> move;
		x1 = move[0] - 48;
		y1 = move[1] - 48;
		x2 = move[2] - 48;
		y2 = move[3] - 48;
		if (getSquare(x1, y1)->getColor() == turn)
		{


			if (makeMove(x1, y1, x2, y2) == false)
			{
				cout << "Invalid move, try again." << endl;
			}
			else
				stop = true;
		}
		else
			cout << "That's not your piece. Try again." << endl;
	}
// 	if (getSquare(x2, y2)->getPiece() == KING)
		if (getSquare(x1, y1)->getColor() == WHITE)
		{
			cout << "WHITE WINS" << endl;
			return false;
		}
		else

		{
			cout << "BLACK WINS" << endl;
			return false;
		}


	if (turn == BLACK)
		turn = WHITE;
	else
		turn = BLACK;

	return true;

}

void Board::setBoard()
{

	square[0][0].setPieceAndColor(PAWN, WHITE);

square[1][0].setPieceAndColor(PAWN, WHITE);
	square[2][0].setPieceAndColor(PAWN, WHITE);
	square[4][0].setPieceAndColor(PAWN, WHITE);
	square[3][0].setPieceAndColor(PAWN, WHITE);

	

	square[0][4].setPieceAndColor(PAWN, BLACK);
	square[1][4].setPieceAndColor(PAWN, BLACK);
	square[2][4].setPieceAndColor(PAWN, BLACK);
	square[3][4].setPieceAndColor(PAWN, BLACK);
	square[4][4].setPieceAndColor(PAWN, BLACK);


	for (int i = 0; i < 5; i++)
	{
		square[i][1].setPieceAndColor(PAWN, WHITE);
		square[i][6].setPieceAndColor(PAWN, BLACK);

	}
	for (int i = 2; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
			square[j][i].setPieceAndColor(EMPTY, NONE);

	}
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			square[i][j].setX(i);
			square[i][j].setY(j);
		}

}

bool Board::playGame()
{
	system("cls");
	printBoard();
	return doMove();

}



bool Board::movePawn(Square* thisPawn, Square* thatSpace) {
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	using namespace std;
	bool invalid = false;
	int pawnX = thisPawn->getX();
	int pawnY = thisPawn->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();


	if (thisPawn->getColor() == WHITE)
	{

		if (pawnX == thatX && thatY == pawnY + 1 && thatSpace->getColor() == NONE)
		{
			thatSpace->setSpace(thisPawn);
			thisPawn->setEmpty();
			return true;
		}
		else
			if ((pawnX + 1 == thatX || pawnX - 1 == thatX) && pawnY + 1 == thatY  && thatSpace->getColor() == BLACK)
			{
				thatSpace->setSpace(thisPawn);
				thisPawn->setEmpty();
				return true;
			}
			else
				return false;
	}
	else
		if (thisPawn->getColor() == BLACK)
		{
			if (pawnX == thatX && thatY == pawnY - 1 && thatSpace->getColor() == NONE)
			{
				thatSpace->setSpace(thisPawn);
				thisPawn->setEmpty();
				return true;
			}
			else
				if ((pawnX + 1 == thatX || pawnX - 1 == thatX) && pawnY - 1 == thatY  && thatSpace->getColor() == WHITE)
				{
					thatSpace->setSpace(thisPawn);
					thisPawn->setEmpty();
					return true;
				}
				else
					return false;
		}
		else
			return false;
}
bool Board::makeMove(int x1, int y1, int x2, int y2) {
	//Checking for turns will be done previous to this
	using namespace std;
	if (x1 < 0 || x1>4 || y1 < 0 || y1>4 || x2 < 0 || x2>4 || y2 < 0 || y2>5)
	{
		std::cout << "One of your inputs was our of bounds" << std::endl;
		return false;
	}
	Square* src = getSquare(x1, y1);
	Square* dest = getSquare(x2, y2);

	if (src->getColor() == dest->getColor() && dest->getColor() != NONE)
	{
		std::cout << "Invalid move: cannot land on your own piece" << std::endl;
		return false;
	}

	switch (src->getPiece())
	{

	case PAWN: return movePawn(src, dest);
		break;
	case EMPTY: std::cout << "You do not have a piece there" << std::endl;  return false;
		break;
	default: std::cerr << "Something went wrong in the switch statement in makeMove()" << std::endl;
		break;
	}
	return false;
}
