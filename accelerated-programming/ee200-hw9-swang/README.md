# Resources
You should fill in this section with the resources that you used to develop your code.  You don't need to include the teaching staff or the textbook, but you should list anyone you worked with, and any online or paper resources you used.

Ref:
    Unix mannual 

Discussion:
    Discussed with Ruoxi Ren about load_tree implementation. 


# Overview
This assignment requires writing a group of related functions, which form a simple library.  It combines material from the last few chapters on pointers, recursion, and now `malloc` and `free`.

You don't need to submit a Makefile, but we suggest writing one to make your life easier.

Like previous assignments, you'll need to write you own test code.  To the extent possible, you should test each function individually, rather than in one monolithic test.  This ensures that errors in one function don't get masked by errors in other functions.  For example, one good test might be to write a file out, and then read it back and check that the data matches.  However, you should also check the intermediate files, and perhaps try reading in some hand-written ones to ensure that you haven't accidentally made the same error in both your reading and writing functions.

# Submission
Your code should be pushed to Github, and then you should submit to Gradescope from there.  You will not be able to upload files directly.

# Problem
In this problem, you'll write a library of functions for reading, writing, and manipulating "Minimal Object Notation" (MON).

The basic "object" in MON is the `Element` struct:

    typedef struct element_t {
      char* name;
      struct element_t* left_child;
      struct element_t* right_child;
    } Element;

Since `left_child` and `right_child` are also `Element`s, we can construct trees of Element objects by manipulating pointers appropriately.

You will write the following functions:

## create_element

    Element* create_element(const char* data)

Creates a new Element with the string in `data`, and returns a pointer to the newly-created element.  If `data` is NULL, an element should not be allocated and the function should return NULL.

## create_left

    Element* create_left(Element* root, const char* data)

Creates a new Element with the string in `data`, and adds it as the left child to the Element `root`.  Returns a pointer to the newly-created Element.  If the `root` Element already has a left child, the function should not create a new element, and should return NULL.

## create_right

    Element* create_right(Element* root, const char* data)

Same as `create_left`, but adds the element as a right child instead.

## free_tree

    void free_tree(Element* root)

Frees all of the memory allocated for an Element and all of its children (and their children).

## write_tree

    int write_tree(FILE* f, Element* root)

Writes a tree to a file.  Written formally in [BNF](https://en.wikipedia.org/wiki/Backus%E2%80%93Naur_form#Example), the file format is:

    <File> ::= [<Element>]
    <Element> ::= {<Element><Element><String>} | "NULL "
    <String> ::= Any characters, whitespace, etc., except for '{' and '}'

A sample file is included in the repository, which should help make sense of this formal specification.
The function should return 0 if successful, and a negative number if it failed for some reason.

## read_tree

    Element* load_tree(FILE* f)

Reads a tree from a MON file and creates the appropriate `Element`s.
The return value should be a pointer to the root of the tree (i.e., the top `Element`).  If the file is corrupt, then the function should return NULL.

# Valgrind
Your code must be valgrind-clean.  That is, Valgrind should not report any memory leaks when running your code.
You'll need to be particularly careful when reading a file that turns out to be corrupt.  It is probable that you will have allocated some memory already, and will need to free it before returning to the user.

