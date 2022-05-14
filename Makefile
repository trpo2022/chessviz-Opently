APP_NAME = chessviz
LIB_NAME = libchessviz
SOURCE=src/chessviz/
LIBSOURCE=src/libchessviz/
OBJLIB=obj/src/libchessviz/
OBJCHESS=obj/src/chessviz/

CC = gcc -c
CFLAGS = -Wall -Werror
INCLUDEPATH = -I src

test_name = test
test_path = bin/$(test_name)

test_sources = $(shell find test/ -name '*.c')
test_objects = $(test_sources:test/%.cpp=obj/test/%.o)


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
						
.PHONY: test
test: $(test_path)

$(test_path): $(test_objects) $(LIB_PATH)
	gcc -Wall -Wextra -Werror -I src -MP -MMD -I thirdparty /home/opently/chessviz-Opently/src/libchessviz/check_move.c /home/opently/chessviz-Opently/test/mytests.c /home/opently/chessviz-Opently/test/main.c -o bin/test

test_run:
	./bin/test
