#include "mon.h"
#include <string.h>
#include <stdlib.h>

Element* create_element(char* data) {
    // check if data is NULL
    if (data == NULL) return NULL;
    
    Element* p_ele = malloc(sizeof(Element));
    
    // allocate for the name
    char* name = malloc(sizeof(char)*(strlen(data)+1));
    // copy the content of the data to name
    strcpy(name, data);
    name[strlen(data)] = '\0';
    // point the name of the p_ele to name
    p_ele->name = name;
    printf("created %s\n", name);
    p_ele->left_child = NULL;
    p_ele->right_child = NULL;

    return p_ele;
}

Element* create_left(Element* root, char* data) {
    // check if root is NULL
    if (root==NULL) return NULL;
    
    // create if left is NULL
    if (root->left_child == NULL){
        Element* p_ele  = create_element(data);  
        // pointing at newly created ele
        root->left_child = p_ele;
        return p_ele;
    }
    return NULL;
}

Element* create_right(Element* root, char* data) {
    // check if root is NULL
    if (root==NULL) return NULL;
    
    // create if right is NULL
    if (root->right_child == NULL){
        Element* p_ele  = create_element(data);  
        // pointing at newly created ele
        root->right_child = p_ele;
        return p_ele;
    }
    return NULL;
}

void free_tree(Element* root) {
    // if the root element if NULL then return
    if (root==NULL) return;
    
    // check if left child exists
    if (root->left_child != NULL) {
        free_tree(root->left_child);
    }
    // check if right child exists
    if (root->right_child != NULL) {
        free_tree(root->right_child);
    }
    // free the current root and name
    free(root->name);
    free(root);
}


// char* ele_string(Element* root){
//     if (root==NULL) return NULL;
// }

// void add_parentheses(char* src, char** dst){
//     if (src==NULL) return;
//     // allocating memory
//     const int len = strlen(src)+3;
//     char* p = malloc(sizeof(char)*len);
//     // parentheses
//     p[0] = '{';
//     // copy string
//     strcpy(p+1, src);
//     // parentheses
//     p[len-2] = '}'; 
//     // zero terminate
//     p[len-1] = '\0'; 
//     *dst = p;
// }

int concat(char** src1, char* src2) {
    // add the string 2 to the string 1 
    size_t len1 = strlen(*src1);  
    size_t len2 = strlen(src2);
    // allocating memory
    char* p = (char*)malloc(sizeof(char)*(len1+len2+1));
    if (p == NULL) return 0;
    // copy string
    memcpy(p, *src1, len1);
    memcpy(p+len1, src2, len2);
    
    p[len1+len2] = '\0'; // zero terminate
    
    free(*src1);
    *src1 = p;
    return 1;
}


// void concat(char** src1, char* src2){
//     const int len1= sizeof(*src1);
//     const int len2 = sizeof(src2); 
//     
//     *src1 = (char*)realloc(*src1, sizeof(char)*(len1+len2));
//     if (!*src1) printf("fail;\n");
//     strcat(*src1, src2);
//     //  *src1[len1+len2]='\0'; 
// }

int recur_format(Element* e, char** dst){
    
    if (e==NULL) return 0;
    
    if (concat(dst, "{") == 0)
        return 0;
    // check if left child exists
    if (e->left_child != NULL) {
        if (recur_format(e->left_child, dst) == 0) 
            return 0;
    } else {
       if (concat(dst, "NULL ")==0) return 0;
    }

    // check if right child exists
    if (e->right_child != NULL) {
        if (recur_format(e->right_child, dst)==0)
            return 0;
    } else {
        if (concat(dst, "NULL ") == 0)
            return 0;
    }

    if (concat(dst, e->name) == 0)
        return 0;

    if (concat(dst, "}") == 0)
        return 0;
    
    return 1;
}

int write_tree(FILE* f, Element* e) {
    if (f == NULL) return -1;
    // intialize the write string
    char* str = (char*)malloc(sizeof(char)*1);
    *str = '\0';
    
    if (recur_format(e, &str) == 0 ) {
        return -1;
    }
    printf("%s\n", str);
    fprintf(f, "%s", str);
    free(str);
    return 0;
}

Element* parse(char * str, size_t* index){
    
    if (str[*index]=='{') {
        *index = *index + 1;
        Element* re  = parse(str, index);
        Element* le = parse(str, index);
        
        // e->left_child  = parse(str, index);
        // e->right_child = parse(str, index);
        
        int nlen = 1;
        while (str[*index+nlen] != '}'){
           nlen++;
        }
        char* n = (char*)malloc(nlen+1);
        strncpy(n, str+*index, nlen);

        n[nlen] = '\0';
        *index = *index + nlen + 1;
        
        Element *e = create_element(n); 
        free(n);
        e->left_child = le;
        e->right_child = re;
        return e;
    }
    else if (str[*index]=='N') {
        char* n = "NULL ";
        int is_equal = 1;
        for (int i=0; i< 5; i++) {
            if (str[*index+i]!= n[i]) {
                is_equal = 0;
                break;
            }
        }
        if (is_equal) {
            *index = *index + 5;
            return NULL;
        } else {
            // error handling
            printf("not equal!");
            return NULL;  
        }
    }
    // error handling
    else return NULL;
}


Element* load_tree(FILE* f) {
    if (f == NULL) return NULL;
    char * buf = NULL;
    size_t buf_size = 0;
    
    if (getline(&buf, &buf_size, f) <= 0) {
        return NULL;
    }
    
    size_t index = 0; 
    Element *e = parse(buf, &index);
    
    free(buf);

    char* str = (char*)malloc(sizeof(char)*1);
    *str = '\0';
    
    if (recur_format(e, &str) == 0 ) {
        printf("haha error!\n");
    }
    printf("%s\n", str);
    free(str);
    
    return e;
}




