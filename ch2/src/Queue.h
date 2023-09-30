#pragma once
#include <iostream>
#include <vector>

template <typename T>
class Queue{
    private:
        std::vector<T> vec;
        int front_id = 0;

    public:
        // enqueue element in the queue. 
        void enqueue(T element){ 
            vec.push_back(element);
        }

        // remove and return the earliest element from the queue. 
        T dequeue(){
            if (vec.size() == front_id) {
                std::cerr << "queue is empty!" << std::endl;
                return 0;
            }
            T front = vec[front_id];
            front_id += 1;
            return front;
        }


        // returns the earliest element without removing it.  
        T poll(){
            if (vec.size() == front_id) {
                std::cerr << "queue is empty!" << std::endl;
                return 0;
            }
            T front = vec[front_id];
            return front;
        }

        // returns the size of the queue. 
        int size(){
            return vec.size() - front_id;
        }
};
