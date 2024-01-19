TREE_IMPL = test

ifneq (,$(filter $(DEMO),$(TREE_IMPL)))
IMPL = tree
endif

CFLAGS += -include $(DEMOS_PATH)/$(DEMO)/demo_tree.hpp
CFLAGS += -include $(IMPL).hpp

SRC += $(IMPL).cpp

DEMOS = $(TREE_IMPL)

include ../Rules.mk
