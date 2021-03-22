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
	Board::Board(CUI rows, CUI cols)
	{
		if (rows == 0 || cols == 0)
		{
			throw std::out_of_range("negative input");
		}
	}
	Board::~Board()
	{
		
	}
	void Board::post(CUI x, CUI y, CDir dir, Cstr msg)
	{
		if (msg.length() == 0)
		{
			throw std::invalid_argument("message must not be empty");
		}
	}
	Cstr Board::read(CUI x, CUI y, CDir dir, CUI length)
	{
		if (length == 0)
		{
			throw std::invalid_argument("length must more then 0");
		}
		switch(dir)
		{
		case Direction::Horizontal:
			if (this->get_cols() < length)
			{
				throw std::out_of_range("length var is to long");
			}
			break;
		case Direction::Vertical:
			if (this->get_rows() < length)
			{
				throw std::out_of_range("length var is to long");
			}
			break;
		}
		return "";
	}
	Cstr Board::show()
	{
		return "";
	}
}

