# tool
CXX = g++
CFLAGS = -std=c++20 -Wall -Wextra -Wpedantic

# paths
BIN_PATH = bin
DEMOS_PATH = demos

# user choice of implementation
ifndef IMPL
	IMPL = lists.cpp
endif
IMPL_FILE = $(filter-out $(IMPL), lists.cpp lists_rec.cpp)

# user choice of demo
ifndef DEMO
  DEMO_SRC = $(wildcard $(DEMOS_PATH)/basic.cpp)
else ifeq ($(wildcard $(DEMOS_PATH)/$(DEMO)/*),) 
  DEMO_SRC = $(wildcard $(DEMOS_PATH)/$(DEMO).cpp)
else
  DEMO_SRC = $(wildcard $(DEMOS_PATH)/$(DEMO)/*.cpp) 
endif

# files
BIN = $(BIN_PATH)/test
SRC = $(filter-out $(IMPL_FILE), $(wildcard *.cpp)) $(DEMO_SRC) 
OBJ = $(SRC:.cpp=.o)

# rules
.PHONY: all clean

all: demo run clean

demo: $(OBJ)
	mkdir -p $(BIN_PATH)
	$(CXX) -o $(BIN) $^ 

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

run:
	[ -f $(BIN) ] || make test IMPL=$(IMPL)
	./$(BIN)

clean:
	rm -rf $(OBJ) $(BIN_PATH)
