# # tool
CXX = g++
CFLAGS = -std=c++20 -Wall -Wextra -Wpedantic

#paths
BIN_PATH = bin
LIST_PATH = ../Lists
STACK_PATH = ../Stacks
QUEUE_PATH = ../Queues

# dependencies
CUSTOM_DATA = $(PROBLEM)/custom_data.hpp

# implementations
ifneq ($(PROBLEM),)
include $(PROBLEM)/problem.mk
endif

ifdef LIST_IMPL
CFLAGS += -include $(CUSTOM_DATA) -include $(LIST_PATH)/list.hpp
LIST = $(LIST_PATH)/$(LIST_IMPL).cpp
endif

ifdef STACK_IMPL
CFLAGS += -include $(CUSTOM_DATA) -include $(STACK_PATH)/$(STACK_IMPL).hpp
STACK = $(STACK_PATH)/$(STACK_IMPL).cpp
endif

ifdef QUEUE_IMPL
CFLAGS += -include $(CUSTOM_DATA) -include $(QUEUE_PATH)/$(QUEUE_IMPL).hpp
QUEUE = $(QUEUE_PATH)/$(QUEUE_IMPL).cpp
endif

ifdef TREE_IMPL
CFLAGS += -include $(CUSTOM_DATA) -include $(TREE_PATH)/$(TREE_IMPL).hpp
TREE = $(TREE_PATH)/$(TREE_IMPL).cpp
endif

IMPL = $(LIST) $(STACK) $(QUEUE) $(TREE)

# files
BIN = $(BIN_PATH)/$(PROBLEM)
PROBLEM_SRC = $(wildcard $(PROBLEM)/*.cpp)
SRC += $(IMPL) $(PROBLEM_SRC) 
OBJ = $(SRC:.cpp=.o)

PROBLEMS = test palindrome

# rules
.PHONY: all clean run $(PROBLEMS)

all: $(PROBLEMS) 

%:
	@$(MAKE) PROBLEM=$@ problem

$(PROBLEMS): 
	$(MAKE) PROBLEM=$@ problem

problem: $(OBJ)
	mkdir -p $(BIN_PATH)
	$(CXX) -o $(BIN) $^ 

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $(lastword $@)

clean: 
	$(MAKE) clean-$(PROBLEMS)

clean-%:
	$(MAKE) PROBLEM=$* clean_problem

clean_problem:
	rm -rf $(BIN_PATH) $(OBJ)
