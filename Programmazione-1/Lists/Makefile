# tool
CXX = g++
CFLAGS = -std=c++20 -Wall -Wextra -Wpedantic

# paths
BIN_PATH = bin
DEMOS_PATH = demos

# user choice of implementation
ifndef IMPL
	IMPL = list
endif

# user choice of demo
ifndef DEMO
	DEMO = test
endif

CFLAGS += -include $(DEMOS_PATH)/$(DEMO)/demo_list.hpp

# files
BIN = $(BIN_PATH)/$(DEMO)
SRC = $(IMPL).cpp $(DEMO_SRC) 
DEMO_SRC = $(wildcard $(DEMOS_PATH)/$(DEMO)/*.cpp)
OBJ = $(SRC:.cpp=.o)

# rules
.PHONY: all clean

all: clean demo

demo: $(OBJ)
	mkdir -p $(BIN_PATH)
	$(CXX) -o $(BIN) $^ 

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

run:
	./$(BIN)

clean:
	rm -rf $(OBJ) $(BIN_PATH) *.o
