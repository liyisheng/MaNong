#include <iostream>

class Complex
{
public:
    Complex(double r = 0.0, double i = 0.0) 
        : real_(r), imag_(i)
    {}

    void disp() const;

    Complex& operator +=(const Complex &rhs);
    Complex operator +(const Complex &rhs);
    Complex operator -(const Complex &rhs);
    Complex operator *(const Complex &rhs);
    Complex operator /(const Complex &rhs);
    Complex& operator++();
    Complex operator++(int);

private:
    double real_;
    double imag_;
};

void Complex::disp() const
{
    if(0 == real_)
    {
        std::cout << imag_ << "i*" << std::endl;
        return ;
    }
    if(imag_ > 0)
    {
        std::cout << real_<< " + " << imag_ << "i*" << std::endl;
    }else if(0== imag_)
    {
        std::cout << real_ << std::endl;
    }else if(imag_ < 0)
    {
        std::cout << real_ << imag_ << "i*" << std::endl;
    }
}

Complex& Complex::operator +=(const Complex & rhs)
{
    this->real_ += rhs.real_;
    this->imag_ += rhs.imag_;
    return (*this);
}

Complex Complex::operator +(const Complex &rhs)
{
    return Complex(real_ + rhs.real_, imag_ + rhs.imag_);
}
Complex Complex::operator -(const Complex &rhs)
{
    return Complex(real_ - rhs.real_, imag_ - rhs.imag_);
}

Complex Complex::operator *(const Complex &rhs)
{

    return Complex(real_ * rhs.real_ - imag_* rhs.imag_, \
                   real_ * rhs.imag_ + imag_ * rhs.real_);
}

Complex Complex::operator /(const Complex &rhs)
{
    return Complex((real_ * rhs.real_ + imag_ * rhs.imag_)/
                   (rhs.real_ * rhs.real_ + rhs.imag_ * rhs.imag_),
                   (imag_ * rhs.real_ - real_ * rhs.imag_)/
                   (rhs.real_ * rhs.real_ + rhs.imag_ * rhs.imag_)
            );
}

Complex& Complex::operator ++()
{
    std::cout << "前置++" << std::endl;
    ++real_;
    ++imag_;
    return *this;
}

Complex Complex::operator ++(int)
{
    std::cout << "后置++" << std::endl;
    Complex ctmp = (*this);
    //++(*this);
    ++real_;
    ++imag_;
    return ctmp;
}

int main(void)
{
    Complex cx1(1.0, 2.0);
    Complex cx2(3.0, 4.0);
    Complex cxResult;
    cx1.disp();
    cx2.disp();
    cxResult += cx2;
    cxResult.disp();
    cx1 += cx2;
    cx1.disp();
#if 0

    std::cout << std::endl;
    cxResult = cx1 + cx2;
    cxResult.disp();


    std::cout << std::endl;
    cxResult = cx1 - cx2;
    cxResult.disp();

    std::cout << std::endl;
    cxResult = cx1 * cx2;
    cxResult.disp();

    std::cout << std::endl;
    cxResult = cx1 * cx2;
    cxResult.disp();
    
    std::cout << std::endl;
    cxResult = cx1 / cx2;
    cxResult.disp();


    std::cout << std::endl;
    Complex cx3(1.0, 1.0), cx4(5.0, 5.0);
    cxResult = ++cx3;
    cxResult.disp();

    std::cout << std::endl;
    cxResult = cx4++;
    cxResult.disp();
#endif
    return 0;

}
