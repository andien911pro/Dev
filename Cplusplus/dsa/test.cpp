#include <iostream>
#include <unordered_map>
#include <vector>

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

int main()
{
    std::vector<int> a{1, 2, 3, 4};
    reverseArray(a);
    for (auto i : a)
        std::cout << i << std::endl;
    return 0;
}
