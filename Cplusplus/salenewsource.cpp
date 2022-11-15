#include <iostream>
#include <string>
#include "SS-new.h"

double sales_data::averagePrice() const
{
    if(units_sold != 0)
    {
        return revenue / units_sold;
    }
    else
    {
        return 0.0;
    }
}

sales_data &sales_data::combine (const sales_data &rhs)
{
    units_sold   += rhs.units_sold;
    revenue      += rhs.revenue;
    return *this;
}

std::istream &read(std::istream &is, sales_data &data)
{
    is>>data.barCode>>data.units_sold>>data.price;
    data.revenue = data.price * data.units_sold;
    return is;
}

sales_data::sales_data (std::istream &is)
{
    read(is, *this);
}

std::ostream &print(std::ostream &os,const sales_data &data)
{
    os  << data.isbn() <<" "<< data.units_sold <<" "
        << data.revenue <<" ";
    if (data.averagePrice() != 0.0)
    {
        os<< data.averagePrice() <<std::endl;
    }
    else
    {
        os<<"No sale"<<std::endl;
    }
    return os;
}

