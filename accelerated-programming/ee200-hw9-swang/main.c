#include "mon.h"

#include <stdio.h>

void print_ele(Element *e){
    printf("name: %s\n", e->name);
}

int main(int argc, char* argv[]) {
    /* This code should create the tree below:
     *            aardvark
     *             /   \
     *        baboon   zebra
     *        /   \
     * xylophone  yak
     */
    
    Element* a = create_element("aardvark");
    Element* b = create_left(a, "baboon");
    Element* x = create_left(b, "xylophone");
    Element* y = create_right(b, "yak");
    
    Element* z = create_right(a, "zebra");
    

    FILE* fw = fopen("sample.mon", "w");
    write_tree(fw, a);

    // Clean up!
    fclose(fw);
    free_tree(a);
    
    FILE* fr = fopen("sample.mon", "r");
    Element* e = load_tree(fr);

    free_tree(e);
    // Clean up!
    fclose(fr);

}

