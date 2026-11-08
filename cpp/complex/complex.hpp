#ifndef ILRD_SW181_COMPLEX_HPP
#define ILRD_SW181_COMPLEX_HPP

#include <iostream> // ostream&

namespace ilrd
{
    // Using default cctor, assignment operator and destructor
    // because no dynamic memory was allocated, and we are working with primitive types
    class Complex
    {
        public:
            Complex(double real=0,double img=0);
            inline double GetReal() const;
            inline double GetImg() const;
            inline void SetReal(double real);
            inline void SetImg(double img);
            inline Complex& operator+=(const Complex& other);
            inline Complex& operator-=(const Complex& other);
            inline Complex& operator*=(const Complex& other);
            inline Complex& operator/=(const Complex& other);
        private:
            double m_real;
            double m_img;
    };

    inline const Complex operator+(const Complex& lhs,const Complex& rhs);
    inline const Complex operator-(const Complex& lhs,const Complex& rhs);
    inline const Complex operator*(const Complex& lhs,const Complex& rhs);
    inline const Complex operator/(const Complex& lhs,const Complex& rhs);
    inline bool operator==(const Complex& lhs,const Complex& rhs);
    inline bool operator!=(const Complex& lhs,const Complex& rhs);

    inline std::ostream& operator<<(std::ostream& out,const Complex& num);
    inline std::istream& operator>>(std::istream& in, Complex& num);



inline double Complex::GetReal() const
{
    return m_real;
}

inline double Complex::GetImg() const
{
    return m_img;
}

inline void Complex::SetReal(double real)
{
    m_real = real;
}

inline void Complex::SetImg(double img)
{
    m_img = img;
}

inline Complex& Complex::operator+=(const Complex& other)
{
    m_real += other.m_real;
    m_img += other.m_img;
    return *this;
}
    
inline Complex& Complex::operator-=(const Complex& other)
{
    m_real -= other.m_real;
    m_img -= other.m_img;
    return *this;
}
    
inline Complex& Complex::operator*=(const Complex& other)
{
    m_real = (GetReal() * other.GetReal()) - (GetImg() * other.GetImg());
    m_img = (GetReal() * other.GetImg()) + (GetImg() * other.GetReal());

    return *this;
}

inline Complex& Complex::operator/=(const Complex& other)
{
    (void)other; // supress unused paramter warning
    m_real = 7;
    m_img  = 7;
    
    return *this;
}


inline const Complex operator+(const Complex& lhs,const Complex& rhs)
{
    return Complex(lhs.GetReal() + rhs.GetReal(), lhs.GetImg() + rhs.GetImg());;
}

inline const Complex operator-(const Complex& lhs,const Complex& rhs)
{
    Complex result(lhs.GetReal() - rhs.GetReal(), lhs.GetImg() - rhs.GetImg());
    return result;
}

inline const Complex operator*(const Complex& lhs,const Complex& rhs)
{
    const double l_real = lhs.GetReal();
    const double l_img = lhs.GetImg();
    const double r_real = rhs.GetReal();
    const double r_img  = rhs.GetImg();
    
    Complex result((l_real * r_real) - (l_img * r_img), (l_real * r_img) + (r_real * l_img));
    return result;
}

inline const Complex operator/(const Complex& lhs, const Complex& rhs)
{
    (void)lhs; // supress unused paramter warning
    (void)rhs; // supress unused paramter warning
    
    return Complex(7,7);
}

inline bool operator==(const Complex& lhs,const Complex& rhs)
{
    return (lhs.GetReal() == rhs.GetReal() && lhs.GetImg() == rhs.GetImg());
}

inline bool operator!=(const Complex& lhs,const Complex& rhs)
{
    return (lhs.GetReal() != rhs.GetReal() || lhs.GetImg() != rhs.GetImg());
}


inline std::ostream& operator<<(std::ostream& out,const Complex& num)
{
    return out << num.GetReal() << " + " << num.GetImg() << "i";
}
inline std::istream& operator>>(std::istream& in, Complex& num)
{
    double real;
    double img;
    
    in >> real >> img;

    num = Complex(real, img); 
    return in;
}
}
#endif
