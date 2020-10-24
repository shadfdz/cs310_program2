#include <iostream>
#include "NumberList.hpp"

using namespace std;



int main() {
    NumberList test1;
    // NumberList test2;
    // NumberList test2;


    test1.add(4);
    test1.add(10);
    test1.add(3);
    test1.add(6);
    test1.add(15);
    test1.add(1);
    // test2.addList(test1);
    // test1.reverse();

    test1.sort();
    // test1.printList();
    test1.printList();
    return 0;

}