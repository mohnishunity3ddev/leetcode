#include "linked_list.h"

void
driver()
{
    linked_list<f32> ll;

    ll.display();

    ll.add(1.5f);
    ll.add(2.33f);
    ll.add(5.23f);

    ll.removeAt(1);

    ll.clear();
    ll.display();
}

void
exampleWithRandoms()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::uniform_int_distribution<int> distribution(1, 100);
    linked_list<i32> ll;

    for (i32 i = 0; i < 20; ++i) {
        i32 n = distribution(gen);
        ll.add(n);
    }

    ll.display();
    ll.update(1, 23100);
    ll.display();

    ll.addAt(0, -1);
    ll.addAt(3, -1);
    ll.display();
}