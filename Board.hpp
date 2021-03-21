#pragma once

#include <string>
#include <vector>
#include "Direction.hpp"

namespace ariel {
	typedef unsigned int UI;
	class Board
	{
	public:
		Board();
		~Board();
		void post(UI, UI, ariel::Direction, std::string);
		std::string read(UI, UI, ariel::Direction, UI);
		void show();
	private:
		inline UI get_rows() {return this->_ROWS;}
		inline UI get_cols() {return this->_COLS;}
		inline char **get_board() {return this->_board;}
		
		UI _x, _y, _length, _ROWS, _COLS;
		std::string _msg;
		ariel::Direction _direction;
		char **_board;
	};
}