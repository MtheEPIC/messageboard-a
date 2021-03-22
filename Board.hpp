#pragma once

#include <string>
#include <vector>
#include "Direction.hpp"

namespace ariel {
	typedef unsigned int UI;
	typedef const unsigned int CUI;
	typedef const Direction CDir;
	typedef const std::string Cstr;
	class Board
	{
	public:
		Board();
		Board(CUI, CUI);
		~Board();
		void post(CUI, CUI, CDir, Cstr);
		Cstr read(CUI, CUI, CDir, CUI);
		/*void after tests*/ Cstr show();
		
		// public only for tests
		inline UI get_rows() {return this->_ROWS;}
		inline UI get_cols() {return this->_COLS;}
		inline char **get_board() {return this->_board;}
	private:
		UI _ROWS, _COLS;
		char **_board;
	};
}