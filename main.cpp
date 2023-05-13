#include <iostream>
#include "array.h"

using namespace std;

int main()
{
        arrayListType<char> arr(10);
        for (int i=0;i<10;i++)
        {
            char num; cin>>num;
            arr.insertAt(i,num);
        }
        arr.print();
}
