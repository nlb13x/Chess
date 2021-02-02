# Chess

# CS246-Chess

## Running the binary file 
If you have XQuartz installed, run xterm from it by going to Applications->Terminal on MacOS

Then run the the command ./chess in your xterm

## Inputs for the program
A brief summary of commands that the executable file ./chess can read are:

- `game white-player black-player` starts a new game. The variables `white-player` and
`black-player` can be either human or computer[1-4], where 1-4 sets the computer level to play with
For e.g, the input `game john computer1` will make john the white-player and computer1 the black-player
- `resign` concedes the game to your opponent. This is the only way, outside of winning or
drawing the game, to end a game.
- To move a piece, type `move` followed by the starting and ending coordinates of
the piece to be moved. For example: `move e2 e4` Castling would specified by the two-
square move for the king: `move e1 g1` or `move e1 c1` for white. Pawn promotion would
additionally specify the piece type to which the pawn is promoted: `move e7 e8 Q`.
- `setup` enters setup mode, within which you can set up your own initial board configurations.
This can only be done when a game is not currently running. Within setup mode, the
following language is used:
  - `K e1` places the piece K (i.e., white king in this case) on the square e1. If a piece is
already on that square, it is replaced. The board should be redisplayed.
  - e1 removes the piece from the square e1 and then redisplays the board. If there is no
piece at that square, take no action.
  - `= colour` makes it colour's turn to go next.
  - `done` leaves setup mode.
- `history` prints the past moves of the board


## LET THE GAME BEGIN
