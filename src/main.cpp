#include <iostream>
#include <vector>

#include <defines.h>
#include <containers/tree/binary_tree/binary_tree.h>
#include <containers/tree/binary_search_tree/binary_search_tree.h>
#include <containers/linked_list/linked_list.h>

#include <containers/heap/heap.h>
#include <sorting/quick_sort.h>

using namespace std;

int
main()
{
    linked_list<int> ll;
    ll.add(1);
    ll.add(2);
    ll.add(3);
    ll.add(4);
    ll.add(5);
    ll.display();
    ll.remove2(4);
    ll.display();
    ll.remove2(1);
    ll.display();
    ll.remove2(3);
    ll.display();
    ll.remove2(5);
    ll.display();
    ll.remove2(2);
    ll.display();

    int x = 0;
}
