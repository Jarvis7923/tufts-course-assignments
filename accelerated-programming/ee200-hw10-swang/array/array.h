#include <iostream>
#include <exception>
#include <cstdio>
#include <cstdlib>

#ifndef ARRAY_H
#define ARRAY_H

using namespace std;

class OutOfBoundsException : public std::exception {
    public: 
        const char * what() const throw () {
            return "index out of bounds";
        }
};

template<typename T>
class Array{

    private: 
        T* array; 
        int length;

    public:
        // default constructor
        explicit Array(): array(NULL), length(0) { }

        /* allocation memory for the array.
           init with NULL array  and 0 length (consider to delete in a try block) 
           if there is no exception thrown in new then update the field length
         */
        void init_mem(int length) throw(std::bad_alloc) {
            this->length = 0;
            this->array = NULL;
            if (length != 0){
                this->array = new T[length];
            }
            this->length = length;
        }

        /* the constructor that will initialize the class with value.  
         */
        Array (int length, T value) throw(std::bad_alloc) {
            this->init_mem(length); // allocate memory for array with length
            for (int i=0; i<length; i++) {
                this->array[i]=value;
            }
        }

        /* the constructor takes the length and the int array to initialize. 
           assume values contains enough data 
         */
        Array(int length, T* values) throw(std::bad_alloc) {
            if (values == NULL) {
                cout << "null pointer found" << endl; 
                this->init_mem(0);
                return;
            }
            this->init_mem(length); 
            for (int i=0; i<length; i++) {
                this->array[i] = values[i];
            }
        }

        /* the copy constructor 
         */
        Array(const Array<T> &arr) throw(std::bad_alloc) {
            this->init_mem(arr.length);
            for (int i=0; i<arr.length; i++) {
                this->array[i] = (arr.array)[i];
            }
        } 

        /* deconstructor 
         */
        ~Array() {
            if(this->array != NULL) {
                delete[] this->array;
            }
        }

        /* return size of array 
         */
        int size() const {
            return this->length;
        }

        /* apppend one value at the end of the Array. Allocate memory for the empty array
         */ 
        void append(T var) throw(std::bad_alloc) {
            T* new_arr = new T[this->length+1];
            new_arr[this->length] = var;
            if (this->array != NULL) {
                copy(this->array, this->array+this->length, new_arr);
                delete[] this->array; 
            } 
            this->array = new_arr;
            this->length += 1; 
        }

        /* apppend another Array at the end of a Array. If arr is empty then the function will return. Other wise, it will allocate memory for the empty array,
         */
        void append(const Array<T> arr) throw(std::bad_alloc) {
            if (arr.size() == 0) {
                return;
            }
            T* new_arr = new T[this->length+arr.size()];
            for (int i = 0; i < arr.size(); i++){
                new_arr[this->length+i] = arr[i];
            }
            if (this->array != NULL) {
                copy(this->array, this->array+this->length, new_arr);
                delete[] this->array; 
            }
            this->array = new_arr;
            this->length += arr.size(); 
        }
        /* stream 
         */
        friend ostream& operator<< (ostream &out, const Array<T> &arr) {
            out << "["; 
            if(arr.size() > 0) {
                for(int i = 0; i<arr.size()-1; i++) {
                    out << arr.array[i] << ", ";
                }
                out << arr[arr.size()-1];
            }
            out << "]";
            return out;
        }

        /* indexing operator
         */
        T& operator[](int i) const throw(OutOfBoundsException) {
            if (i < this->length && i >= 0) {
                return this->array[i];
            }
            else {
                throw OutOfBoundsException();
            }
        }

        /* overwrite the assignment operator
         */
        Array& operator=(const Array<T> rhs) throw(std::bad_alloc) {
            T* new_arr = NULL;
            if (rhs.length != 0) {
                new_arr = new T[rhs.length];
                copy(rhs.array, rhs.array+rhs.length, new_arr);
            }
            if (this->array != NULL) {
                delete[] this->array;
            }
            this->array = new_arr;
            this->length = rhs.length;
            return *this;
        }

        /* overwirte plus operator 
         */
        Array operator+(const Array<T> &rhs) throw(std::bad_alloc) {
            Array arr(*this);
            arr.append(rhs);
            return arr;
        }

};


#endif
