// import necessary packages;
#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>

#include "SinglyLinkedList.cpp"

// using namespace sdsu;
using namespace std; 
using namespace std::chrono;

// loops a linked list method
template <class List>
void loop_method(int n, List &list, int m);

// test method time
template <class List>
void test_method(int epoch, int loop, List &list, string method);

// prints contents of linked list
template <class List>
void print_list(List &list);

// retrieves method name as int
int method_number(string method);

// return quotient of numerator and denominator
double growth(double numerator, double denominator);


int main() {

        // create two int SingleLinkedList objects
        SinglyLinkedList<int> singlyLinkedList1;
        SinglyLinkedList<int> singlyLinkedList2;
        
        // create two int List pointers and point to SingleLinked list objects
        List<int> *list1 = &singlyLinkedList1;
        List<int> *list2 = &singlyLinkedList2;

        bool val; // holds value of List return methods
        int num; // holds value of List return methods


        try {   // Test add methods
                cout << "Testing add methods" << endl;
                val = list1->add(1);   // add
                val = list2->add(4);
                val = list2->add(10);
                val = list1->addFirst(2);  // addFirst
                val = list1->addLast(3);  // addLast
                val = list1->addList(*list2); // addList
                print_list(*list1);

                cout << "\nTesting remove and get" << endl;
                cout <<  "Removing at 0 returns " << list1->remove(0) << endl;  // remove at 0
                cout << "Removing at -1 returns " << list1->remove(-1) << endl; // remove at -1
                cout << "Removing at -2 returns " << list1->get(-2) << endl;  // get at -2
                
                cout << "\nTesting clear method\n";
                cout << "The size of the linked list is " << list1->size() << endl;  // get size
                list1->clear(); // clear list
                cout << "The size of the linked list after clearing is " << list1->size() << endl; // get size
                cout << "Is list empty? " << list1->isEmpty() << endl;  // check if empty

                cout << "\nTesting sort" << endl;
                cout << "Create descending list from 9 to 0\n";
                loop_method(10, *list1, method_number("addFirst"));  // create list 9-0
                print_list(*list1);  // print list
                list1->sort();   // sort list
                cout << "\nList after order after sorting" << endl;
                print_list(*list1);  // print list

                cout << "\nTesting set method" << endl;
                cout << "Adding two 4's in the list using set method" << endl;
                num = list1->set(0,4);
                num = list1->set(8,4);
                cout << "The number of '4' on the list is " << list1->count(4) << endl;

                list1->clear();
                cout << "Testing reverse on empty list";
                list1->reverse();
                cout << "Size of list is " << list1->size() << endl;
                cout << "Seems fine..." << endl;

                list1->clear();
        
                // // Testing time complexity of addFirst, addList, removeFirst, and removeLast
                cout << "\nPerforming Timing Test\n";
                test_method(8, 500, list1, "addFirst");
                test_method(8, 500, list1, "addLast");
                test_method(8, 500, list1, "removeFirst");
                test_method(8, 500, list1, "removeLast");          

    

        } catch (const char* error) {
                cerr <<  error << endl;
        }
        return 0;

}

/*
 Calls linked list addFirst, addLast, and remove methods
 @param int n number of elements to add
 @param List linked list
 @param int method number using method_number
*/
template <class List>
void loop_method(int n, List &list, int m) {

        // swtich statement for different linked list methods
        switch (m)
       {
        case 1:
                for(int i = 0; i < n; i++)
                        list.addFirst(i);
               break;
        case 2:
                for(int i = 0; i < n; i++)
                        list.addLast(i);
                break;
        case 3:
                for(int i = 0; i < n; i++)
                        list.remove(0);
                break;
        case 4:
                for(int i = 0; i < n; i++)
                        list.remove(-1);
        default:
               break;
       }
}

/*
 Function to test linked list time complexity
 @param int epoch epochs
 @param int n number of elements to add
 @param List linked list
 @param string name of List method to test
*/
template <class List>
void test_method(int epoch, int loops, List &list, string method) {

        // create time_point instances of high_resolution_clock from chrono library
        high_resolution_clock::time_point start;  // holds start time
        high_resolution_clock::time_point end;  // holds end time

        int loop = loops;  // number of time to call method
        double elapsed, previous_elapsed = 0; // holds elapsed times
        double growth_factor;  // ratio of elapsed/previous elapsed
        
        // Title
        cout << "\nTesting Time Complexity of " << method << "." << endl;
        cout << "Time (ms)\t" << "N (size)\t" << "Growth Factor" << endl;

        // Test loop
        for (int i = 0; i < epoch; i++) {

                // add elements on list when calling remove method
                if (method_number(method) == 3 || method_number(method) == 4)
                        loop_method(loop, *list, method_number("addFirst"));

                start = high_resolution_clock::now();  // get start time
                loop_method(loop, *list, 1);  // call method using loop method
                end = high_resolution_clock::now();  // get end time
                chrono::duration< double > elapsed_time = end - start;  // cast to double
                elapsed = elapsed_time.count() * 1000000;  // get elapsed time in ms
                growth_factor = growth(elapsed, previous_elapsed);  // get growth factor
                printf(" %-11.f %-11d %-10.2f \n", elapsed, loop, growth_factor);  // print results

                list->clear();  // clear list
                previous_elapsed = elapsed;  // assign elapsed as previous
                loop*=2;  // double loop value
        }
        
}

/*
Converts method name to int key for loop method argument
@param string method name
@return int method number
*/
int method_number(string method) {
        
        // assign a number to each method then return
        if (method == "addFirst") 
                return 1;
        else if (method == "addLast")
                return 2;
        else if (method == "removeFirst")
                return 3;
        else if (method == "removeLast")
                return 4;
        else {
                cout << "Enter a valid method name.\n";
                return -1;
        }
}

/*
Divides numerator by denominator i.e ratio
@param double numerator 
@param double denominator
@return double quotient. 1 if denominator is zero
*/
double growth(double numerator, double denominator) {
        if (denominator == 0)
                return 1.0;
        else return (numerator/denominator);

}
// prints contents of linked list
template <class List>
void print_list(List &list) {
        // get size and loop
        for(int i = 0; i < list.size();i++)
                cout << list.get(i) << endl;
}
