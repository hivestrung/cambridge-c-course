#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

Node *empty = NULL;

Node *node(int value, Node *left, Node *right) { 
  Node *r = malloc(sizeof(Node));
  r->marked = false;
  r->value = value;
  r->left = left;
  r->right = right;
  return r;
}


/* Basic Problems */

int size(Node *node) { 
  /* TODO */
  return 0;
}


void unmark(Node *node) { 
  /* TODO */
}

bool path_from(Node *node1, Node *node2) {
  /* TODO */
  return false;
}

bool cyclic(Node *node) { 
  /* TODO */
  return false;
} 


/* Challenge problems */

void get_nodes(Node *node, Node **dest) { 
  /* TODO */
}

void graph_free(Node *node) { 
  /* TODO */
}


