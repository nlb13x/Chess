CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = chess
LDFLAGS = -L/opt/X11/lib -lX11
OBJECTS = main.o main_helper.o computer.o board.o textdisplay.o cell.o move.o nopiece.o piece.o king.o queen.o bishop.o rook.o knight.o pawn.o window.o graphicsdisplay.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} ${LDFLAGS}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
