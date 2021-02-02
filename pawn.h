#ifndef _PAWN_H_
#define _PAWN_H_

#include <vector>
#include <string>
#include <memory>
#include "piece.h"
#include "color.h"
#include "board.h"

class Pawn : public Piece {
	bool readyToUpgrade;
	bool twoStepChance;
	bool movedTwoStepsBefore; // for En Passant
public:
	Pawn(Color color, bool twoStepChance);
	bool gettwoStepChance() const override;
	bool getmovedTwoStepsBefore() const;
	void settwoStepChance();
	void setmovedTwoStepsBefore();
};

#endif
