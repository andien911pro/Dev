#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include "stdint.h"
#include "string.h"

constexpr size_t sz = 100;

bool kiemTraDinhDang(char *s)
{
    if (s[0] != 'D')
    {
        return 0;
    }
    if (s[1] != 'H')
    {
        return 0;
    }
    if (s[2] != '5')
    {
        return 0;
    }
    for (int i = 3; s[i] != '\0'; ++i)
    {
        if (s[i] < '0' || s[i] > '9')
            return 0;
    }
    return 1;
}

char *toUpper(char *s)
{
    s[0] -= 32;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        if ((s[i] >= 'a' || s[i] <= 'z') && s[i] == ' ')
        {
            s[i + 1] -= 32;
        }
    }
    return s;
}


char *tachTen(char *s)
{
    char *arr = new char(strlen(s) + 1);
    arr = s;
    int cnt = 0;
    int space = 0;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        if (s[i] == ' ')
            ++cnt;
    }

    for (int i = 0; s[i] != '\0'; ++i)
    {
        if (s[i] == ' ')
            ++space;
        if (space == cnt)
        {
            arr[i] = s[i + 1];
        }
    }
    for (int i = 0; i != strlen(arr); ++i)
        std::cout << arr[i];
    return arr;
}

int main()
{
    char mssv[] = "DH52005758";
    char s[] = "nguyen vu an dien";
    tachTen(s);
    /* for (int i = 0; s[i] != '\0'; ++i) */
    /*     std::cout << s[i]; */
    /* if (kiemTraDinhDang(mssv)) */
    /*     std::cout << "Dung dinh dang"; */
    /* else */
    /*     std::cout << "Sai dinh dang"; */
    return 0;
}
