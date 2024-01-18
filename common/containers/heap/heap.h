#if !defined(HEAP_H)

#include <defines.h>
#include <iostream>

enum heap_type
{
    NONE,
    MAX_HEAP,
    MIN_HEAP,
};

struct heap {
    int *h;
    int heapSize;
    int capacity;
    heap_type type;

    heap() : h(nullptr), heapSize(0), type(heap_type::NONE) {
        this->h = new int[1];
        this->h[0] = -1;
        capacity = 1;
    }
    heap(heap_type type) : h() {
        this->type = type;
    }
    heap(int *arr, int arrSize, heap_type type) : heap()
    {
        // this->capacity = arrSize + 1;
        // this->h = new int[this->capacity];
        // this->h[0] = -1;
        this->type = type;
        for (int i = 0; i < arrSize; ++i) {
            insert(arr[i]);
        }
    }
    ~heap()
    {
        delete[] h;
        h = nullptr;
        heapSize = 0;
        type = heap_type::NONE;
        // std::cout << "heap destructor called!\n";
    }

    bool isFull() {
        bool result = (this->heapSize >= (this->capacity - 1));
        return result;
    }

    void display() {
        for (int i = 1; i <= heapSize; ++i) {
            std::cout << this->h[i] << ", ";
        }
        std::cout << std::endl;
    }

    void resize() {
        this->capacity *= 2;
        int *temp = new int[this->capacity];
        for (int i = 0; i <= this->heapSize; ++i)
        {
            temp[i] = this->h[i];
        }
        delete[] this->h;
        this->h = temp;
    }

    void
    verify()
    {
        int i = 1;

        // std::cout << "heapsize is: " << heapSize << ".\n";
        if(type == heap_type::MAX_HEAP) {
            while(i <= (heapSize - 1)/2) {
                ASSERT(h[i] >= h[i*2]);
                ASSERT(h[i] >= h[i*2 + 1]);
                i++;
            }
            if(2*i == heapSize) { ASSERT(h[i] >= h[2*i]); }
        } else if(type == heap_type::MIN_HEAP) {
            while(i <= (heapSize - 1)/2) {
                ASSERT(h[i] <= h[i*2]);
                ASSERT(h[i] <= h[i*2 + 1]);
                i++;
            }
            if(2*i == heapSize) { ASSERT(h[i] <= h[2*i]); }
        }
    }

    void
    insert(int item)
    {
        if( isFull() ) { resize(); }
        int i = ++this->heapSize;

        this->h[i] = item;
        if(type == heap_type::MAX_HEAP) {
            while(i > 1 && (h[i] > h[i/2])) {
                int temp = h[i];
                h[i] = h[i/2];
                h[i/2] = temp;
                i /= 2;
            }
        } else if(type == heap_type::MIN_HEAP) {
            while(i > 1 && (h[i] < h[i/2])) {
                int temp = h[i];
                h[i] = h[i/2];
                h[i/2] = temp;
                i /= 2;
            }
        }
    }

    int
    removeOne()
    {
        int result = h[1];

        h[1] = h[this->heapSize--];
        int i = 1;
        if(type == heap_type::MAX_HEAP) {
            while(i <= (this->heapSize - 1) / 2) {
                int c1 = h[i*2];
                int c2 = h[i*2 + 1];
                if(h[i] < c1 || h[i] < c2) {
                    int temp = h[i];
                    int j = (c1 > c2) ? (i * 2) : (i * 2 + 1);

                    h[i] = h[j];
                    h[j] = temp;
                    i = j;
                } else {
                    break;
                }
            }
            if(i == heapSize/2 && h[i] < h[2*i]) {
                int temp = h[i];
                h[i] = h[2*i];
                h[2*i] = temp;
            }
        } else if(type == heap_type::MIN_HEAP) {
            while(i <= (this->heapSize - 1) / 2) {
                int c1 = h[i*2];
                int c2 = h[i*2 + 1];
                if(h[i] > c1 || h[i] > c2) {
                    int temp = h[i];
                    int j = (c1 < c2) ? (i * 2) : (i * 2 + 1);

                    h[i] = h[j];
                    h[j] = temp;
                    i = j;
                } else {
                    break;
                }
            }
            if(i == heapSize/2 && h[i] > h[2*i]) {
                int temp = h[i];
                h[i] = h[2*i];
                h[2*i] = temp;
            }
        }

        return result;
    }
};

void
heapTest()
{

    int numTests = 1;
    int countItems = 0;
    for (int i = 0; i < numTests; ++i)
    {
#if 1
        // int arrSize = Rand.next(500000, 1000000);
        int arrSize = 1'000'000'000;
        int *arr = new int[arrSize];
        for (int i = 0; i < arrSize; ++i)
        {
            arr[i] = Rand.next(1, 510000);
        }
#else
        int arr[] = {981, 977, 916, 910, 954, 790, 806, 901, 857, 736, 899,
                     697, 725, 478, 770, 777, 618, 601, 245, 729, 445, 585,
                     737, 464, 300, 692, 646, 372, 476, 398, 713, 765, 462,
                     232, 420, 302, 592, 50,  152, 229, 575, 151, 287, 326,
                     441, 149, 167, 116, 208, 123, 259, 294, 680, 88,  332,
                     74,  109, 231, 442, 187, 10,  370, 364, 122, 310, 184,
                     146, 123, 225, 42,  374, 252, 259, 183, 477, 42};
        int arrSize = ARRAY_SIZE(arr);
#endif
        int randType = Rand.next(1, 3);
        ASSERT(randType == 1 || randType == 2);

        heap h{arr, arrSize, (heap_type)randType};
        // std::cout << "the max heap is: \n";
        // h.display();
        h.verify();

        std::vector<int> heapSorted;
        int c = h.heapSize;
        for (int i = 0; i < c; ++i)
        {
            heapSorted.push_back(h.removeOne());
        }

        // std::cout << "heap sorted array is: \n";
        ASSERT(heapSorted.size() == arrSize);
        for (int i = 0; i < heapSorted.size() - 1; ++i)
        {
            ASSERT(heapSorted[i] > 0);
            if (h.type == heap_type::MIN_HEAP)
            {
                ASSERT(heapSorted[i] <= heapSorted[i + 1]);
            }
            else if (h.type == heap_type::MAX_HEAP)
            {
                ASSERT(heapSorted[i] >= heapSorted[i + 1]);
            }
            // std::cout << heapSorted[i] << ", ";
        }
        // std::cout << std::endl;
        std::cout << "End of test " << (i + 1) << ".\n";
        countItems += arrSize;
        std::cout << "Counter Value: " << countItems << ".'\n";
        delete[] arr;
    }
}

#define HEAP_H
#endif