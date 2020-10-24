#include <iostream>
#include "NumberList.hpp"

using namespace std;



int main() {
    NumberList test1;
    // NumberList test2;
    // NumberList test2;


    test1.add(4);
    test1.add(2);
    test1.add(3);
    test1.add(6);

    // test2.addList(test1);
    // test1.reverse();

    test1.set(3, 0);

    test1.printList();
    return 0;

}