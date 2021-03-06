#include "fraction.h"

std::ostream& operator<<(std::ostream& out, const fraction &frac)
{
    out<<frac.num;
    if(frac.denom != 1)
         out<<"/"<<frac.denom;
    return out;
}

std::istream& operator>>(std::istream& in, fraction &frac)
{
    char junk;
    std::stringstream ss;
    std::string possibleFraction;
    if(&in == &std::cin) //This means that the program is reading from the console
    {
        if(in>>possibleFraction)
        {
            if(possibleFraction.find_first_not_of("-+0123456789./") < possibleFraction.size())
                throw Error("Invalid fraction input.");
            ss<<possibleFraction;
            ss>>frac;
        }
    }
    else//Let's assume everything else is a file (for now)
    {
        // Negative check, this will allow us to change the possibleFraction into its negative counterpart.
        bool neg = false;
        if (in.peek() == '-')
        {
            in >> junk;
            neg = true;
        }

        if (in.peek() == '.') // Example ".5"
        {
            double temp;
            if (!(in >> temp))
                throw Error("Invalid fraction input.");

            temp = temp + frac.num;

            if (neg)
                temp *= -1;

            fraction a(temp);
            frac = a;
            frac.reduce();
        }
        else if (!(in>>frac.num))
            throw Error("Invalid fraction input.");
        else{
            if (in.peek() == '/')
            {
                if (neg)
                    frac.num *= -1;
                in >> junk;
                if (!(in>>frac.denom))
                    throw Error("Invalid fraction input.");
                if (frac.denom == 0)
                    throw Error("Invalid fraction input. Division by zero.");
                frac.reduce();
            } else if (in.peek() == '.') // Example "0.5"
            {
                double temp;
                if (!(in >> temp))
                    throw Error("Invalid fraction input.");

                temp = temp + frac.num;

                if (neg)
                    temp *= -1;

                fraction a(temp);
                frac = a;
                frac.reduce();
            } else
            { // This case allows us to take whole numbers (e.g. (5))
                if (neg)
                    frac.num *= -1;
            }
        }
    }
    return in;
}

fraction operator+(const fraction &x,const fraction &y)
{
    fraction result;
    int num = x.num * y.denom + y.num  * x.denom,
        denom = x.denom * y.denom;
    result.setValue(num,denom);
    return result;
}

fraction operator-(const fraction &x,const fraction &y)
{
    using namespace std;
    std::numeric_limits<int>::max();
    fraction result;
    unsigned int temp1 = x.num*y.denom;
    unsigned int temp2 = y.num*x.denom;

    unsigned int num = temp1 - temp2,
                  denom = x.denom * y.denom;
    result.setValue(num,denom);
    return result;
}

fraction operator*(const fraction &x,const fraction &y)
{
    fraction result;
    int num = x.num * y.num,
        denom = x.denom * y.denom;
    result.setValue(num,denom);
    return result;
}

fraction operator/(const fraction &x,const fraction &y)
{
    fraction result;
    int num = x.num * y.denom,
        denom = x.denom * y.num;
    result.setValue(num,denom);
    return result;
}

fraction operator^(const fraction &x,const fraction &y)
{
    double temp1 = pow(pow(x.num, y.num),1./y.denom),
            temp2 = pow(pow(x.denom, y.num),1./y.denom);
    return temp1/temp2;
}

fraction fraction::squareRoot() const
{
// babylonian algorithm
//    fraction temp, r, preGuess;

//    temp = *this;

//    fraction guess = temp/2;

//    preGuess = guess;

//    while(!(guess <= preGuess*.001))
//    {
//        r = temp/guess;
//        preGuess = guess;
//        guess = (guess+r)/2;
//    }

//    return guess;

    double dnum = sqrt(num), ddenom = sqrt(denom);
    return fraction(dnum/ddenom);
}
bool operator==(const fraction &x,const fraction &y)
{
    return x.num * y.denom == y.num * x.denom;
}

bool operator>=(const fraction &x,const fraction &y)
{
    return x.num * y.denom >= y.num * x.denom;
}

bool operator<=(const fraction &x,const fraction &y)
{
    return x.num * y.denom <= y.num * x.denom;
}

bool operator!=(const fraction &x,const fraction &y)
{
    return x.num * y.denom != y.num * x.denom;
}

bool operator<(const fraction &x,const fraction &y)
{
    return x.num * y.denom < y.num * x.denom;
}

bool operator>(const fraction &x,const fraction &y)
{
    return x.num * y.denom > y.num * x.denom;
}
