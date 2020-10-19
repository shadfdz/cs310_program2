#ifndef NUMBERLIST_H
#define NUMBERLIST_H
#include <iostream>

class NumberList{

    //node def
    private:

        struct ListNode {
            double value;
            struct ListNode *next;
        };

        ListNode *head;
        ListNode *tail;
        int size;

  
    public:
        //constructor
        NumberList();
        //destructor
        ~NumberList();

        void add(double);
        void addList(NumberList &list);
        void addFirst(double);
        void addLast(double);
        void clear();
        int count(double) const;
        double get(int index) const;
        bool isEmpty() const;
        // double remove(int index) const;
        void reverse();

        void printList() const; //REMOVEEE!!!! NOT PART OF HW

        int getSize() const;


};
    //constructor
    NumberList::NumberList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    //add copy constructor

    // destructor
    NumberList::~NumberList() {
        ListNode *nodePtr;
        ListNode *nextNode;

        nodePtr = head;

        while(nodePtr != nullptr) {
            nextNode = nodePtr;
            delete nodePtr;
            nodePtr = nextNode->next;
        }

    }

    //append to linked list
    void NumberList::add(double num) {
        ListNode *newNode;
        ListNode *nodePtr;

        newNode = new ListNode;
        newNode->value = num;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
     }

    
    //function adds list values to linked list
    void NumberList::addList(NumberList &list) {

        int list_size = list.getSize();
        for (int i = 0; i < list_size; i++) {
            add(list.get(i));
            size++;
        } 
        
    }
     //add to start of linked list

     void NumberList::addFirst(double num) {
        ListNode *newNode;
        ListNode *nodePtr;

        newNode = new ListNode;
        newNode->value = num;
        nodePtr = head;

        head = newNode;
        newNode->next = nodePtr;

        size++;

     }

    //add to last element
    void NumberList::addLast(double num) {
        ListNode *newNode;
        ListNode *nodePtr;

        newNode = new ListNode;
        newNode->value = num;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    //clears the list
    void NumberList::clear() {

        ListNode *nodePtr;
        ListNode *deleteNode;
 
        if (!head || !tail) {
            
        } else {
        
        nodePtr = head->next;
        deleteNode = head;
        head = nullptr;

        while(nodePtr) {
            delete deleteNode;
            deleteNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        delete tail;
        tail = nullptr;

        size = 0;
        }
    }

    //count
    int NumberList::count(double num) const {
        int count = 0;

        ListNode *nodePtr;

        nodePtr = head;

        while(nodePtr) {
            if (nodePtr->value == num) 
                count++;
            nodePtr = nodePtr->next;
        }

        return count;
    }

    //get member
    double NumberList::get(int index) const {
        
        ListNode *nodePtr;

        nodePtr = head;

        for(int i = 0; i < index; i++) {
            nodePtr = nodePtr->next;
        }

        return nodePtr->value;
    }

    bool NumberList::isEmpty() const {
        if (size == 0) {
            return true;
        } else {
            return false;
        }
    }

    // //removes value at index you know
    // double NumberList::remove(int index) const {
    //     double value = get(index);

    //     ListNode *nodePtr;

    //     nodePtr = head;

    //     if (index == 0) {
            
    //     }
    // }
    
    //reverse list direction
    void NumberList::reverse() {

        ListNode *previous;
        ListNode *next;

        previous = nullptr;
        next = nullptr;
        tail = head;

        while (head != NULL) {

            next = head->next;
            head->next = previous;
            previous = head;
            head = next;
        }

        head = previous;
    }

    //print list
    void NumberList::printList() const{
        ListNode *nodePtr;

        nodePtr = head;

        while(nodePtr) {
            std::cout << nodePtr->value << "\n";
            nodePtr = nodePtr->next;
        }

    }
    //get size
    int NumberList::getSize() const {
        return size;
    }




    

#endif