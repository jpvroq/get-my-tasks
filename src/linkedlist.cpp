#include <linkedlist.hpp>
#include <stdint.h>

    template<typename T>
    void push(T value) {
        Node<T>* aux = nullptr;

        if (head != nullptr) {
            aux = head;
        } else {
            head = new Node(value);
            return;
        }
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = new Node(value);
    };

    template<typename T>
    bool delNode(uint16_t id) {
        Node<T>* aux = head;
        Node<T>* aux2 = nullptr;
        
        if (head != nullptr){
            if(head->id == id){
                head = head->next;
                delete aux;
                return true;
            }
            return false;
        }
        while(aux->next != nullptr) {
            if (aux->next->id == id) {
                aux2 = aux->next;
                aux->next = aux->next->next;
                delete aux2;
                return true;
            }
        }
        return false;
    };

    template<typename T>
    T* getData(uint16_t id) {
        Node<T>* aux = nullptr;

        aux = head;

        while(aux != nullptr) {
            if (aux->id == id) return &(aux->data);
            aux = aux->next;
        }
        return nullptr;
    }
