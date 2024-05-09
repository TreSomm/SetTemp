#ifndef UNORDEREDSET_H
#define UNORDEREDSET_H

#include "unorderedArrayListType.h"
#include <iostream>

template<typename T>
class unorderedSet : public unorderedArrayListType<T> {
public:
    using unorderedArrayListType<T>::insertAt;
    using unorderedArrayListType<T>::insertEnd;
    using unorderedArrayListType<T>::replaceAt;

    unorderedSet(int size = 100);

    unorderedSet<T> operator+(const unorderedSet<T>& otherSet);

    unorderedSet<T> operator-(const unorderedSet<T>& otherSet);
};

template<typename T>
unorderedSet<T>::unorderedSet(int size) : unorderedArrayListType<T>(size) {}


template<typename T>
unorderedSet<T> unorderedSet<T>::operator+(const unorderedSet<T>& otherSet) {
    unorderedSet<T> tempSet = *this; 
    for (int i = 0; i < otherSet.listSize(); ++i) {
        if (tempSet.seqSearch(otherSet.list[i]) == -1) {
            tempSet.insertEnd(otherSet.list[i]); 
        }
    }
    return tempSet; 
}

template<typename T>
unorderedSet<T> unorderedSet<T>::operator-(const unorderedSet<T>& otherSet) {
    unorderedSet<T> tempSet;
    for (int i = 0; i < this->listSize(); ++i) {
        if (otherSet.seqSearch(this->list[i]) != -1) {
            tempSet.insertEnd(this->list[i]); 
        }
    }
    return tempSet;
}

#endif 
