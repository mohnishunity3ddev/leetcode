#if !defined(double_ended_stack_h)

#include <defines.h>
#include <iostream>

template <typename T>
struct double_ended_stack
{
  private:
    T *items;
    i32 capacity = 0;

    i32 topRight;
    i32 sizeRight;

    i32 topLeft;
    i32 sizeLeft;

  public:
    double_ended_stack() = delete;
    double_ended_stack(i32 capacity)
    {
        items = new T[capacity];
        topRight = capacity;
        topLeft = -1;
        sizeLeft = 0;
        sizeRight = 0;
        this->capacity = capacity;

        // rightIndex = capacity - 1;
        // leftIndex = 0;
    }
    ~double_ended_stack() {
        std::cout << "double ended stack destructor called!\n";
        delete[] items;
    }

    bool isLeftFull() {
        bool result = ((topLeft + 1) == topRight || (topLeft + 1) >= capacity);
        return result;
    }

    void pushLeft(T val) {
        if(isLeftFull()) {
            std::cout << "left stack is full!\n";
            return;
        }

        items[++topLeft] = val;
        sizeLeft += 1;
    }

    bool isLeftEmpty() {
        bool result = topLeft == -1;
        if(result) {
            ASSERT(sizeLeft == 0);
        }
        return result;
    }

    T popLeft() {
        if(isLeftEmpty()) {
            std::cout << "left stack is empty!\n";
            return (T)-1;
        }

        T result = items[topLeft--];
        sizeLeft--;
        return result;
    }

    void displayLeft() {
        if(isLeftEmpty()) {
            std::cout << "nothing in left list to display\n";
            return;
        }

        std::cout << "Left Stack: \n";
        i32 top = topLeft;
        while(top >= 0) {
            std::cout << items[top--] << "\n";
        }
    }

    bool isRightFull() {
        bool result = ((topRight - 1) == topLeft || (topRight - 1) < 0);
        return result;
    }

    bool isRightEmpty() {
        bool result = (topRight >= capacity);
        if(result) {
            ASSERT(sizeRight == 0);
        }
        return result;
    }

    void pushRight(T val) {
        if(isRightFull()) {
            std::cout << "right stack is full!\n";
        }

        items[--topRight] = val;
        sizeRight += 1;
    }

    T popRight() {
        if(isRightEmpty()) {
            std::cout << "right stack is empty!\n";
            return (T)-1;
        }

        T result = items[topRight++];
        sizeRight--;
        return result;
    }

    void displayRight() {
        if(isRightEmpty()) {
            std::cout << "nothing in right list to display\n";
            return;
        }

        std::cout << "Right Stack: \n";
        i32 top = topRight;
        while(top < capacity) {
            std::cout << items[top++] << "\n";
        }
    }
};

class solution {
  public:
    void driver()
    {
        double_ended_stack<f32> dStack(10);
        dStack.pushLeft(1);
        dStack.pushLeft(2);
        dStack.pushLeft(3);
        dStack.pushLeft(4);
        dStack.pushLeft(5);
        dStack.displayLeft();

        dStack.pushRight(6);
        dStack.pushRight(7);
        dStack.pushRight(8);
        dStack.pushRight(9);
        dStack.pushRight(10);
        dStack.displayRight();

        dStack.pushLeft(10);

        dStack.pushRight(dStack.popLeft());
        dStack.pushRight(dStack.popLeft());
        dStack.pushRight(dStack.popLeft());
        dStack.pushRight(dStack.popLeft());
        dStack.pushRight(dStack.popLeft());

        dStack.displayLeft();
        dStack.displayRight();

    }
};

#define double_ended_stack_h
#endif