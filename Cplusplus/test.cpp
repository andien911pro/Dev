#include <iostream>
#include <vector>
#include <unordered_map>

bool duplicate(std::vector<int> &nums)
{
    int n = nums.size();
    std::unordered_map<int, int> count;
    for (int i = 0; i != n; ++i)
        count[nums[i]]++;
    std::unordered_map<int, int>::iterator itr;
    for (itr = count.begin(); itr != count.end(); ++itr)
        if (itr->second >= 2)
            return 1;
    return 0;
}

int main()
{
    std::vector<int> numbers = {5, 6, 9 ,10, 5};
    std::cout << duplicate(numbers) << std::endl;
    return 0;
}
