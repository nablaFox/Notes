LIST_IMPL = move_biggest_smallest
LIST_IMPL_REC = test
LIST_IMPL_CIRC = giuseppe_flavio

ifneq (,$(filter $(DEMO),$(LIST_IMPL)))
IMPL = list
else ifneq (,$(filter $(DEMO),$(LIST_IMPL_CIRC)))
IMPL = list_circ
else ifneq (,$(filter $(DEMO),$(LIST_IMPL_REC)))
IMPL = list_rec
endif

CFLAGS += -include $(DEMOS_PATH)/$(DEMO)/demo_list.hpp

SRC += $(IMPL).cpp

DEMOS = $(LIST_IMPL) $(LIST_IMPL_CIRC) $(LIST_IMPL_REC)

include ../Rules.mk
