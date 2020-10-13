#include <iostream>
#include "NumberList.h"

using namespace std;



int main() {
    NumberList test1;
    NumberList test2;
    // NumberList test2;

    test1.add(1);
    test1.add(2);
    test1.add(4);
    test1.add(1);
    test1.add(1);
    test1.add(1);

    // test2.addList(test1);

    // test1.printList();
    cout << test1.count(1);

    return 0;

}