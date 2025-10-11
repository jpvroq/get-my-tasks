#include <linkedlist.hpp>
#include <stdint.h>

    template<HasID T>
    void LinkedList<T>::push(T value) {
        
        if(head == nullptr) {
            head = new Node(value);
            tail = head;
        }
        else {
            tail->next = new Node(value);
            tail = tail->next;
        }
        size++;
        return;
    };

    template<HasID T>
    bool LinkedList<T>::delNode(int id) {
        Node<T>* aux = head;
        Node<T>* aux2 = nullptr;
        
        if (head != nullptr){
            if(head->data.id == id){
                head = head->next;
                delete aux;
                size--;
                return true;
            }
            return false;
        }
        while(aux->next != nullptr) {
            if (aux->next->data.id == id) {
                aux2 = aux->next;
                aux->next = aux->next->next;
                delete aux2;
                size--;
                return true;
            }
        }
        return false;
    };

    template<HasID T>
    T* LinkedList<T>::getData(int id) {
        Node<T>* aux = nullptr;

        aux = head;

        while(aux != nullptr) {
            if (aux->data.id == id) return &(aux->data);
            aux = aux->next;
        }
        return nullptr;
    }

    template<HasID T>
    void LinkedList<T>::clear() {
        Node<T>* aux = head;
        while(aux) {
            head = head->next;
            delete aux;
            aux = head;
        }
    }

    template<HasID T>
    LinkedList<T>::Iterator LinkedList<T>::begin() {
        return Iterator(head, 0);
    }

    template<HasID T>
    LinkedList<T>::Iterator LinkedList<T>::end() {
        return Iterator(nullptr, size);
    }