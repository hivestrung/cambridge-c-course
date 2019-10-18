#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <stdbool.h>

List *cons(int head, List *tail) {
  /* malloc() will be explained in the next lecture! */
  List *cell = malloc(sizeof(List));
  cell->head = head;
  cell->tail = tail;
  return cell;
}

/* Functions for you to implement */

int sum(List *list) {
  /* TODO */
  int res = 0;
  List *current = list;
  while (current != NULL) {
      res += current->head;
      current = current->tail;
  }
  return res;
}

void iterate(int (*f)(int), List *list) {
  /* TODO */
  List *current = list;
  while (current != NULL)
  {
      current->head = (*f)(current->head);
      current = current->tail;
  }
}

void print_list(List *list) {
  /* TODO */
  List *current = list;
  printf("[");
  while (current != NULL)
  {
      printf("%d", current->head);
      if (current->tail != NULL)
      {
          printf(", ");
      }
      current = current->tail;

  }
  printf("]\n");
}

/**** CHALLENGE PROBLEMS ****/

List *merge(List *list1, List *list2) {
  /* TODO */
  List *end = cons(0, NULL);
  List *res = end;
  List *l1 = list1;
  List *l2 = list2;
  // walk down l1 and l2
  while (l1 != NULL && l2 != NULL) {
      if (l1->head >= l2->head) {
          end->tail = cons(l2->head, NULL);
          l2 = l2->tail;
      }
      else {
          end->tail = cons(l1->head, NULL);
        //   cur->tail = l1;
          l1 = l1->tail;
      }
      end = end->tail;
  }
//   print_list(end);
//   fflush(stdout);
  end->tail = (l1) ? l1 : l2;

  return res->tail;
}

void split(List *list, List **list1, List **list2) {
  /* TODO */
//   print_list(list);
    *list1 = NULL;
    *list2 = NULL;
  bool first = true;
  while (list != NULL) {
      List *next_cell = (*list).tail;
      if (first) {
          (*list).tail = *list1;
          *list1 = list;
      }
      else {
          (*list).tail = *list2;
          *list2 = list;
      }
      first = !first;
      list = next_cell;
  }
  fflush(stdout);
}

/* You get the mergesort implementation for free. But it won't
   work unless you implement merge() and split() first! */

List *mergesortours(List *list) {
  if (list == NULL || list->tail == NULL) {
      fflush(stdout);
      return list;
  } else {
    //   print_list(list);
    //   fflush(stdout);
      List *list1;
      List *list2;
    //   printf("splitting\n");
      split(list, &list1, &list2);
      list1 = mergesortours(list1);
      list2 = mergesortours(list2);
      return merge(list1, list2);
  }
}
