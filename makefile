CC=gcc
CFLAGS= -I -g -lstdc++

P0: main.cpp tree.hpp tree.cpp node.hpp
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o main
	rm P0
	rm *.preorder *.inorder *.postorder

