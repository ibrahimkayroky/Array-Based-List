#include "array.h"
#include <iostream>
using namespace std;


template <class elemType>
bool arrayListType<elemType>::isEmpty() const
{
    return (length ==0);
}

template <class elemType>
bool arrayListType<elemType>::isFull() const
{
    return (length == maxSize);
}

template <class elemType>
int arrayListType<elemType>::listSize() const
{
    return length;
}

template <class elemType>
int arrayListType<elemType>::maxListSize() const
{
    return maxSize;
}

template <class elemType>
void arrayListType<elemType>::print() const
{
    for (int i = 0; i < length; i++)
    cout << list[i] << " ";
    cout << endl;
}


template <class elemType>
bool arrayListType<elemType>::isItemAtEqual(int location, const elemType& item) const
{
    return(list[location] == item);
}

template <class elemType>
void arrayListType<elemType>::insertAt
(int location, const elemType& insertItem)
{
    if (location < 0 || location >= maxSize)
    cerr << "The position of the item to be inserted "<< "is out of range" << endl;
    else
    if (length >= maxSize)
        cerr << "Cannot insert in a full list" << endl;
    else
    {
    for (int i = length; i > location; i--)
        list[i] = list[i - 1];
    list[location] = insertItem;
    length++;
    }
}

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem)
{
if (length >= maxSize)
cerr << "Cannot insert in a full list" << endl;
    else
    {
        list[length] = insertItem;
        length++;
    }
}

template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
    if (location < 0 || location >= length)
    cerr << "The location of the item to be removed "<< "is out of range" << endl;
    else
        {
        for (int i = location; i < length - 1; i++)
        list[i] = list[i+1];
        length--;
        }
}

template <class elemType>
void arrayListType<elemType>::clearList()
{
    length = 0;
}

template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
if (size < 0)
{
    cerr << "The array size must be positive. Creating "<< "an array of size 100. " << endl;
    maxSize = 100;
}
    else
        maxSize = size;
    length = 0;
    list = new elemType[maxSize];
    assert(list != NULL);
}
template <class elemType>
arrayListType<elemType>::~arrayListType()
{
    delete [] list;
}
template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
    if (size < 0)
    {
        cerr << "The array size must be positive. Creating "
        << "an array of size 100. " << endl;
        maxSize = 100;
    }
    else
        maxSize = size;
    length = 0;
    list = new elemType[maxSize];
    assert(list != NULL);
}

template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem)
{
    int loc;
    if (length == 0)
        list[length++] = insertItem;
    else if (length == maxSize)
        cerr << "Cannot insert in a full list." << endl;
    else
    {
        loc = seqSearch(insertItem);
        if (loc == -1)    list[length++] = insertItem;
        else
            cerr << "the item to be inserted is already in "<< "the list. No duplicates are allowed." << endl;
    }
}
