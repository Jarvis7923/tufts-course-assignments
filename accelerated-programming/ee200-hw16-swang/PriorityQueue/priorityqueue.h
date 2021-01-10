#include<vector>
#include<stdexcept>
#include<iostream>

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H



template<typename T>
class PriorityQueue{
  // You'll need to fill in the function declarations here, since writing them
  // correctly is half the challenge of some of these functions.  Be careful to
  // give them the same names as specified in the README, and pay special
  // attention to things which should be const, references, or both.

    private:
        // container of the heap element
        std::vector<T> vec; 
        
        // get the index of the 
        // int left_id(int id) { return id*2 + 1 < vec.size() ? id*2 + 1 : -1 ; };
        int left_id(int id) { return id*2 + 1; };
        int right_id(int id) { return id*2 + 2; };
        int parent_id(int id) { return (id-1)/2; };

        // swap the item of index id1 and id2
        void swap(int id1, int id2) {
            check_index(id1);
            check_index(id2);
            T temp = vec[id1]; 
            vec[id1] = vec[id2];
            vec[id2] = temp;
        };

        void check_index(int i) {
            if (i >= size() || i < 0) {
                throw std::out_of_range("index out of range\n");
            }
        }

        int max(int ix, int iy) { 
            check_index(ix);
            check_index(iy);
            return vec[ix] > vec[iy] ? ix : iy; 
        };

    public:
        PriorityQueue():vec(std::vector<T>()) {};

        PriorityQueue(const PriorityQueue & rhs):vec(rhs.vec) { };

        PriorityQueue & operator=(const PriorityQueue *rhs) {
            if(this != &rhs) {
                vec = rhs.vec;
            }
            return *this;
        };

        int size() {return vec.size();};

        T top() { 
            check_index(0);
            return vec[0]; 
        };

        void push(T x) {
            vec.push_back(x);
            int ic = vec.size()-1;
            int ip = parent_id(ic);
            while (ip >= 0 && vec[ip] < vec[ic]) {
                swap(ip, ic);
                ic = ip;
                ip = parent_id(ic);
            }
        };

        void pop() {
            swap(vec.size()-1, 0);
            vec.pop_back();
            int ip = 0;
            int il = left_id(ip);
            int ir = right_id(ip);
            
            if (il >= vec.size()) return;
            int im = ir >= vec.size() ? il : max(ir, il);
            
            while (vec[ip] < vec[im]) {
                swap(ip, im);
                ip = im;
                il = left_id(ip);
                ir = right_id(ip);
                
                if (il >= vec.size()) break;
                im = ir >= vec.size() ? il : max(ir, il);
            }
        };

        // friend std::ostream & operator<<(std::ostream& os, const PriorityQueue& p) {
        //     typename std::vector<T>::iterator ptr;
        //     os << "[";
        //     for (ptr=p.vec.begin();ptr<p.vec.end(); ptr++) {
        //         os << *ptr << " ";
        //     }
        //     os << "]" << std::endl;
        //     return os;
        // };
        ~PriorityQueue() { };
};

#endif
