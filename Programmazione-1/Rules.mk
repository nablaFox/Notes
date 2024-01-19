CXX = g++
CFLAGS += -std=c++20 -Wall -Wextra -Wpedantic

BIN_PATH = bin
DEMOS_PATH = demos

DEMO_SRC = $(wildcard $(DEMOS_PATH)/$(DEMO)/*.cpp)
SRC += $(DEMO_SRC)
BIN = $(BIN_PATH)/$(DEMO)
OBJ = $(SRC:.cpp=.o)

.PHONY: all clean run $(DEMOS)

all: $(DEMOS) 

$(DEMOS): 
	$(MAKE) DEMO=$@ demo

%:
	@$(MAKE) DEMO=$@ demo

demo: $(OBJ)
	mkdir -p $(BIN_PATH)
	$(CXX) -o $(BIN) $^ 

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $(lastword $@)

clean: 
	$(MAKE) clean-$(DEMOS)

clean-%:
	$(MAKE) DEMO=$* clean_demo

clean_demo:
	rm -rf $(BIN_PATH) $(OBJ)

run-%:
	@./$(BIN_PATH)/$*

