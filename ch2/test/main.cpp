#include "Stack.h"
#include "Queue.h"
#include "StackWithTwoQs.h"
#include <iostream>

// test for task 1, class stack
void test1(){
    std::cout << "----------test1-----------" << std::endl;
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    std::cout << "peek " << st.peek() << std::endl;
    std::cout << "pop " << st.pop() << std::endl;
    std::cout << "size " << st.size() << std::endl;
    std::cout << "pop " << st.pop() << std::endl;
    std::cout << "peek " << st.peek() << std::endl;
    std::cout << "pop " << st.pop() << std::endl;
    std::cout << "size " << st.size() << std::endl;
    std::cout << "pop " << st.pop() << std::endl;
    st.push(1);
    std::cout << "size " << st.size() << std::endl;
    std::cout << "pop " << st.pop() << std::endl;
}

// test of task three, queue implemented by vector
void test3(){
    std::cout << "----------test3-----------" << std::endl;
    Queue<int> que;
    que.enqueue(1);
    que.enqueue(2);
    que.enqueue(3);
    std::cout << "poll " << que.poll() << std::endl;
    std::cout << "dequeue " << que.dequeue() << std::endl;
    std::cout << "size " << que.size() << std::endl;
    std::cout << "dequeue " << que.dequeue() << std::endl;
    std::cout << "poll " << que.poll() << std::endl;
    std::cout << "dequeue " << que.dequeue() << std::endl;
    std::cout << "size " << que.size() << std::endl;
    std::cout << "dequeue " << que.dequeue() << std::endl;
    que.enqueue(1);
    std::cout << "size " << que.size() << std::endl;
    std::cout << "dequeue " << que.dequeue() << std::endl;
}

// test of task 4, stack implemented by two queues
void test4(){
    std::cout << "----------test4-----------" << std::endl;
    StackWithTwoQs<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    std::cout << "peek " << st.peek() << std::endl;
    std::cout << "pop " << st.pop() << std::endl;
    std::cout << "size " << st.size() << std::endl;
    std::cout << "pop " << st.pop() << std::endl;
    std::cout << "peek " << st.peek() << std::endl;
    std::cout << "pop " << st.pop() << std::endl;
    std::cout << "size " << st.size() << std::endl;
    std::cout << "pop " << st.pop() << std::endl;
    st.push(1);
    std::cout << "size " << st.size() << std::endl;
    std::cout << "pop " << st.pop() << std::endl;
}

// implement of task 2
void calculator(std::string input){
    Stack<double> num_st; // stack for numbers
    Stack<char> op_st; // stack for operators
    int temp_num = 0; // calculate value of numbers while iterating
    for (int i = 0; i < input.size(); i++) {
        char ch = input[i];
        if (ch == ' ') {
            // omit space
            continue;
        }
        else if (ch >= '0' && ch <= '9') {
            // calculate numbers
            temp_num *= 10;
            temp_num += ch - '0';
        }
        else if(ch == '*' || ch == '/'){
            // push to stack directly
            num_st.push(temp_num);
            // std::cout << "num: " << temp_num << std::endl;
            temp_num = 0;
            op_st.push(ch);
        }
        else if(ch == '+' || ch == '-'){
            // calculate expression before ch, then push ch to stack
            num_st.push(temp_num);
            temp_num = 0;
            while (op_st.size() != 0){
                char op = op_st.pop();
                double num2 = num_st.pop();
                double num1 = num_st.pop();
                if (op == '/' && num2 == 0){
                    // invalid expression
                    std::cout << "NaN\n";
                    return;
                }
                if (op == '/'){
                    num1 = num1 * 1.0 / num2;
                }
                else if (op == '*'){
                    num1 *= num2;
                }
                else if (op == '+'){
                    num1 += num2;
                }
                else{
                    num1 -= num2;
                }
                num_st.push(num1);
            }
            op_st.push(ch);
        }
        else{
            // invalid character
            std::cout << "NaN\n";
            return;
        }
    }

    // push the last number to stack, then calculate the rest of expression
    num_st.push(temp_num);
    while (op_st.size() != 0){
        char op = op_st.pop();
        double num2 = num_st.pop();
        double num1 = num_st.pop();
        if (op == '/' && num2 == 0){
            // invalid expression
            std::cout << "NaN\n";
            return;
        }
        if (op == '/'){
            num1 = num1 * 1.0 / num2;
        }
        else if (op == '*'){
            num1 *= num2;
        }
        else if (op == '+'){
            num1 += num2;
        }
        else{
            num1 -= num2;
        }
        num_st.push(num1);
    }

    std::cout << num_st.pop() << std::endl;
}

// test of task2
int test2() {
    std::cout << "----------test2-----------" << std::endl;
    std::string input1 = "10 - 10 + 10 / 10";
    calculator(input1);

    std::string input2 = "30/30 + 1";
    calculator(input2);

    std::string input3 = "foo / 30 + 7";
    calculator(input3);

    std::string input4 = "4 + 20 * 3 / 30 - 2";
    calculator(input4);

    std::string input5 = "30 + 20 * 3 / 0 * 5+ 8";
    calculator(input5);

    std::string input6 = "3 - 0 + 1 * 3 + 0 * 5 / 2";
    calculator(input6);
}

int main(){
    test1();
    test2();
    test3();
    test4();
    return 0;
}