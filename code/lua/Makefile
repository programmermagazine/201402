CC=gcc
OBJS0=lapi.o lcode.o lctype.o ldebug.o ldo.o ldump.o lfunc.o lgc.o llex.o lmem.o lobject.o lopcodes.o lparser.o lstate.o lstring.o ltable.o ltm.o lundump.o lvm.o lzio.o
OBJS= $(OBJS0) lua.o lauxlib.o lbaselib.o lbitlib.o lcorolib.o ldblib.o liolib.o lmathlib.o loslib.o lstrlib.o ltablib.o loadlib.o linit.o
OBJS2= $(OBJS0) luac.o lauxlib.o

MYOBJS= $(OBJS0) myLua.o lauxlib.o lbaselib.o lbitlib.o lcorolib.o ldblib.o liolib.o lmathlib.o loslib.o lstrlib.o ltablib.o loadlib.o linit.o


CFLAGS= -Wall -O2

T= lua

all:	$T luac
	./$T test.lua
	./luac -l test.lua

$T:	$(OBJS)
	$(CC) -o $@ $(OBJS) -lm

luac:	$(OBJS2)
	$(CC) -o $@ $(OBJS2) -lm

myLua:	$(MYOBJS)
	$(CC) -o $@ $(MYOBJS) -lm
	
clean:
	rm -f $T $(OBJS) $(OBJS2) core core.* luac.out luac

diff:
	diff ORIG . | grep -v ^Only > DIFFS
