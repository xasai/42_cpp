#TODO CC compilation 
#Take objdirs from sources dirs and mkdir them
#Make debug build in different folder
#Generate .d files and include them
BIN := brain 

SRC := main.cpp
SRC ?= $(wildcard *.cpp) #FIXME

SRCDIR := ./
SRCDIR ?= src/ #FIXME

OBJPATH := .obj/
OBJ := $(addprefix $(OBJPATH), $(SRC:.cpp=.o))

INC := -I.
INC ?= -Iinclude/ #FIXME

CXX := clang++
CXXFLAGS := -Wall -Wextra -Werror -pedantic-errors -std=c++98

LDFLAGS := 
LIBS := 

all: CXXFLAGS += -O3
all: $(BIN)

$(BIN): $(OBJPATH) $(OBJ)
	$(CXX) $(OBJ) $(INC) $(CXXFLAGS) -o $@ $(LIBS) $(LDFLAGS)

$(OBJPATH)%.o: %.cpp 
	$(CXX) -c $< $(INC) $(CXXFLAGS) -o $@

$(OBJPATH): 
	mkdir -p $(OBJPATH)

run:
	./$(BIN)

clean:
	rm -rf $(OBJPATH)

fclean: clean
	rm -f $(BIN)	

re: fclean all $(BIN)

debug: CPPFLAGS += -DDEBUG
debug: CXXFLAGS += -g3
debug: $(BIN)
