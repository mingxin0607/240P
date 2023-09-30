#include "Queue.h"
#include <iostream>
#include <vector>

template <typename T>
class StackWithTwoQs{
    private:
        Queue<T> que1;
        Queue<T> que2;

    public:
        // pushes element in the stack. 
        void push(T element){ 
            que1.enqueue(element);
        }

        // removes the latest element from the stack and returns it. 
        T pop(){
            if (que1.size() == 0) {
                std::cerr << "stack is empty!" << std::endl;
                return 0;
            }
            while(que1.size() != 1) {
                que2.enqueue(que1.dequeue());
            }
            T res = que1.dequeue();
            que1 = que2;
            while(que2.size() != 0){
                que2.dequeue();
            }
            return res;
        }


        //returns the latest element from the stack without removing it 
        T peek(){
            if (que1.size() == 0) {
                std::cerr << "stack is empty!" << std::endl;
                return 0;
            }
            while(que1.size() != 1) {
                que2.enqueue(que1.dequeue());
            }
            T res = que1.dequeue();
            que2.enqueue(res);
            que1 = que2;
            while(que2.size() != 0){
                que2.dequeue();
            }
            return res;
        }

        //returns the size of the stack. 
        int size(){
            return que1.size();
        }
};
