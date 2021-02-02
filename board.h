#ifndef _BOARD_H_
#define _BOARD_H_

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "textdisplay.h"
#include "observer.h"
#include "subject.h"
#include "color.h"
#include "main_helper.h"
#include "piece.h"
#include "state.h"
#include "cell.h"
#include "king.h"
#include "move.h"
#include "window.h"
#include "graphicsdisplay.h"

class TextDisplay;
template <typename StateType> class Observer;
class Cell;

class Board {
  std::vector<std::vector<Cell>> theBoard;
  TextDisplay *td = nullptr;
  std::vector<std::shared_ptr<Move>> pastMoves;
  Observer<State> *ob = nullptr;
  bool pastCastle = false;
  std::string pastWhat_you_want;
  bool pastEmPassant = false;
  bool white_checkmate = false;
  bool black_checkmate = false;
  bool stalemate = false;
  bool white_check = false;
  bool checkTest = false;
  bool checkmateTest = false;
  bool black_check = false;
protected:
  bool white_human = true;
  bool black_human = true;
public:
  ~Board(); // destructor
  void setObserver(Observer<State> *ob); // sets the observers for each
  void init(); // sets up 8x8 board and responsible for observer pattern
               // clears the old board, if necessary
  void move(std::string pos_initial, std::string pos_final, bool white_turn); // move a piece
  void undo();
  void removePiece_setup(std::string pos); // removes a piece, if nothing, nothing happens
  void removePiece(int row, int col, std::shared_ptr<Move> currMove);
  Color winner(); // white wins -> White, black wins -> Black, draw -> NoColor
  bool gameEnd(); // true if gameover or false otherwise 
  bool setup_valid(); // determines if the current setup mode is valid
  void game_default_setting(); // places the pieces in right pos in default
  void placePiece_setup(std::string piece, std::string pos);
  void placePiece(Piece &piece, int row, int col);
  void swapPiece(int row_0, int col_0, int row_f, int col_f);
  bool canmove(std::string name, int row_0, int col_0, int row_f, int col_f);
  bool canAttack(std::string name, int row_0, int col_0, int row_f, int col_f);
  std::vector<std::vector<Cell>> &get_theBoard();
  bool getwhite_checkmate() const;
  bool getblack_checkmate() const;
  bool getStalemate() const;
  bool getwhite_check() const;
  void setCheckTest(bool test) {this->checkTest = test;}
  bool getCheckTest(){return checkTest;}
  void setCheckMateTest(bool checkmateTest) {this->checkmateTest = checkmateTest;}
  bool getCheckMateTest(){return checkmateTest;}
  void setpastWhat_you_want(std::string str) {this->pastWhat_you_want = str;}
  std::string getpastWhat_you_want(){return pastWhat_you_want;}
  bool getblack_check() const;
  void setwhite_checkmate(bool check);
  void setblack_checkmate(bool check);
  void printHistory(int turn);
  void setStalemate();
  void setwhite_check(bool check);
  void setblack_check(bool check);
  void setPastCastle(bool castle) {this->pastCastle = castle;}
  bool getPastCastle() { return pastCastle; }
  void setPastEmPassant(bool emPassant) {this->pastEmPassant = emPassant;}
  bool getPastEmPassant() { return pastEmPassant; }
  void setHumans(Color color, bool human_player);
  // placePiece() calls move and remove functions
  // placePiece()'s positions are in the users' perspective (be aware of change)
  friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

std::ostream &operator<<(std::ostream &out, const Board &b);

#endif
