#include <iostream>
#include "SinglyLinkedList.cpp"

//add -2 on get
//get ride of size and use function
//using namespace sdsu

using namespace std; 


int main() {

        SinglyLinkedList<int> singlyLinkedList1;
        SinglyLinkedList<int> singlyLinkedList2;


        List<int> *test1 = &singlyLinkedList1;
        List<int> *test2 = &singlyLinkedList2;

        bool t1;
        int val;
        // List<int> test2;
        t1 = test1->add(1);
        t1 = test2->add(21);
        t1 = test1->add(4);
        t1 = test1->addList(*test2);

        cout << test1->size();
     

        return 0;

}

