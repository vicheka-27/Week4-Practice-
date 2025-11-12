
#define STACK_HPP

#include <vector>
#include<iostream>
#include<string>

template <typename T>
class LinkStack{
    private: 
        struct Node{
            T data;
            Node* next;
            Node(T val, Node* nxt) : data(val), next(nxt) {}


        };
    Node* topNode = nullptr;
    public:
        LinkStack() = default;
        ~LinkStack(){
            while(!empty()){
                pop();
            }
        }
    void push(T value){

        topNode = new Node(value, topNode);
    }

    T pop(){

        if (!empty()){
            Node* temp = topNode;
            T value = temp->data;
             topNode = topNode->next;
            delete temp;
            return value;   
        }
        throw std::out_of_range("Stack is empty");
    }

    T peek() const {
        if (!empty()){
            return topNode->data;
        }        
        throw std::out_of_range("Stack is empty");
    }

    bool empty() const {

        return topNode == nullptr;
    }
};

