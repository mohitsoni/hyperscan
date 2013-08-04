# Makefile

CC = gcc
OBJS = hyperscan.o
TARGET = hyperscan
GCHS = hyperscan.h.gch

SBINDIR = /usr/sbin
BINDIR = /usr/bin
PROGS = hyperscan

RM = rm -f

all:$(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

hyperscan.o: hyperscan.c hyperscan.h
	$(CC) -c hyperscan.c hyperscan.h

install: $(TARGET)
	cp $(PROGS) $(SBINDIR); \

uninstall:
	rm -f $(SBINDIR)/$(PROGS)
	
clean:
	$(RM) $(TARGET) $(OBJS) $(GCHS)
