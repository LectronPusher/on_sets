#pragma once

#include <vector>
#include <set>

namespace on_sets {

enum digit {ONE=1, TWO=2, THREE=3, FOUR=4, FIVE=5};


// binary: 0000, colors: BRGY
enum card {
	BLANK=0b0000,   B=0b1000,   BR=0b1100,   R=0b0100,
	    G=0b0010,  BG=0b1010,  BRG=0b1110,  RG=0b0110,
	   GY=0b0011, BGY=0b1011, BRGY=0b1111, RGY=0b0111,
	    Y=0b0001,  BY=0b1001,  BRY=0b1101,  RY=0b0101
};

class card_set : public std::set<card> {
public:
	using set<card>::set; // yikes the syntax (templated constructor inheritance)
	// set union (OR)
	card_set operator|(const card_set &other) const;
	// set intersection (AND)
	card_set operator&(const card_set &other) const;
	// set difference (MINUS)
	card_set operator-(const card_set &other) const;
	// set symmetric difference
	card_set operator^(const card_set &other) const;
	// set complement (NOT)
	// returns: ALL_CARDS - *this
	card_set operator~() const;
	
}; // card_set

const card_set ALL_CARDS = {
	BLANK, B, BR,  R, G, BG, BRG, RG, GY, BGY, BRGY, RGY, Y, BY, BRY, RY
};
const card_set NO_CARDS;
const card_set BLUE_CARDS =   { B, BR, BG, BRG, BGY, BRGY, BY, BRY };
const card_set RED_CARDS =    { BR, R, BRG, RG, BRGY, RGY, BRY, RY };
const card_set GREEN_CARDS =  { G, BG, BRG, RG, GY, BGY, BRGY, RGY };
const card_set YELLOW_CARDS = { GY, BGY, BRGY, RGY, Y, BY, BRY, RY };

enum symbol {
	BLUE='B', RED='R', GREEN='G', YELLOW='Y', // colors
	UNIVERSE='V', EMPTYSET='0', // universals
	AND='n', OR='U', MINUS='-', NOT='\'', // operators, NOT is an apostrophe
	EQUALS='=', SUBSET='<', // restrictions
};

class symbol_list : public std::vector<symbol> {
public:
	// returns a new symbol_list concatenated to by other
	symbol_list concat(const symbol_list &other) const;
	symbol_list operator+(const symbol_list &other) const { return concat(other); }
	// returns a new symbol_list of the symbols that return true when input to f
	// f must be a functor taking a symbol as input and returning true or false
	// example: symbol_list list_of_colors = my_list.where(&is_color);
	template<typename Func> symbol_list where(Func f) const;
	
}; // symbol_list

// R,B,G,Y
bool is_color(symbol ss);
// UNIVERSE, EMPTYSET
bool is_universal(symbol ss);
// AND, OR, MINUS, NOT
bool is_operator(symbol ss);
// EQUALS, SUBSET
bool is_restriction(symbol ss);

}
