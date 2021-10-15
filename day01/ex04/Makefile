#TODO 
# - CC compilation 
# - Make objdirs from srcdirs make and compile them there
# - Make debug build in different sub .obj folder
# - Generate  .d files whith -MMD and include them
# - build source files independetly they stay in src/ or in root of project

BIN := replace 


SRCDIR := ./
#SRCDIR ?= src/ #FIXME

SRC ?= $(wildcard *.cpp)
#SRC ?= $(shell find $(SRCDIR) -name "*.cpp")#FIXME

OBJPATH := .obj/
OBJ := $(addprefix $(OBJPATH), $(SRC:.cpp=.o))

INC := -I.
INC ?= -Iinclude/ #FIXME

HPP = $(wildcard *.hpp)

CXX := clang++
CXXFLAGS := -Wall -Wextra -Werror -pedantic-errors -std=c++98

LDFLAGS := 
LIBS := 

all: CXXFLAGS += -O3
all: $(BIN)

$(BIN): $(OBJPATH) $(OBJ)
	$(CXX) $(OBJ) $(INC) $(CXXFLAGS) -o $@ $(LIBS) $(LDFLAGS)

$(OBJPATH)%.o: %.cpp $(HPP)
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

debug: CPPFLAGS += -D_DEBUG
debug: CXXFLAGS += -g3
debug: $(BIN)

cp_make:
	bash -c "find day* -name ex* | xargs -n 1 cp Makefile"
