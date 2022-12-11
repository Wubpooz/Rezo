#Usages
#make : compiles all .ml
#make clean : remove ALL binaries and .cmo

.PHONY : all clean

#Compiler
CP = gcc
CFLAGS =

#Linker
LD = gcc
LDFLAGS =

#Cleaner (can specify a dir in which bin would be created)
RM = rm -rvf

#Executable files retriving
SRCS := $(wildcard *.c)
BINS := $(SRCS:%.c=%)

all: clean $(BINS)

%: %.o
	$(LD) $(LDFLAGS) -o $@ $<

%.o: %.c
	@echo "Creating object files..."
	$(CP) $(CFLAGS) -c $<


clean:
	@echo "Cleaning up..."
	$(RM) $(BINS)
