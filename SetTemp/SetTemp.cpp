#include <iostream>
#include "unorderedSet.h"
using namespace std;

int main() {
    int intArray[] = { 1, 2, 3, 4, 5, 3, 2, 6, 7, 8 };

    string strArray[] = { "apple", "banana", "orange", "apple", "grape", "banana" };

    unorderedSet<int> intSet;
    unorderedSet<string> strSet;

    for (int i = 0; i < sizeof(intArray) / sizeof(int); ++i) {
        intSet.insertEnd(intArray[i]);
    }

    for (int i = 0; i < sizeof(strArray) / sizeof(string); ++i) {
        strSet.insertEnd(strArray[i]);
    }

    cout << "Integer set after adding elements:" << endl;
    intSet.print();

    cout << "String set after adding elements:" << endl;
    strSet.print();

    intSet.insertAt(3, 10);
    cout << "Integer set after insertAt:" << endl;
    intSet.print();

    strSet.insertAt(2, "apple");
    cout << "String set after insertAt:" << endl;
    strSet.print();

    intSet.replaceAt(4, 20);
    cout << "Integer set after replaceAt:" << endl;
    intSet.print();

    strSet.replaceAt(3, "banana");
    cout << "String set after replaceAt:" << endl;
    strSet.print();

    unorderedSet<int> intSet1, intSet2, intSetUnion;
    intSet1.insertEnd(1);
    intSet1.insertEnd(2);
    intSet2.insertEnd(2);
    intSet2.insertEnd(3);
    intSetUnion = intSet1 + intSet2;
    cout << "Union of integer sets:" << endl;
    intSetUnion.print();

    unorderedSet<int> intSetIntersection;
    intSetIntersection = intSet1 - intSet2;
    cout << "Intersection of integer sets:" << endl;
    intSetIntersection.print();

    return 0;
}
