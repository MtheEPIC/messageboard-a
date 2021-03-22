#include "doctest.h"
#include "Board.hpp"
#include <string.h>

using namespace ariel;
using namespace std;

TEST_CASE("Bad Class Init")
{
	CHECK_THROWS(new Board(0, 0));
	CHECK_THROWS(new Board(1, 0));
	CHECK_THROWS(new Board(0, 1));
}
TEST_CASE("Resize Board")
{
	Board br(1, 1);
	br.post(0, 0, Direction::Horizontal, "hello");
	CHECK(br.get_cols()==7); // if msg>size, new size = (size + size_of(msg) - free space) * 1.5
	br.post(0, 0, Direction::Vertical, "hello");
	CHECK(br.get_rows()==7);
}
TEST_CASE("Post")
{
	Board br;
	CHECK_THROWS(br.post(0, 0, Direction::Horizontal, ""));
	CHECK_THROWS(br.post(0, 0, Direction::Vertical, ""));
	
	Board br2(1, 1);
	CHECK_THROWS(br.post(0, 0, Direction::Horizontal, ""));
	CHECK_THROWS(br.post(0, 0, Direction::Vertical, ""));
}
TEST_CASE("Read")
{
	Board br;
	CHECK_THROWS(br.read(0, 0, Direction::Horizontal, 0));
	CHECK(br.read(0, 0, Direction::Horizontal, 5).size() == 0);
	
	br.post(0, 0, Direction::Horizontal, "string with length of 24");
	CHECK_THROWS(br.read(0, 0, Direction::Horizontal, 0));
	CHECK_THROWS(br.read(0, 0, Direction::Horizontal, 25));
	CHECK(br.read(0, 0, Direction::Horizontal, 24).size() == 24);
	CHECK(br.read(0, 0, Direction::Horizontal, 5).size() == 5);
	
	Board br2;
	CHECK_THROWS(br2.read(0, 0, Direction::Vertical, 0));
	CHECK(br2.read(0, 0, Direction::Vertical, 5).size() == 0);
	
	br2.post(0, 0, Direction::Vertical, "string with length of 24");
	CHECK_THROWS(br2.read(0, 0, Direction::Vertical, 0));
	CHECK_THROWS(br2.read(0, 0, Direction::Vertical, 25));
	CHECK(br2.read(0, 0, Direction::Vertical, 24).size() == 24);
	CHECK(br2.read(0, 0, Direction::Vertical, 5).size() == 5);
}
TEST_CASE("Show")
{
	Board br;
	CHECK(br.show() == "");
	
	br.post(0, 0, Direction::Horizontal, "abc");
	CHECK(br.show() == "abc");
	
	br.post(0, 0, Direction::Vertical, "abc");
	CHECK(br.show() == "abc\nb--\nc--");
	
	br.post(0, 1, Direction::Vertical, "abc");
	br.post(0, 2, Direction::Vertical, "abc");
	CHECK(br.show() == "abc\nbbb\nccc");
	
	br.post(1, 0, Direction::Horizontal, "abc");
	br.post(2, 0, Direction::Horizontal, "abc");
	CHECK(br.show() == "abc\nabc\nabc");
	
	br.post(0, 0, Direction::Horizontal, "123");
	CHECK(br.show() == "123\nabc\nabc");
	
	br.post(0, 0, Direction::Vertical, "123");
	CHECK(br.show() == "123\n2bc\n3bc");
	
	br.post(0, 1, Direction::Vertical, "123");
	br.post(0, 2, Direction::Vertical, "123");
	CHECK(br.show() == "123\n222\n333");
	
	br.post(1, 0, Direction::Horizontal, "123");
	br.post(2, 0, Direction::Horizontal, "123");
	CHECK(br.show() == "123\n123\n123");
	
	Board br1;
	br.post(1, 1, Direction::Horizontal, "abc");
	CHECK(br1.show() == "----\n-abc");
	
	Board br2;
	br2.post(1, 1, Direction::Vertical, "abc");
	CHECK(br2.show() == "--\n-a\n-b\n-c");
}
