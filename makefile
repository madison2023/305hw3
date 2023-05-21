#define the compiler-executable path
COMPILE = gcc $(COMPILE_SWITCHES)
OFILES = feed.o post.o main.o

feed: $(OFILES)
	$(COMPILE) -o feed $(OFILES)

feed.o: feed.c feed.h post.h
	$(COMPILE) -c feed.c

post.o: post.c post.h
	$(COMPILE) -c post.c

main.o: main.c feed.h post.h
	$(COMPILE) -c main.c

# this defines the command for cleaning up
# all generated files
clean:
	rm -f *.o feed.exe feed
