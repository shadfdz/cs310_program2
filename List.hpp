#ifndef LIST_HPP
#define LIST_HPP

// using namespace sdsu;

using namespace std;

/**
 * Generic virtual base class defining methods of a linked list
 */

template <class E>
class List {


    public:
        //constructor
        List() {
        }
        //destructor
        ~List() {
        }

        // append datum to the end of list
        virtual bool add(E num) = 0;
        // append every datum from another list to end of list
        virtual bool addList(List<E> &list) = 0;
        // append datum to front of list
        virtual bool addFirst(E num) = 0;
        // append datum to the end of list
        virtual bool addLast(E num) = 0;
        // clears list contents and resets it to empty state
        virtual void clear() = 0;
        // counts number of instances a target value appears in the list
        virtual int count(E num) const = 0;
        // return element stored at index, 0 at front and -1 at end.
        virtual E get(int index) const = 0;
        // return true if list is empty
        virtual bool isEmpty() const = 0;
        // remove item at index, 0 at front and -1 at end
        virtual E remove(int index) = 0;
        // reverse order of list
        virtual void reverse() = 0;
        // set value at index and returns old value
        virtual E set(int index, E value) = 0;
        // return size of list
        virtual int size() const = 0;
        // sort size of list ascending
        virtual void sort() = 0;

};

#endif