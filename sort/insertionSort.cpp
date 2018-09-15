#include "insertionSort.hpp"
#include <iostream>

void insertionSort(std::vector<int> &data)
{
    if (data.empty() || data.size() == 1)
    {
        return;
    }
    for (std::vector<int>::iterator i = ++(data.begin()); i != data.end(); ++i)
    {
        std::vector<int>::iterator saveKey = i;
        for (std::vector<int>::iterator j = --saveKey; (i != data.begin()) && (*i < *j); --j, --i)
        {
            int save = *i;
            *i = *j;
            *j = save;
        }
        i = ++saveKey;
    }
    return;
}

std::vector<int> insertionSort(const std::vector<int> &data)
{
    std::vector<int> result;
    if (data.empty() || data.size() == 1)
    {
        return result;
    }
    result.push_back(*(data.begin()));
    for (auto value = ++(data.begin()); value != data.end(); ++value)
    {
        result.push_back(*value);
        std::vector<int>::iterator i = --(result.end());
        for (std::vector<int>::iterator j = --(--(result.end())); (i != result.begin()) && (*i < *j); --j, --i)
        {
            int save = *i;
            *i = *j;
            *j = save;
        }
    }
    return result;
}