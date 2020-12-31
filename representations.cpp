#include "representations.hpp"

#include <algorithm>

using namespace on_sets;

#define args begin(), end(), other.begin(), other.end(), std::inserter(s, s.begin())

card_set card_set::operator|(const card_set &other) const {
	card_set s;
	std::set_union(args);
	return s;
}

card_set card_set::operator&(const card_set &other) const {
	card_set s;
	std::set_intersection(args);
	return s;
}

card_set card_set::operator-(const card_set &other) const {
	card_set s;
	std::set_difference(args);
	return s;
}

card_set card_set::operator^(const card_set &other) const {
	card_set s;
	std::set_symmetric_difference(args);
	return s;
}

card_set card_set::operator~() const {
	return ALL_CARDS - *this;
}

#undef args

symbol_list symbol_list::concat(const symbol_list &other) const {
	symbol_list combined = *this;
	combined.insert(this->end(), other.begin(), other.end());
	return combined;
}

template<typename Func> symbol_list symbol_list::where(Func f) const {
	symbol_list g;
	for (auto ss : *this) {
		if (f(ss)) g.push_back(ss);
	}
	return g;
}

bool is_color(symbol ss) {
	switch (ss) {
		case BLUE:
		case RED:
		case GREEN:
		case YELLOW:
			return true;
		default:
			return false;
	}
}

bool is_universal(symbol ss) {
	switch (ss) {
		case UNIVERSE:
		case EMPTYSET:
			return true;
		default:
			return false;
	}
}

bool is_operator(symbol ss) {
	switch (ss) {
		case AND:
		case OR:
		case MINUS:
		case NOT:
			return true;
		default:
			return false;
	}
}

bool is_restriction(symbol ss) {
	switch (ss) {
		case EQUALS:
		case SUBSET:
			return true;
		default:
			return false;
	}
}
