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
        double remove(int index);
        void reverse();
        double set(int index, double value);
        int getSize() const;
        void sort();

        void printList() const; //REMOVEEE!!!! NOT PART OF HW



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
        
        double val;
        if (index == size - 1) {
            val = tail->value;
        } else {
            ListNode *nodePtr;
            nodePtr = head;

            for(int i = 0; i < index; i++) {
                nodePtr = nodePtr->next;
            }
            val = nodePtr->value;
        }
        return val;
    }

    bool NumberList::isEmpty() const {
        if (size == 0) {
            return true;
        } else {
            return false;
        }
    }

    // //removes value at index you know
    double NumberList::remove(int index) {

        double val;
        ListNode *nodePtr1;
        ListNode *nodePtr2;

        nodePtr1 = head;

        if (size > 0) {

            if (index == 0) {
                head = nodePtr1->next;
                val = nodePtr1->value;
                delete nodePtr1;
            } else if (index == size - 1) {

                while (nodePtr1->next->next) {
                    nodePtr1 = nodePtr1->next;
                }

                val = tail->value;
                delete tail;
                nodePtr1->next = NULL;
                tail = nodePtr1;

            } else if (index > 1 && index < size) {

                for (int i = 0; i < index; i++) {
                    nodePtr2 = nodePtr1;
                    nodePtr1 = nodePtr1->next;
                }

                val = nodePtr1->value;
                nodePtr2->next = nodePtr1->next;
                delete nodePtr1;

            } else {
                std::cout << "Please enter a valid index\n";
            }


        
        }
        return val;
       
    }
    
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

    double NumberList::set(int index, double value) {
        
        ListNode *nodePtr;
        nodePtr = head;
        double val;

        for(int i = 0; i < index; i++) {
            nodePtr = nodePtr->next;
        }

        val = nodePtr->value;
        nodePtr->value = value;

        return val;
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

    void NumberList::sort() {
        ListNode *nodePtr1;
        ListNode *nodePtr2;
        ListNode *switchNodePtr;
        nodePtr2 = head;

        double temp, start_value, lowest_value;

        for(int i = 0; i < size - 1; i++) {

            start_value = nodePtr2->value; // value to be compared
            lowest_value = start_value;  // set start value as initial minimum value
            nodePtr1 = nodePtr2->next;  // assign nodePtr1 as next node to nodePtr2
            switchNodePtr = nodePtr2;  // pointer to a node that will be switched with start value node
            
            // look for the node with the lowest value and assign node of lowest to switch node
            while(nodePtr1) {
                if (nodePtr1->value < lowest_value) {
                    lowest_value = nodePtr1->value;
                    switchNodePtr = nodePtr1;
                }
                nodePtr1 = nodePtr1->next;
            }
            // if minimum value has been found, switch the values
            if (switchNodePtr) {
                temp = switchNodePtr->value;
                switchNodePtr->value = nodePtr2->value;
                nodePtr2->value = temp;
                switchNodePtr = nullptr;
            }
            
            nodePtr2 = nodePtr2->next;

        }


    }



    

#endif