#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

std::vector<int> reverseArray(std::vector<int> &a) {
    int temp;
    int n = a.size() - 1, i = 0;
    /* for (int i = 0; i != a.size(); ++i) */
    /* { */
    /*     if (i < n) */
    /*     { */
    /*         temp = a[i]; */
    /*         a[i] = a[n]; */
    /*         a[n - 1] = temp; */
    /*     } */
    /*     --n; */
    /* } */
    while (i < n)
    {
        temp = a[i];
        a[i] = a[n];
        a[n] = temp;
        ++i;
        --n;
    }
    return a;
}

std::string removeSpace(const std::string &x)
{
    std::string ans;
    for (decltype(x.size()) i = 0; i != x.size(); ++i)
    {
        if (x[i] != ' ')
            ans.push_back(x[i]);
    }
    return ans;
}

int main()
{
    std::cout << removeSpace("8 j 8   mBliB8g  imjB8B8  jl  B");
    return 0;
}
