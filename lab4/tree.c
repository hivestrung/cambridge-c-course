#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

Tree *empty = NULL;

/* BASE EXERCISE */

int tree_member(int x, Tree *tree) {
  /* TODO */
  // is x in tree?
  // recursively
  if (tree == empty) {
      return 0;
  }
  else if (tree->value == x) {
      return 1;
  }
  else {
      return tree_member(x, tree->left) || tree_member(x, tree->right);
  }
}

Tree *tree_insert(int x, Tree *tree) {
  /* TODO */
  Tree *current = tree;
  if (current == empty) {
      Tree *inserted = malloc(sizeof(Tree));
      (*inserted).right = NULL;
      (*inserted).left = NULL;
      inserted->value = x;
      return inserted;
  }
  else {
      if (x < current->value) {
          (*current).left = tree_insert(x, current->left);
      }
      else {
          (*current).right = tree_insert(x, (*current).right);
      }
      return current;
  }
  return tree;
}

void tree_free(Tree *tree) {
  /* TODO */
  if (tree != NULL) {
      tree->value = 0;
      tree_free(tree->left);
      tree_free(tree->right);
  }
  else {
      return free(tree);
  }
}

/* CHALLENGE EXERCISE */

void pop_minimum(Tree *tree, int *min, Tree **new_tree) {
  /* TODO */

}

Tree *tree_remove(int x, Tree *tree) {
  /* TODO */
  return empty;
}
