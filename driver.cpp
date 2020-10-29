#include <iostream>
#include "SinglyLinkedList.cpp"

//using namespace sdsu
using namespace std; 


int main() {

        SinglyLinkedList<int> singlyLinkedList1;
        SinglyLinkedList<int> singlyLinkedList2;


        List<int> *test1 = &singlyLinkedList1;
        List<int> *test2 = &singlyLinkedList2;

        bool t1;
        // List<int> test2;
        t1 = test1->add(1);
        t1 = test2->add(2);
        t1 = test1->addList(*test2);
        t1 = test1->addLast(4);
        
        // test2.add(3);
        // test1.addList(test2);
        test1->printList();

        // NumberList test1;
        // // NumberList test2;
        // // NumberList test2;


        // for (int i = 15; i > 0; i--)
        //     test1.add(i);
        // // test1.reverse();

        // test1.sort();
        // // test1.printList();
        // test1.printList();
        return 0;

}

