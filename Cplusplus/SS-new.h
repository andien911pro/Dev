#ifndef SS-new_H_INCLUDED
#define SS-new_H_INCLUDED

#include <iostream>
#include <string>

/*
class sales_data;
std::istream &read(std::istream &is, sales_data &data );
std::ostream &print(std::ostream &os,const sales_data &data);
*/

class sales_data
{
 friend std::istream &read(std::istream &is, sales_data & );
 friend std::ostream &print(std::ostream &os, const sales_data &);

 public:
    sales_data() : barCode(""), units_sold(0), revenue(0.0) {}
    sales_data(const std::string &s): barCode(s) {}
    sales_data(const std::string &s, unsigned n) :
            barCode(s), units_sold(n) {}
    sales_data(const std::string &s, unsigned n, double p) :
            barCode(s), units_sold(n), revenue(p*n) {}
    sales_data(std::istream &is);
    std::string isbn() const {return barCode;}
    sales_data &combine (const sales_data &);

private:
    std::string barCode;
    unsigned units_sold ;
    double price ;
    double revenue ;

    double averagePrice () const;

};

/*
std::istream &read(std::istream &is, sales_data &data );
std::ostream &print(std::ostream &os,const sales_data &data);
*/
#endif // SS-new_H_INCLUDED
