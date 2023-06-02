CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
HEADER = binary_trees.h
PRINT = binary_tree_print.o
TARGET = 0-node 1-left 2-right 3-del 4-leaf 5-root\
	 6-pre 7-in 8-post 9-height 10-depth 11-size\
	 12-leaves 13-nodes 14-balance 15-full 16-perfect\
	 17-sibling 18-uncle
OBJS ::= $(wildcard *.o)
vpath %-main.c tests/

.PHONY: all clean

all: $(TARGET)

0-node: 0-main.o
1-left: 1-main.o 1-binary_tree_insert_left.o
2-right: 2-main.o
3-del: 3-main.o 3-binary_tree_delete.o
4-leaf: 4-main.o 4-binary_tree_is_leaf.o
5-root: 5-main.o 5-binary_tree_is_root.o
6-pre: 6-main.o 6-binary_tree_preorder.o
7-in: 7-main.o 7-binary_tree_inorder.o
8-post: 8-main.o 8-binary_tree_postorder.o
9-height: 9-main.o 9-binary_tree_height.o
10-depth: 10-main.o 10-binary_tree_depth.o
11-size: 11-main.o 11-binary_tree_size.o
12-leaves: 12-main.o 12-binary_tree_leaves.o
13-nodes: 13-main.o 13-binary_tree_nodes.o
14-balance: 14-main.o 14-binary_tree_balance.o 1-binary_tree_insert_left.o
15-full: 15-main.o 15-binary_tree_is_full.o
16-perfect: 16-main.o 16-binary_tree_is_perfect.o
17-sibling: 17-main.o 17-binary_tree_sibling.o
18-uncle: 18-main.o 18-binary_tree_uncle.o

0-node 1-left 2-right 3-del 4-leaf 5-root 6-pre 7-in 8-post: 0-binary_tree_node.o
9-height 10-depth 11-size 12-leaves 13-nodes 14-balance 15-full: 0-binary_tree_node.o
16-perfect 17-sibling 18-uncle: 0-binary_tree_node.o
2-right 3-del 4-leaf 5-root 9-height 10-depth 11-size 12-leaves: 2-binary_tree_insert_right.o
13-nodes 14-balance 15-full 16-perfect: 2-binary_tree_insert_right.o

$(TARGET): $(PRINT)
	$(CC) $(CFLAGS) $^ -o $@
	./$@

clean: 
	rm $(OBJS)
	find . -maxdepth 1 -type f -executable -exec rm {} \;

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
