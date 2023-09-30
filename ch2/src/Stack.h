#include <iostream>
#include <vector>

template <typename T>
class Stack{
    private:
        std::vector<T> vec;

    public:
        // pushes element in the stack. 
        void push(T element){ 
            vec.push_back(element);
        }

        // removes the latest element from the stack and returns it. 
        T pop(){
            if (vec.size() == 0) {
                std::cerr << "stack is empty!" << std::endl;
                return 0;
            }
            T top = vec.back();
            vec.pop_back();
            return top;
        }


        //returns the latest element from the stack without removing it 
        T peek(){
            if (vec.size() == 0) {
                std::cerr << "stack is empty!" << std::endl;
                return 0;
            }
            T top = vec.back();
            return top;
        }

        //returns the size of the stack. 
        int size(){
            return vec.size();
        }
};