#ifndef FUNCTIONS_HPP_INCLUDED
#define FUNCTIONS_HPP_INCLUDED

#include <iostream>
#include "card.hpp"

static bool sort_ByValue(card &lhs, card &rhs) { return lhs.getValue() < rhs.getValue(); };

#endif // FUNCTIONS_HPP_INCLUDED
