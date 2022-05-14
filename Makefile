APP_NAME = chessviz
LIB_NAME = libchessviz
SOURCE=src/chessviz/
LIBSOURCE=src/libchessviz/
OBJLIB=obj/src/libchessviz/
OBJCHESS=obj/src/chessviz/

CC = gcc -c
CFLAGS = -Wall -Werror
INCLUDEPATH = -I src

all: bin/chessviz

obj/src/libchessviz/Mate.o: $(LIBSOURCE)Mate.c
	$(CC) $(INCLUDEPATH) $< -o $@
obj/src/libchessviz/InputVar.o: $(LIBSOURCE)InputVar.c
	$(CC) $(INCLUDEPATH) $< -o $@
obj/src/libchessviz/MoveBlack.o: $(LIBSOURCE)MoveBlack.c
	$(CC) $(INCLUDEPATH) $< -o $@
obj/src/libchessviz/MoveWhite.o: $(LIBSOURCE)MoveWhite.c
	$(CC) $(INCLUDEPATH) $< -o $@
obj/src/libchessviz/PrintCB.o: $(LIBSOURCE)PrintCB.c
	$(CC) $(INCLUDEPATH) $< -o $@	
obj/src/chessviz/chess.o: $(SOURCE)chess.c
	$(CC) $(INCLUDEPATH) $< -o $@
obj/src/libchessviz/Check.o: $(LIBSOURCE)Check.c
	$(CC) $(INCLUDEPATH) $< -o $@

obj/src/libchessviz/libchessviz.a: $(OBJLIB)Mate.o $(OBJLIB)InputVar.o $(OBJLIB)MoveBlack.o $(OBJLIB)MoveWhite.o $(OBJLIB)PrintCB.o $(OBJLIB)Check.o
	ar rcs $@ $^

bin/chessviz: $(OBJCHESS)chess.o $(OBJLIB)libchessviz.a 
	gcc $(CFLAGS) $(INCLUDEPATH) $^ -o $@
run:
	./bin/chessviz
clean:
	rm -f $(OBJLIB)*.[oa]
	rm -f $(OBJCHESS)*.o
