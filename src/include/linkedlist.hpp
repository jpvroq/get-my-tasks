#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>
#include <concepts>

template<typename T>
concept HasID = requires(T t) {
    { t.getID() } -> std::convertible_to<int>;
} || requires(T t) {
    { t->getID() } -> std::convertible_to<int>;
};

template<HasID T>
struct Node {
    T data;
    Node<T>* next;

    Node(const T& value) : data(value), next(nullptr) {}

    bool operator==(const Node& b) const {
        return this->data.id == b->data.id;
    }
};

template<HasID T>
struct LinkedList {
    Node<T>* head;
    Node<T>* tail;
    size_t size;

    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    LinkedList(const T& value): head(new Node<T>(value)), tail(head), size(1) {}

    ~LinkedList() {
        clear();
    }

    struct Iterator {
        using iterator_category = std::forward_iterator_tag;
        using value_type        = T;
        using difference_type   = std::ptrdiff_t;
        using pointer           = T*;
        using reference         = T&;

        private:
        size_t i;
        Node<T>* ptr;

        public:
        Iterator() : ptr(nullptr), i(0) {}
        Iterator(Node<T>* node, size_t indx) :  ptr(node), i(indx) {}
        
    
        Iterator& operator++() {
            if(ptr->next == nullptr) throw std::out_of_range("Iterator cannot be incremented");
            ptr = ptr->next;
            ++i;
            return *this;
        }

        Iterator& operator++(int) {
            Iterator aux = *ptr;
            if(ptr->next == nullptr) throw std::out_of_range("Iterator cannot be incremented");
            ptr = ptr->next;
            ++i;
            return aux;
        }

        friend bool operator==(const Iterator& a, const Iterator& b) {
            return a.i == b.i;
        }

        friend bool operator!=(const Iterator& a, const Iterator& b) {
            return !(a == b);
        }

        T* operator->() const{
            if(ptr == nullptr) throw std::runtime_error("Dereferencing null iterator");
            return &(ptr->data);
        }

        T& operator*() const{
            if(ptr == nullptr) throw std::runtime_error("Dereferencing null iterator");
            return ptr->data;
        }

        bool operator<(Iterator& it) {
            if(size < it.i) return true;
            return false;
        }
    };

    void push(T value);
    bool delNode(int id);
    T* getData(int id);
    void clear();
    Iterator begin();
    Iterator end();
};

#endif