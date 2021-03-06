#
# Templated makefile
#

CC := gcc # This is the main compiler

# CC := clang --analyze # and comment out the linker last line for sanity

SRCDIR := src
BUILDDIR := build
TARGET := bin/runner

SRCEXT := cc
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g # -Wall
LIB := -lncurses
INC := -Iinclude -I/lib/x86_64-linux-gnu





$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# Tests
tester:
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

# Spikes
ticket:
	$(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o bin/ticket

.PHONY: clean




# connect4: $(OBJS)
# 	g++ -o connect4 $(OBJS) -lncurses

# game.o: game.cc board.h engine.h
# 	g++    game.cc -c

# board.o: board.cc board.h
# 	g++  -Wall -Werror board.cc -c

# engine.o: engine.cc engine.h board.h
# 	g++ -Wall -Werror engine.cc -c


# clean:
# 	rm -f *~ *.o connect4
