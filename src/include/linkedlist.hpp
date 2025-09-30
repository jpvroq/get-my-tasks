#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(const T& value) : data(value), next(nullptr);
};

template<typename T>
struct LinkedList {
    Node<T>* head;

    LinkedList(const T& value): head(value);

    ~LinkedList() {
        clear();
    }

    void push(T value);

    bool delNode(int id);

    T* getData(int id);
};

#endif