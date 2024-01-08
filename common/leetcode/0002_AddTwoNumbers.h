#if !defined(ADDTWONUMBERS_H)

// NOTE: Problem Link: https://leetcode.com/problems/add-two-numbers/
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
  private:
    void
    printNum(const ListNode *s)
    {
        const ListNode *t = s;
        while (t != nullptr)
        {
            printf("%d", t->val);
            t = t->next;
        }
        printf(".\n");
    }

  public:
    ListNode *
    addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *pL1 = l1, *pL2 = l2;
        int carry = 0;
        int Num[128];
        int nDigits = 0;

        while(pL1 != nullptr && pL2 != nullptr)
        {
            int sum = (pL1->val + pL2->val) + carry;
            carry = (sum / 10);
            int n = sum - 10*carry;

            Num[nDigits++] = n;

            pL1 = pL1->next;
            pL2 = pL2->next;
        }

        while(pL1 != nullptr)
        {
            int sum = (pL1->val + carry);
            carry = sum / 10;
            int n = sum - 10*carry;

            Num[nDigits++] = n;

            pL1 = pL1->next;
        }

        while(pL2 != nullptr)
        {
            int sum = (pL2->val + carry);
            carry = sum / 10;
            int n = sum - 10*carry;
            Num[nDigits++] = n;
            pL2 = pL2->next;
        }

        if(carry)
        {
            Num[nDigits++] = carry;
        }

        ListNode *result = nullptr;

        for(int i = (nDigits-1); i >= 0; --i)
        {
            result = new ListNode(Num[i], result);
        }

        return result;
    }

    void
    driver()
    {
        // 243
        ListNode *s1 = new ListNode(0);
        // s1 = new ListNode(9, s1);
        // s1 = new ListNode(9, s1);
        // s1 = new ListNode(9, s1);
        // s1 = new ListNode(9, s1);
        // s1 = new ListNode(9, s1);
        // s1 = new ListNode(9, s1);
        // s1 = new ListNode(3, s1);
        // s1 = new ListNode(7, s1);
        // s1 = new ListNode(9, s1);
        // s1 = new ListNode(8, s1);
        // s1 = new ListNode(4, s1);
        // s1 = new ListNode(3, s1);
        // s1 = new ListNode(2, s1);
        // s1 = new ListNode(7, s1);
        printf("first number is: ");
        printNum(s1);

        ListNode *s2 = new ListNode(0);
        // s2 = new ListNode(9, s2);
        // s2 = new ListNode(9, s2);
        // s2 = new ListNode(9, s2);
        // s2 = new ListNode(3, s2);
        // s2 = new ListNode(0, s2);
        // s2 = new ListNode(5, s2);
        // s2 = new ListNode(3, s2);
        // s2 = new ListNode(4, s2);
        // s2 = new ListNode(8, s2);
        printf("second number is: ");
        printNum(s2);

        ListNode *result = addTwoNumbers(s1, s2);
        printf("result is: ");
        printNum(result);
    }
};

#define ADDTWONUMBERS_H
#endif // ADDTWONUMBERS_H