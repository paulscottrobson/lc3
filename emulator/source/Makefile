ifeq ($(OS),Windows_NT)
include ..\..\documents\common.make
else
include ../../documents/common.make
endif

APPNAME = lc3$(APPSTEM)

SOURCES = 	src$(S)sys_processor.o  framework$(S)main.o framework$(S)gfx.o framework$(S)debugger.o \
			src$(S)sys_debug_lc3.o src$(S)hardware.o
CC = g++

.PHONY: all clean emulator test prebuild

all: emulator
#	.$(S)$(APPNAME) 

run: emulator 
	.$(S)$(APPNAME) filename go

debug: emulator 
	.$(S)$(APPNAME) 
		

emulator: prebuild $(APPNAME)
	$(CCOPY) $(APPNAME) $(BINDIR)
	
prebuild:
	make -C ..$(S)z80
	$(CCOPY) ..$(S)z80$(S)code$(S)*.h cpu

%.o:%.cpp
	$(CC) $(CXXFLAGS) -D INCLUDE_DEBUGGING_SUPPORT -I cpu -I framework -I include -c -o $@ $<

clean:
	$(CDEL) $(APPNAME) 
	$(CDEL) src$(S)*.o 
	$(CDEL) framework$(S)*.o

$(APPNAME): $(SOURCES) include$(S)cpu_support.h
	$(CC) $(SOURCES) $(LDFLAGS) $(SDL_LDFLAGS) -o $@
	

