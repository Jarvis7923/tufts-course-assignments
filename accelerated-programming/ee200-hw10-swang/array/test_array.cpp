#include "array.h"
#include <cstdio>
#include <iostream>

using namespace std;


void test_constructor() {
    cout << "1. test constructor" << endl;
    Array<int>* a1 = new Array<int>();
    cout << "default `Array<int>* a1 = new Array<int>()`:  "<< *a1 << endl;

    Array<int> a2;
    cout << "default `Array<int> a2`:  "<< a2 << endl;

    Array<int>* b1 = new Array<int>(4, 1);
    cout << "length and value `Array<int>* b1 = new Array<int>(4, 1)` " << *b1 << endl;

    Array<int> b2(4, 1);
    cout << "length and value `Array<int> b2(4, 1)` " << b2 << endl;

    int list[] = {1,2,3,4,5};
    Array<int>* c1 = new Array<int>(5, list);
    cout << "length and values `Array<int>* c1 = new Array<int>(5, list);` " << *c1 << endl;

    Array<int> c2(5, list);
    cout << "length and values `Array<int> c2(5, list)` " << c2 << endl;

    Array<int>* d1 = new Array<int>(c2);
    cout << "copy `Array<int>* d1 = new Array<int>(c2);` " << *d1 << endl;

    Array<int> d2(c2);
    cout << "copy `Array<int> d2(c2)` " << d2 << endl;

    c2[1] = 100; 
    cout << "after change c2[1]="<< c2[1] << ", d2=" << d2 << endl;

    Array<Array<int> >  e2(2, d2);
    cout << "length and values `Array<Array<int> >e2(2, d2)` " << e2 << endl;
    delete a1;
    delete b1;
    delete c1;
    delete d1;
}


void test_assignment() {
    cout << "2. indexing and assigning test" << endl;
    int list[] = {1,2,3,4,5};
    Array<int> a(5, list);
    cout << "before " << a << endl;
    cout << "a[2] = " << a[2] << endl;
    for (int i=0; i<5; i++) {
        a[i] = 10;
    }
    cout << "after " << a << endl;
}

void test_operation() {
    cout << "3. operation test" << endl;
    int* l1 = NULL;
    int l2[] = {1,2,3};
    int l3[] = {4,5,6};
    Array<int> a0;
    Array<int> a1(0, l1); 
    Array<int> a2(3, l2);
    Array<int> a3(3, l3);

    cout << "a1, a2, a3 = " << a1 << ", " << a2 << ", " << a3 << endl;
    cout << "a1 + a2 + a3 = " << a1 + a2 + a3 << endl;
    a0 = a1 + a2 + a3;
    cout << "a0 = a1 + a2 + a3: " << a0 << endl;
    a0 = a1 + a1 + a1;
    cout << "a0 = a1 + a1 + a1: " << a0 << endl;
}

void test_exception() {
    cout << "4. exception test" << endl;
    int list[] = {1,2,3,4,5};
    Array<int> a(5, list);
    try {
        a[6] = 4;
    }
    catch(exception &e) {
        cout << e.what() << endl;
    }
    try {
        Array<int> b(-1, 0);
    }
    catch(exception &e) {
        cout << e.what() << endl;
    }
}

int main(int argc, char* argv[]) {
    test_constructor();
    test_assignment();
    test_operation();
    test_exception();
    return 0;
}

