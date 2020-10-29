#ifndef SINGLYLINKEDLIST_CPP
#define SINGLYLINKEDLIST_CPP
#include "List.hpp"

using namespace std;

template <class E>

class SinglyLinkedList : public List<E> {

    private:
          struct Node {
            E value;
            struct Node *next;
        };

        int list_size;
        Node *head;
        Node *tail;

    public: 
        SinglyLinkedList(){
            head = nullptr;
            tail = nullptr;
            list_size = 0;
        }

        SinglyLinkedList(SinglyLinkedList const &list) {
            head = nullptr;
            tail = nullptr;
            list_size = 0;
        }

        ~SinglyLinkedList() {

            Node *nodePtr;
            Node *nextNode;

            nodePtr = head;

            while(nodePtr != nullptr) {
            nextNode = nodePtr;
            delete nodePtr;
            nodePtr = nextNode->next;
            }    
        }

        virtual bool add(E num) {
            Node *newNode;
            Node *nodePtr;

            newNode = new Node;
            newNode->value = num;
            newNode->next = nullptr;

            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            list_size++;

            return true;
        }

        virtual bool addFirst(E num) {
    
            Node *newNode;
            Node *nodePtr;

            newNode = new Node;
            newNode->value = num;
            nodePtr = head;

            head = newNode;
            newNode->next = nodePtr;

            list_size++;    

            return true;
        }


        virtual bool addList(List<E> &list) {
            
            int add_size = list.size();
            
            for (int i = 0; i < add_size; i++) {
                add(list.get(i));
                list_size++;
            }

            return true;     

        }

        virtual bool addLast(E num) {

            Node *newNode;
            Node *nodePtr;

            newNode = new Node;
            newNode->value = num;
            newNode->next = nullptr;

            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
                }

            list_size++;

            return true;
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

        virtual E get(int index) const {

            E val;

            if (index == (list_size - 1)) {
                val = tail->value;
            } else {

                Node *nodePtr;
                nodePtr = head;

            for(int i = 0; i < index; i++) {
                nodePtr = nodePtr->next;
            }
            val = nodePtr->value;
            }
        return val;

        }

        virtual int size() const {
            return list_size;
        }


// template <class E>
// void SinglyLinkedList<E>::clear() {

//     Node *nodePtr;
//     Node *deleteNode;
 
//     if (!head || !tail) {
            
//     } else {
        
//         nodePtr = head->next;
//         deleteNode = head;
//         head = nullptr;

//         while(nodePtr) {
//             delete deleteNode;
//             deleteNode = nodePtr;
//             nodePtr = nodePtr->next;
//     }

//         delete tail;
//         tail = nullptr;
//         size = 0;
        
//     }
//  }

//  template <class E>
// int SinglyLinkedList<E>::count(E num) const {
        
//     int count = 0;

//     Node *nodePtr;

//     nodePtr = head;

//     while(nodePtr) {
//         if (nodePtr->value == num) 
//             count++;
//         nodePtr = nodePtr->next;
//     }

//     return count;
// }

// template <class E>
// E SinglyLinkedList<E>::get(int index) const {
        
    // double val;
    // if (index == size - 1) {
    //     val = tail->value;
    // } else {

    //     Node *nodePtr;
    //     nodePtr = head;

    //     for(int i = 0; i < index; i++) {
    //         nodePtr = nodePtr->next;
    //     }

    //     val = nodePtr->value;
    // }
    // return val;
// }

// template <class E>
// bool SinglyLinkedList<E>::isEmpty() const {
//     if (size == 0) {
//         return true;
//     } else {
//         return false;
//     }
// }

// template <class E>
// E SinglyLinkedList<E>::remove(int index) {

//     double val;
//     Node *nodePtr1;
//     Node *nodePtr2;

//     nodePtr1 = head;

//     if (size > 0) {

//         if (index == 0) {
//             head = nodePtr1->next;
//             val = nodePtr1->value;
//             delete nodePtr1;
//         } else if (index == size - 1) {

//             while (nodePtr1->next->next) {
//                 nodePtr1 = nodePtr1->next;
//             }

//             val = tail->value;
//             delete tail;
//             nodePtr1->next = NULL;
//             tail = nodePtr1;

//         } else if (index > 1 && index < size) {

//             for (int i = 0; i < index; i++) {
//                 nodePtr2 = nodePtr1;
//                 nodePtr1 = nodePtr1->next;
//             }

//             val = nodePtr1->value;
//             nodePtr2->next = nodePtr1->next;
//             delete nodePtr1;

//         } else {
//             std::cout << "Please enter a valid index\n";
//         }
//     }
//     return val;
// }

// template <class E>
// void SinglyLinkedList<E>::reverse() {

//     Node *previous;
//     Node *next;

//     previous = nullptr;
//     next = nullptr;
//     tail = head;

//     while (head != NULL) {

//         next = head->next;
//         head->next = previous;
//         previous = head;
//         head = next;
//     }

//     head = previous;
// }

// template <class E>
// E SinglyLinkedList<E>::set(int index, E value) {
        
//     Node *nodePtr;
//     nodePtr = head;
//     double val;

//     for(int i = 0; i < index; i++) {
//         nodePtr = nodePtr->next;
//     }

//     val = nodePtr->value;
//     nodePtr->value = value;

//     return val;
// }

// template <class E>
// void SinglyLinkedList<E>::printList() const {

//     Node *nodePtr;

//     nodePtr = head;

//     while(nodePtr) {
//         std::cout << nodePtr->value << "\n";
//         nodePtr = nodePtr->next;
//     }

// }

// // template <class E>
// // int SinglyLinkedList<E>::getSize() const {
// //         return size;
// // }

// template <class E>
// void SinglyLinkedList<E>::sort() {
    
//     Node *nodePtr1;
//     Node *nodePtr2;
//     Node *switchNodePtr;
//     nodePtr2 = head;

//     E temp, start_value, lowest_value;

//     for(int i = 0; i < size - 1; i++) {

//         start_value = nodePtr2->value; // value to be compared
//         lowest_value = start_value;  // set start value as initial minimum value
//         nodePtr1 = nodePtr2->next;  // assign nodePtr1 as next node to nodePtr2
//         switchNodePtr = nodePtr2;  // pointer to a node that will be switched with start value node
            
//         // look for the node with the lowest value and assign node of lowest to switch node
//         while(nodePtr1) {

//             if (nodePtr1->value < lowest_value) {
//                 lowest_value = nodePtr1->value;
//                 switchNodePtr = nodePtr1;
//             }
            
//             nodePtr1 = nodePtr1->next;
//         }
        
//         // if minimum value has been found, switch the values
//         if (switchNodePtr) {

//             temp = switchNodePtr->value;
//             switchNodePtr->value = nodePtr2->value;
//             nodePtr2->value = temp;
//             switchNodePtr = nullptr;

//         }
//         nodePtr2 = nodePtr2->next;
//     }
// }


};


#endif