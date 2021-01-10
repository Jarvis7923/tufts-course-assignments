/* mon.h
 * Library of functions for "Minimal object notation" (MON). */

#ifndef MON_H
#define MON_H

#include <stdio.h>

typedef struct element_t {
  char* name;
  struct element_t* left_child;
  struct element_t* right_child;
} Element;


Element* create_element(char* data);
Element* create_left(Element* root, char* data);
Element* create_right(Element* root, char* data);

void free_tree(Element* root);
int write_tree(FILE*, Element* root);
Element* load_tree(FILE* f);

#endif

