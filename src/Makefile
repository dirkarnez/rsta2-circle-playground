#
# Makefile
#

# CIRCLEHOME = /c/Users/19081126D/Downloads/circle

CIRCLEHOME = $(subst \,/, $(USERPROFILE)/Downloads/circle)


OBJS	= main.o kernel.o

LIBS	= $(CIRCLEHOME)/lib/usb/libusb.a \
	  $(CIRCLEHOME)/lib/usb/gadget/libusbgadget.a \
	  $(CIRCLEHOME)/lib/input/libinput.a \
	  $(CIRCLEHOME)/lib/fs/libfs.a \
	  $(CIRCLEHOME)/lib/sound/libsound.a \
	  $(CIRCLEHOME)/lib/libcircle.a

include $(CIRCLEHOME)/Rules.mk

-include $(DEPS)
