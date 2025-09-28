#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<typename T>
struct Node {
    T data;
    uint16_t id;
    Node<T>* next;

    Node(const T& value) : data(value), next(nullptr);
};

template<typename T>
struct LinkedList {
    Node<T>* head;

    LinkedList(const T& value): head(value), next(nullptr);

    ~LinkedList() {
        clear();
    }

    void push(T value);

    bool delNode(uint16_t id);

    T* getData(uint16_t id);
};

#endif