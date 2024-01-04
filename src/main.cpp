#include <iostream>
#include <vector>
#include <stdio.h>

#include <containers/linked_list/linked_list.h>

using namespace std;

int
main()
{
    linked_list<f32> ll;

    ll.display();

    ll.add(1.5f);

    ll.add(2.33f);

    ll.add(5.23f);

    ll.removeAt(1);

    ll.clear();
    ll.display();

    return 0;
}
