STACK_IMPL = test
STACK_IMPL_LIST = 
STACK_IMPL_STATIC = 

ifneq (,$(filter $(DEMO),$(STACK_IMPL)))
IMPL = stack
else ifneq (,$(filter $(DEMO),$(STACK_IMPL_STATIC)))
IMPL = stack_static
else ifneq (,$(filter $(DEMO),$(STACK_IMPL_LIST)))
IMPL = stack_list
endif

CFLAGS += -include $(DEMOS_PATH)/$(DEMO)/demo_stack.hpp 
CFLAGS += -include $(IMPL).hpp

SRC += $(IMPL).cpp

DEMOS = $(STACK_IMPL) $(STACK_IMPL_STATIC) $(STACK_IMPL_LIST)

include ../Rules.mk
