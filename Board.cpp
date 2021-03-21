#include "Board.hpp"
#include "Direction.hpp"

#include <iostream>
#include <stdexcept>

using namespace std;
using namespace ariel;

namespace ariel {
	Board::Board()
	{
		
	}
	Board::Board(UI rows, UI cols)
	{
		if (rows == 0 || cols == 0)
		{
			throw std::out_of_range("negative input");
		}
	}
	Board::~Board()
	{
		
	}
	void Board::post(UI x, UI y, Direction dir, std::string msg)
	{
		
	}
	string Board::read(UI x, UI y, ariel::Direction dir, UI length)
	{
		return "";
	}
	string Board::show()
	{
		return "";
	}
}

