CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
HEADER = binary_trees.h
PRINT = binary_tree_print.o
TARGET = 0-node 1-left 2-right 3-del 4-leaf
OBJS ::= $(wildcard *.o)
vpath %-main.c tests/

.PHONY: all clean

all: $(TARGET)

0-node: 0-main.o
1-left: 1-main.o 1-binary_tree_insert_left.o
2-right: 2-main.o
3-del: 3-main.o 3-binary_tree_delete.o
4-leaf: 4-main.o 4-binary_tree_is_leaf.o

0-node 1-left 2-right 3-del 4-leaf: 0-binary_tree_node.o
2-right 3-del 4-leaf: 2-binary_tree_insert_right.o

$(TARGET): $(PRINT)
	$(CC) $(CFLAGS) $^ -o $@
	./$@

clean: 
	rm $(OBJS)
	find . -maxdepth 1 -type f -executable -exec rm {} \;

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
