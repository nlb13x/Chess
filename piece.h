#ifndef _PIECE_H_
#define _PIECE_H_

#include <vector>
#include <memory>
#include <string>
#include "color.h"

class Piece {
	Color color;
	int value;
	// value of the piece [pawn=1, knight,bishop=3, rook=5, queen=9, king=10]
	std::string name;
public:
	Piece(Color color, int value, std::string name); // constructor
	std::string getName() const;
	int getValue() const;
	Color getColor() const;
	virtual bool getCheck() const;
	virtual bool getCastle() const;
	virtual bool gettwoStepChance() const;
	virtual bool getmovedTwoStepsBefore() const;
	virtual void setCastle();
	virtual void setCheck(bool check);
	virtual bool getpawnPromotion() const {}
	virtual void setpawnPromotion(bool value) {}
	virtual void settwoStepChance();
	virtual void setmovedTwoStepsBefore();
};

#endif
