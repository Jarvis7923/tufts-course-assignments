#include <iostream>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<typename T>
class LinkedList{
    // You'll need to fill in the function declarations here, since writing them
    // correctly is half the challenge of some of these functions.  Be careful to
    // give them the same names as specified in the README, and pay special
    // attention to things which should be const, references, or both.

    // Note that if your function declarations are incorrect, the autograder will
    // fail to compile.  We'll make sure the autograder is at least able to test
    // compiling your code before the submission deadline.
    private:
        class Node {
            public: 
                T data;
                Node* next;

                Node();
                Node(T data);
                ~Node();
        };
        Node* dummy;
        int length;

    public:
        LinkedList();
        LinkedList(int length, T* values);
        LinkedList(LinkedList& l);

        ~LinkedList();

        int size();

        T getItem(int pos);

        void insert(T x,int pos);
        void remove(int pos);

        LinkedList& operator=(const LinkedList<T> rhs); 

};

template<typename T>
LinkedList<T>::Node::Node(T x) {
    this->data = x;
    this->next = NULL;
};
template<typename T>
LinkedList<T>::Node::Node(): next(NULL) { };

template<typename T>
LinkedList<T>::Node::~Node() { };

template<typename T>
LinkedList<T>::LinkedList():  dummy(new Node()), length(0) { };


template<typename T>
LinkedList<T>::LinkedList(int length, T* values): dummy(new Node()) , length(0) {
    if (values == NULL) {
        // throw some exception
    }
    if (length == 0) {
        return;    
    }
    this->dummy = Node();
    Node* cur = this->dummy;
    for (int i=0; i<length; i++) {
        cur->next = new Node(*(values+i));
        cur = cur->next;
    }
};


template<typename T>
LinkedList<T>::LinkedList(LinkedList& l): dummy(new Node()), length(0) {
    Node* cur = this->dummy;
    Node* lcur = l.dummy;
    for (int i=0; i<l.length; i++) {
        cur->next = new Node(lcur->next->data);
        cur = cur->next;
        lcur = lcur->next;
    }
    this->length = l.length;
};


template<typename T>
LinkedList<T>::~LinkedList() {
    Node* c = this->dummy; 
    Node* n = NULL;
    while (c->next != NULL) {
        n = c->next;
        delete c;            
        c = n;
    }
    delete c;            
};

template<typename T>
int LinkedList<T>::size() {
    return this->length;
};

template<typename T>
T LinkedList<T>::getItem(int pos) {
    if (pos >= this->length && pos < 0) {
        // throw some exception
    }
    Node* cur = this->dummy->next;
    for(int i=0; i<pos; i++) {
        cur = cur->next;
    }
    return cur->data;
};

template<typename T>
void LinkedList<T>::insert(T x, int pos) {
    if (pos >= this->length && pos < 0) {
        // throw some exception
    }
    Node* cur = this->dummy;
    for (int i=0; i<pos; i++) {
        cur = cur->next;   
    }
    Node* n = cur->next;
    cur->next = new Node(x);
    cur->next->next = n;
    this->length++;
};

template<typename T>
void LinkedList<T>::remove(int pos) {
    if (pos >= this->length && pos < 0) {
        // throw some exception
    }
    Node* cur = this->dummy;
    for (int i=0; i<pos; i++) {
        cur = cur->next;   
    }
    Node* n = cur->next;
    cur->next = n->next;
    delete n;
    this->length--;
};

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> rhs) {
    Node* c = this->dummy; 
    Node* n = NULL;
    while (c->next != NULL) {
        n = c->next;
        delete c;            
        c = n;
    }
    delete c;         
    this->dummy = new Node();
    Node* cur = this->dummy;
    Node* rhs_cur = rhs.dummy;
    for (int i=0; i<rhs.length; i++) {
        cur->next = new Node(rhs_cur->next->data);
        cur = cur->next;
        rhs_cur = rhs_cur->next;
    }
    this->length = rhs.length;
    return *this;
}; 


#endif
