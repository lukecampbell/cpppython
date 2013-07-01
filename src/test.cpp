#include <iostream>
#include "linked_list.h"

using namespace std;

int main(int argc, char *argv[])
{
    int a = 20;
    int tmp;
    LinkedList<int> list;
    list.add(a);
    cout << "Size: " << list.length() << endl;
    cout << "l[0] = " << list.get(0) << endl;
    cout << "l.pop() = " << list.pop() << endl;
    cout << "Size: " << list.length() << endl;
    try {
        cout << "Trying to get an element (should fail)"<<endl;
        tmp = list.get(0);
        cout << "Shouldn't see this" << endl;
    } catch(std::out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    for(int i=0;i<20;i++) {
        list.add(i);
    }

    list.remove(10);

    while(list.length() > 0)
        cout << list.pop() << " ";
    cout << endl;



    return 0;
}
