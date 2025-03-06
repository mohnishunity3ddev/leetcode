#pragma once

#include <string>
#include <iostream>
#include <string_view>
#include <vector>

std::string mergeAlternately(std::string word1, std::string word2) {
    char ret[256];
    std::vector<std::string_view> words{word1, word2};

    int flip = 0;
    int sz1=word1.size(), sz2=word2.size();
    int s[2] = {0, 0};
    int c=0;
    while (s[0]<sz1 && s[1]<sz2) {
        int i = s[flip];
        ret[c++] = (words[flip])[i];
        s[flip] += 1;
        flip = !flip;
    }

    while (s[0]<sz1) {
        int i = s[0];
        ret[c++] = (words[0])[i];
        s[0] += 1;
    }
    while (s[1]<sz2) {
        int i = s[1];
        ret[c++] = (words[1])[i];
        s[1] += 1;
    }
    ret[c++] = '\0';

    return std::string(ret);
}

void driver() {
    std::string word1 = "ab", word2 = "pqrs";
    std::string w = mergeAlternately(word1, word2);
    std::cout << w << std::endl;
}