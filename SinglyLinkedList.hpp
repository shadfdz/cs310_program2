#ifndef SINGLYLINKEDLIST_HPP
#define SINGLYLINKEDLIST_HPP
#include <iostream>

template <class E>
class SinglyLinkedList{

    //node def
    private:

        struct Node {
            T value;
            struct Node *next;
        };

        Node *head;
        Node *tail;
        int size;
  
    public:
        //constructor
        SinglyLinkedList();
        //destructor
        ~SinglyLinkedList();

        void add(E);
        void addList(SinglyLinkedList &list);
        void addFirst(E);
        void addLast(E);
        void clear();
        int count(E) const;
        E get(int index) const;
        bool isEmpty() const;
        E remove(E index);
        void reverse();
        double set(int index, E value);
        int getSize() const;
        void sort();

        void printList() const; //REMOVEEE!!!! NOT PART OF HW



};

#endif