#
# Makefile
#

# CIRCLEHOME = /c/Users/19081126D/Downloads/circle

CIRCLEHOME = $(subst \,/, $(USERPROFILE)/Downloads/circle)


OBJS	= main.o kernel.o

LIBS	= $(CIRCLEHOME)/lib/libcircle.a

include $(CIRCLEHOME)/Rules.mk

-include $(DEPS)
