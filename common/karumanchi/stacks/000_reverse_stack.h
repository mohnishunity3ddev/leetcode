#if !defined(_reverse_stack_h)

#include "defines.h"
#include <containers/stack/stack.h>
#include <vector>

class solution {
  public:
    void reverseStack(stack<i32> *s) {
        s->display();
        std::vector<i32> vec;
        i32 size = s->getSize();
        vec.reserve(size);

        for(i32 i = 0; i < size; ++i) {
            i32 stackTop = s->pop();
            vec.emplace_back(stackTop);
        }

        ASSERT(s->isEmpty() == true);

        for (i32 i = 0; i < vec.size(); ++i) {
            s->push(vec[i]);
        }
        s->display();
    }

    void driver() {
        stack<i32> s(5);
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);

        reverseStack(&s);
    }
};

#define _reverse_stack_h
#endif