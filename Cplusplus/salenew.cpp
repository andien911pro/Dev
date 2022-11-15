#include <iostream>
#include "SS-new.h"
#include "salenewsource.cpp"

using namespace std;

int main()
/*
{
    sales_data a;
    print(std::cout, a);

    sales_data a1("1a");
    print(std::cout, a1);

    sales_data a2("2a", 10);
    print(std::cout, a2);

    sales_data a3("3a", 10, 5);
    print(std::cout, a3);
}
*/

{
	sales_data total;
	if (read(cin, total))
	{
        sales_data trans;
        while (read(cin, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(cout, total);
                total = trans;
            }
        }
        print(cout, total);
        return 0;
	}
	else
	{
        cerr<<"No data"<<std::endl;
	}
}
