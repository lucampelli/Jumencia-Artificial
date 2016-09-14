##My simple Makefile

ALL=	$(shell find *.cpp)

makefile:
	g++ -o Gomoku $(ALL) -I.

debug:
	g++ -g -fno-inline-functions -o Gomoku $(ALL) -I.

.PHONY: makefile clean

