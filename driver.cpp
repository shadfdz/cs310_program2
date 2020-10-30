#include <iostream>
#include <string>

#include "SinglyLinkedList.cpp"

//add -2 on get
//polish get remove if else
//get ride of size and use function
//add exception handling?
//using namespace sdsu

using namespace std; 

// function to loop method
template <class List>
void loop_method(int n, List &list, int m);

// function to test method time
template <class List>
void test_method(int epoch, List &list, string method);


int main() {

        // create two SingleLinkedList objects
        SinglyLinkedList<int> singlyLinkedList1;
        SinglyLinkedList<int> singlyLinkedList2;
        
        // create two List
        List<int> *test1 = &singlyLinkedList1;
        List<int> *test2 = &singlyLinkedList2;

        bool t1;
        int val;

        try {
                // List<int> test2;
                t1 = test1->add(1);
                t1 = test2->add(21);
                t1 = test2->add(-4);
                t1 = test1->addList(*test2);
                // cout << test1->set(0,29) << endl;
                // // test1->sort();
                test_method(1, test1, "lol");
                
 
                test1->printList();

        } catch (const char* error) {
                cerr <<  error << endl;
        }

        return 0;

}

/*
 Function to test linked list add methods
 @param int n number of elements to add
 @param List linked list
 @param string test method
*/
template <class List>
void loop_method(int n, List &list, int m) {

        switch (m)
       {
        case 1:
                for(int i = 0; n < 0; i++)
                        list.addFirst(i);
               break;
        case 2:
                for(int i = 0; n < 0; i++)
                        list.addLast(i);
                break;
        case 3:
                for(int i = 0; n < 0; i++)
                        list.remove(0);
                break;
        case 4:
                for(int i = 0; n < 0; i++)
                        list.remove(-1);
        default:
               break;
       }
}

/*
 Function to test linked list remove methods
 @param int n number of elements to add
 @param List linked list
 @param string test method
*/
template <class List>
void test_method(int epoch, List &list, string method) {

        int loop = 500;

        for (int i = 0; i < epoch; i++) {
                // get star time
                loop_method(loop, *list, 1);
                // get end time 
                list->clear();
                loop*=2;

        }
        
}



