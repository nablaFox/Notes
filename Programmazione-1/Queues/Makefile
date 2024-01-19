DEMOS_IMPL = test
DEMOS_IMPL_LIST = 
DEMOS_IMPL_STATIC =

ifneq (,$(filter $(DEMO),$(DEMOS_IMPL)))
IMPL = queue
else ifneq (,$(filter $(DEMO),$(DEMOS_IMPL_LIST)))
IMPL = queue_list
else ifneq (,$(filter $(DEMO),$(DEMOS_IMPL_STATIC)))
IMPL = queue_static
endif

CFLAGS += -include $(DEMOS_PATH)/$(DEMO)/demo_queue.hpp
CFLAGS += -include $(IMPL).hpp

SRC += $(IMPL).cpp

DEMOS = $(DEMOS_IMPL) $(DEMOS_IMPL_LIST) $(DEMOS_IMPL_STATIC)

include ../Rules.mk
