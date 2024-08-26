
OBJS = src/main.o \
	src/subcommands/subcommands.o \
	src/subcommands/build.o \
	src/subcommands/clean.o

all: minbuild

CFLAGS += -Iinclude

.PHONY: all clean
.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

minbuild: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) minbuild
