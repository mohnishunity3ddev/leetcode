#if !defined(LongestSubstringWORepeat_H)

// NOTE:
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <string>
using namespace std;

class Solution
{
  public:
    int
    lengthOfLongestSubstring(string s)
    {
        int sLen = s.size();

        // start is the start of a substring with individual characters
        int start = 0;
        // the max length of a substring we have seen so far satisfying the
        // condition we have for the substring
        int maxLen = 0;
        // running length so far (in the loop) for the current substring we are
        // tracking for.
        int runningLen = 0;

        for (int i = 0; i < sLen; ++i)
        {
            // Check from the start of this substring whether there is any
            // character that is equal to the character we have encountered here
            // in this new iteration of the loop where we have advanced one in
            // the string
            for (int j = start; j < i; ++j)
            {
                // If we have found a character equal to the current char we are
                // looking at, that means the substring cannot go on running. We
                // have to cut it. start of the new substring with distinct
                // characters one more than the j's index. This will be the
                // start of a new substring we will be tracking the running Len
                // for.
                if (s[j] == s[i])
                {
                    // Since we have finished tracking this substring, here we
                    // check whether it is more than the global max we have seen
                    // so far, if so, set the max value.
                    if(runningLen > maxLen)
                    {
                        maxLen = runningLen;
                    }

                    // The start of the new substring will from the j's next index.
                    start = j + 1;
                    // since previously we were already including the j'th
                    // character here. Since now we find that j'th and ith cant
                    // be part of the same substring since they are equal, we
                    // cut out the part of the substring starting from the
                    // 'start' till j from the current substring we are looking
                    // at.
                    runningLen = i - start;
                    break;
                }
            }

            // Since we have gone one up a char, we increment the running length
            // of the substring by 1.
            ++runningLen;
        }

        // It can be that we have gone through the entire without once looking
        // at a duplicate charac. or no duplicate till the end of the string
        // since the last duplicate that we saw(and updated maxLen there inside
        // the for-loop).
        if (runningLen > maxLen)
        {
            maxLen = runningLen;
        }

        return maxLen;
    }

    void
    driver()
    {
        std::string myString(" ");
        auto res = lengthOfLongestSubstring(myString);

        printf("Length of longest substring in %s without repeating characters "
               "is: %d",
               myString.c_str(), res);
    }
};

#define LongestSubstringWORepeat_H
#endif