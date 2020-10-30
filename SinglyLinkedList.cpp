#ifndef SINGLYLINKEDLIST_CPP
#define SINGLYLINKEDLIST_CPP
#include "List.hpp"

// fix get to include -1, remove at 0 to include tail when size = 1, add throws for index stuff

using namespace std;

template <class E>
class SinglyLinkedList : public List<E> {

    // Node structure definition
    private:
          struct Node {
            E value;
            struct Node *next;
        };
    
        Node *head;  // Node head points to first elemenet in list
        Node *tail;  // Node tail points to last element in list

    public: 
        // Constructor
        SinglyLinkedList(){
            head = nullptr;
            tail = nullptr;
        }

        // Copy constructor
        SinglyLinkedList(SinglyLinkedList const &list) {
            head = nullptr;
            tail = nullptr;
        }

        // Desctructor
        ~SinglyLinkedList() {
            // Pointers to Node
            Node *nodePtr;
            Node *nextNode;

            nodePtr = head;
            // iterate through Nodes and delete NodePtr
            while(nodePtr != nullptr) {
            nextNode = nodePtr;
            delete nodePtr;
            nodePtr = nextNode->next;
            }    
        }
        /**
            Adds E at the end of linked list
            @param E value
            @return bool true if E is added to linked list else false
        */
        virtual bool add(E num) {

            Node *newNode;  // pointer node to new Node
            Node *nodePtr;  // pointer to Node on linked list

            // create new node and set num as value
            newNode = new Node;
            newNode->value = num;
            newNode->next = nullptr;

            // if list is empty, point head and tail to new node
            if (!head) {
                head = newNode;
                tail = newNode;
            // else add new Node at end of linked list    
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            return true;
        }
        
        /**
            Adds E in front of linked list
            @param E value
            @return bool true if E is added else false
        */
        virtual bool addFirst(E num) {
            
            Node *newNode;  // pionter to new Node
            Node *nodePtr;  // pointer to Node on linked list

            // create new Node set value as num
            newNode = new Node;
            newNode->value = num;
            
            // add new Node to front of list
            nodePtr = head;
            head = newNode;
            newNode->next = nodePtr;

            return true;
        }

        /**
            Appends contents of another linked list at end of self
            @param List E 
            @return bool true if linked list contents were added at end of list
        */
        virtual bool addList(List<E> &list) {
            
            int list_size = list.size();  // get size of linked list to be added
            
            //iterate through added linked list and add each node value at the end of list
            for (int i = 0; i < list_size; i++) {
                add(list.get(i));
            }

            return true;     

        }

        /**
            Adds E at end of linked list
            @param E value
            @return bool true if E is added else false
        */        
        virtual bool addLast(E num) {

            Node *newNode; // pointer to new Node
            Node *nodePtr; // pointer to Node on linked list

            // create new Node and set value as num
            newNode = new Node;
            newNode->value = num;
            newNode->next = nullptr;

            // if list is empty point head and tail to new Node
            if (!head) {
                head = newNode;
                tail = newNode;
            // add new Node at end of linked list
            } else {
                tail->next = newNode;
                tail = newNode;
                }

            return true;
        }

        /**
            Clear deletes all nodes in linked list
            @param none
            @return none
        */
        virtual void clear() {

            Node *nodePtr;  // pointer to Node on linked list
            Node *deleteNode; // pointer to Node for deletion
        
            // if empty do nothing
            if (!head || !tail) {
        
            } else {
                
                nodePtr = head->next;  // point to second Node
                deleteNode = head;  // point to first Node
                head = nullptr;  // set head to null

                // itereate through list and delete each Node
                while(nodePtr) {
                    delete deleteNode;
                    deleteNode = nodePtr;
                    nodePtr = nodePtr->next;
            }

                // delete last Node and set tail to nullptr
                delete tail;
                tail = nullptr;
                
            }
        }       

        /**
            Counts instances of argument value in linked list
            @param E value to be searched on the list
            @return int intances of E on the list
        */
        virtual int count(E num) const {
                
            int count = 0;  // holds amount of instances E is found

            // create Node pointer and point to head
            Node *nodePtr;
            nodePtr = head;

            // iterate through list and increment count if E is found
            while(nodePtr) {
                if (nodePtr->value == num) 
                    count++;
                nodePtr = nodePtr->next;
            }

            return count;
        } 

        /**
            Get returns value at index argument. -2 as second to last and -1 as last
            @param int index of value of interest
            @return E value at index
            @throw index out of bounds
        */
        virtual E get(int index) const {

            E val; // will hold value at index

            // create Node pointer and point to head
            Node *nodePtr; 
            nodePtr = head;
            
            // if index at end of list or -1, return last element using tail
            if (index == (this->size() - 1) || index == -1) {
                val = tail->value;
            } 
            // if index at -2 return 2nd to last element
            else if (index == -2 && this->size() > 1) {
                // get 2nd to last element
                while(nodePtr->next->next) {
                    nodePtr = nodePtr->next;
                }
                val = nodePtr->value;
            } 
            // if index at front, use head to get value;
            else if (index == 0) {
                val = nodePtr->value;
            }
            // if index is between 0 and less than size
            else if (index > 0 && index < this->size() ) {
                // iterate till index and get Node pointer
                for(int i = 0; i < index; i++) {
                    nodePtr = nodePtr->next;
                }
                val = nodePtr->value;
            } 
            // throw error if index out of bounds
            else {
                throw "Index out of bound error";
            }
            return val;

        }
        /**
            Checks if list is empty
            @param none
            @return bool true if empty else false
        */
        virtual bool isEmpty() const {
            // check size if empty
            if (this->size() == 0) {
                return true;
            } else {
                return false;
            }
        }

        /**
            Removes Node at index argument
            @param int index of Node to be removed
            @return E value of Node at index
            @throw index out of bound error
        */       
        virtual E remove(int index) {

            E val = 0;  // will hold value at index
            Node *nodePtr1; // Node pointer of node to be deleted
            Node *nodePtr2;  
            nodePtr1 = head;   
            int list_size = this->size();  // get size

            // if index at 0, move head to next then delete front Node
            if (index == 0 ) {
                head = nodePtr1->next;
                val = nodePtr1->value;
                delete nodePtr1;
            } 
            // if index at -1, move tail to 2nd to last then delete last Node
            else if (index == -1) {
                // find 2nd to last Node
                while (nodePtr1->next->next) {
                    nodePtr1 = nodePtr1->next;
                }
                // get value, delete tail and update tail Node
                val = tail->value;
                delete tail;
                nodePtr1->next = NULL;
                tail = nodePtr1;

            }
            // if index is greater than zero or less than list size 
            else if (index > 0 && index < list_size) {
                // iterate till index
                for (int i = 0; i < index; i++) {
                    nodePtr2 = nodePtr1;
                    nodePtr1 = nodePtr1->next;
                }
                // get Node value, point previous Node to next Node then delete Node
                val = nodePtr1->value;
                nodePtr2->next = nodePtr1->next;
                delete nodePtr1;
            } 
            else {
                // throw index out of bounds error
                throw "Index out of bounds error";
            } 
            return val;
        }
        /*
            Reverses the order of the list
            @param none
            @return none
        */
        virtual void reverse() {

            // Create Node pointers
            Node *previous;
            Node *next;

            previous = nullptr;
            next = nullptr;
            // set tail to head
            tail = head;

            // iterate will head is not null
            while (head != NULL) {
                next = head->next;  // point to Node next to head
                head->next = previous;  // point head node to previous node
                previous = head; // point previous to heads location
                head = next; // point head to the next Node
            }
            // set last Node as head 
            head = previous;
        }
        /*
            Replaces value at index arguement with value E argument
            @param int index of value of interest
            @param E new value at index
            @return E value at index
            @throw Index out of bounds
        */
        virtual E set(int index, E value) {
            
            // Create Node pointer and point to head
            Node *nodePtr;  
            nodePtr = head;  
            E val;  // holds old E value
            // if index within bounds, iterate then replace value
            if (index >= 0 && index < this->size()) {
                
                for(int i = 0; i < index; i++) {
                    nodePtr = nodePtr->next;
                }
                val = nodePtr->value;
                nodePtr->value = value;
            } 
            // throw if index out of bounds
            else {
                throw "Index out of bounds error.";
            }
            return val;
        }

        /*
            Returns size of linked list
            @param none
            @return int size of linked list
        */
        virtual int size() const {
            int linked_list_size = 0; // default linked list size
            //c reate Node pointer and point to head
            Node *nodePtr;
            nodePtr = head;
            // iterate through linked list and increment size
            while(nodePtr) {
                linked_list_size++;
                nodePtr = nodePtr->next;
            }
            return linked_list_size;
        }

        // template <class E>
        virtual void printList() const {

            Node *nodePtr;

            nodePtr = head;

            while(nodePtr) {
                std::cout << nodePtr->value << "\n";
                nodePtr = nodePtr->next;
            }
        }

        /*
            Sorts values of the linked list in increasing order
            @param none
            @return none
        */
        virtual void sort() {
            // Declare Nod pointers
            Node *nodePtr1;
            Node *nodePtr2;
            Node *switchNodePtr;  // pointer will switch Node values
            nodePtr2 = head;  // point to head

            //start_value will be compared, lowest_value will hold lowest value
            E temp, start_value, lowest_value;  

            // iterate through linked list
            for(int i = 0; i < this->size() - 1; i++) {

                start_value = nodePtr2->value; // value to be compared to other values in list
                lowest_value = start_value;  // set start value as initial minimum value
                nodePtr1 = nodePtr2->next;  // assign nodePtr1 as next node to nodePtr2
                switchNodePtr = nodePtr2;  // pointer to a node that will be switched with start value node
                    
                // look for the node with the lowest value and assign node of lowest to switch node
                while(nodePtr1) {
                    // if node value is lower than lowest_value, assign node value as lowest
                    if (nodePtr1->value < lowest_value) {
                        lowest_value = nodePtr1->value;
                        switchNodePtr = nodePtr1;
                    }
                    
                    nodePtr1 = nodePtr1->next;
                }
                
                // if minimum value has been found, switch the values
                if (switchNodePtr) {

                    temp = switchNodePtr->value;  // holds lowest value
                    switchNodePtr->value = nodePtr2->value;  // switch values
                    nodePtr2->value = temp;  
                    switchNodePtr = nullptr;  // reset to point to null

                }
                nodePtr2 = nodePtr2->next; // move to next Node
            }
        }


};


#endif