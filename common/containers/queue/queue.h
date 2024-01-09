#if !defined(queue_h)

#include <defines.h>
#include <iostream>

#define TEST_ENQUEUE(q, val, size)                                             \
    q->enqueue(val);                                                           \
    ASSERT(q->getSize() == size)

#define TEST_DEQUEUE(q, expValue, expSize)                                     \
    {                                                                          \
        int res = q->dequeue();                                                \
        ASSERT(res == expValue);                                               \
        ASSERT(q->getSize() == expSize);                                       \
    }

template <typename T>
struct queue
{
  private:
    T *arr;
    int capacity = 0;
    int front = -1;
    int rear = -1;
    int size = 0;

  public:
    queue() : capacity(1), front(-1), rear(-1), size(0) {
        arr = new T[capacity];
    }

    queue(int capacity) : capacity(capacity), front(-1), rear(-1), size(0) {
        arr = new T[capacity];
    }

    ~queue() {
        delete[] arr;
        capacity = 0;
        front = -1;
        rear = -1;
        size = 0;
        std::cout << "called queue destructor.\n";
    }

    bool isEmpty() {
        bool result = (size == 0);
        return result;
    }

    bool isFull() {
        bool result = (size == capacity);
        return result;
    }

    int getSize() { return size; }

    void enqueue(T val) {
        if(isEmpty()) {
            front = rear = 0;
            arr[rear] = val;
            ++size;
            return;
        }
        rear = ((rear + 1) % capacity);
        if(isFull()) {
            resize();
            rear = ((rear + 1) % capacity);
        }
        arr[rear] = val;
        ++size;
    }

    T dequeue() {
        if(isEmpty()) {
            return NULL;
        }

        T result = arr[front];
        arr[front] = NULL;
        front = ((front + 1) % capacity);
        --size;

        return result;
    }

    void resize() {
        int oldCapacity = capacity;
        int newCapacity = capacity * 2;

        T *newArr = new T[newCapacity];
        int start = front;

        int i = 0;
        while (i < oldCapacity) {
            int index = start;

            newArr[i] = arr[index];
            start = ((start + 1) % oldCapacity);
            ++i;
        }

        delete[] arr;
        arr = newArr;
        front = 0;
        rear = oldCapacity - 1;
        capacity = newCapacity;
    }

    static void
    test(int capacity)
    {
        queue<T> *q = new queue<T>(capacity);
        int size = 0;
        q->enqueue(1);
        ASSERT(q->getSize() == 1);
        ASSERT(!q->isFull());
        q->enqueue(2);
        ASSERT(q->getSize() == 2);
        ASSERT(!q->isFull());
        q->enqueue(3);
        ASSERT(q->getSize() == 3);
        ASSERT(!q->isFull());
        q->enqueue(4);
        ASSERT(q->getSize() == 4);
        ASSERT(!q->isFull());
        q->enqueue(5);
        ASSERT(q->getSize() == 5);
        ASSERT(!q->isFull());
        q->enqueue(6);
        ASSERT(q->getSize() == 6);

        ASSERT(q->isFull());

        int r = q->dequeue();
        ASSERT(q->getSize() == 5);
        ASSERT(r == 1);

        r = q->dequeue();
        ASSERT(q->getSize() == 4);
        ASSERT(r == 2);

        r = q->dequeue();
        ASSERT(q->getSize() == 3);
        ASSERT(r == 3);

        r = q->dequeue();
        ASSERT(q->getSize() == 2);
        ASSERT(r == 4);

        r = q->dequeue();
        ASSERT(q->getSize() == 1);
        ASSERT(r == 5);

        r = q->dequeue();
        ASSERT(q->getSize() == 0);
        ASSERT(r == 6);

        ASSERT(q->isEmpty());

        TEST_ENQUEUE(q, 1, 1);
        TEST_ENQUEUE(q, 2, 2);
        TEST_ENQUEUE(q, 3, 3);
        TEST_ENQUEUE(q, 4, 4);
        TEST_ENQUEUE(q, 5, 5);
        TEST_ENQUEUE(q, 6, 6);

        ASSERT(q->isFull());

        TEST_DEQUEUE(q, 1, 5);
        TEST_DEQUEUE(q, 2, 4);

        TEST_ENQUEUE(q, 7, 5);
        TEST_ENQUEUE(q, 8, 6);
        ASSERT(q->isFull());

        TEST_ENQUEUE(q, 9, 7);
        TEST_ENQUEUE(q, 10, 8);
        TEST_ENQUEUE(q, 11, 9);
        TEST_ENQUEUE(q, 12, 10);
        TEST_ENQUEUE(q, 13, 11);
        TEST_ENQUEUE(q, 14, 12);
        ASSERT(q->isFull());

        TEST_DEQUEUE(q, 3, 11);
        TEST_DEQUEUE(q, 4, 10);
        TEST_DEQUEUE(q, 5, 9);
        TEST_DEQUEUE(q, 6, 8);

        TEST_ENQUEUE(q, 15, 9);
        TEST_ENQUEUE(q, 16, 10);
        TEST_ENQUEUE(q, 17, 11);
        TEST_ENQUEUE(q, 18, 12);
        ASSERT(q->isFull());

        TEST_DEQUEUE(q, 7, 11);
        TEST_DEQUEUE(q, 8, 10);
        TEST_DEQUEUE(q, 9, 9);
        TEST_DEQUEUE(q, 10, 8);
        TEST_DEQUEUE(q, 11, 7);
        TEST_DEQUEUE(q, 12, 6);
        TEST_DEQUEUE(q, 13, 5);
        TEST_DEQUEUE(q, 14, 4);
        TEST_DEQUEUE(q, 15, 3);
        TEST_DEQUEUE(q, 16, 2);
        TEST_DEQUEUE(q, 17, 1);
        TEST_DEQUEUE(q, 18, 0);
        ASSERT(q->isEmpty());

        delete q;
    }
};

#define queue_h
#endif