#include "Fixed.hpp"

Fixed::Fixed() : value(0) 
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : value(other.value)
{
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed::Fixed(const int intval) : value(intval << Fixed::fractionalBits)
{
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float flotval) : value(static_cast<int>(roundf(flotval * (1 << Fixed::fractionalBits))))
{
  std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
  std::cout << "Copy assignment operator called" << std::endl;
  if(this != &other)
     this->value = other.getRawBits();
  return *this;
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
  return (float)this->value / (1 << fractionalBits);
}

int Fixed::toInt( void ) const
{
  return this->value >> fractionalBits;
}

int Fixed::getRawBits(void) const
{
  return this->value;
}

void Fixed::setRawBits(int const raw)
{
  this->value = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& f)
{
    out << f.toFloat(); // كنطبع القيمة كـ float
    return out;         // كنرجع stream باش نقدر نزيد نطبع من بعد
}
