#ifndef queue_hpp
#define queue_hpp

#include <iostream>
#include <string>
using namespace std;

struct Node{
    string data;
    Node* next;
};

struct Queue{
    Node* head;
    Node* tail;
    int length;
};

void initQueue(Queue &q){
    q.head = nullptr;
    q.tail = nullptr;
    q.length = 0;
}

bool isEmpty(Queue &q){
    return (q.head == nullptr);
}

void enqueue(Queue &q, string value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if(isEmpty(q)){
        q.head = q.tail = newNode;
    }else{
        q.tail->next = newNode;
        q.tail = newNode;
    }

    q.length++;
    cout << "Added: " << value << endl;
}

void dequeue(Queue &q){
    if(isEmpty(q)){
        cout << "Queue is empty. Nothing to remove.\n";
        return;
    }

    Node* temp = q.head;
    cout << "Removed: " << temp->data << endl;

    q.head = q.head->next;
    if(q.head == nullptr){
        q.tail = nullptr;
    }

    delete temp;
    q.length--;
}

void peek(Queue &q){
    if(isEmpty(q)){
        cout << "Queue is empty.\n";
    }else{
        cout << "Front of queue: " << q.head->data << endl;
    }
}

void display(Queue &q){
    if(isEmpty(q)){
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Queue items:\n";
    Node* current = q.head;
    while(current != nullptr){
        cout << " - " << current->data << endl;
        current = current->next;
    }
}

void freeQueue(Queue &q){
    while(!isEmpty(q)){
        dequeue(q);
    }
}

#endif