#ifndef LIST_HPP
#define LIST_HPP

using namespace std;

template <class E>
class List {


    public:
        //constructor
        List() {
        }
        //destructor
        ~List() {
        }

        virtual bool add(E num) = 0;

        virtual bool addList(List<E> &list) = 0;

        virtual bool addFirst(E num) = 0;

        virtual bool addLast(E num) = 0;

        // virtual void clear() = 0;

        // virtual int count(E num) const = 0;

        virtual E get(int index) const = 0;

        // virtual bool isEmpty() const = 0;

        // virtual E remove(int index) = 0;

        // virtual void reverse() = 0;

        // virtual E set(int index, E value) = 0;

        virtual int size() const = 0;

        // int getSize() {
        //     return size;
        // }

        // virtual void sort() = 0;

        virtual void printList() const = 0; //REMOVEEE!!!! NOT PART OF HW



};

#endif