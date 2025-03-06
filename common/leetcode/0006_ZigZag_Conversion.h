#pragma once

#include <string>
#include <vector>

inline std::string zigzag_string_conversion(const std::string& s, int numRows) {
    if (numRows == 1) return s;
    
    std::vector<std::array<char, 1024>> rows(numRows);
    std::vector<int> row_running_counts(numRows, 0);
    
    int adder = 1;
    int sz = s.size();
    for (int i=0, row_index=0; i<sz; ++i) {
        rows[row_index][row_running_counts[row_index]++] = s[i];
        row_index += adder;
        if (row_index == numRows) {
            adder = -1;
            row_index = numRows - 2;
        } else if (row_index == -1) {
            adder = 1;
            row_index = 1;
        }
    }

    char buffer[1024];
    int buffer_index=0;
    for (int ri=0; ri < numRows; ++ri) 
    {
        const auto& row = rows[ri];
        const int sz = row_running_counts[ri];
        for (int i = 0; i < sz; ++i) {
            buffer[buffer_index++] = row[i];
        }
    }
    buffer[buffer_index] = '\0';
    return std::string(buffer);
}