#include "Fraction.hpp"

#include <cmath>
#include <stdexcept>
using namespace ariel;
using namespace std;
Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
  if (denom == 0) {
    throw runtime_error("divided by zero!");
  }
  reduce();
}
Fraction::Fraction(float num, float denom)
    : numerator(num), denominator(denom) {
  if (denom == 0) {
    throw runtime_error("divided by zero!");
  }
  int precision = 1000; // 3 digits beyond the decimal point
  int numInt = round(num * precision);

  numerator = numInt;
  denominator = precision * denom;
  reduce();
}

Fraction::Fraction(float num) {
  int precision = 1000; // 3 digits beyond the decimal point
  int numInt = round(num * precision);

  numerator = numInt;
  denominator = precision;
  reduce();
}

Fraction Fraction::operator+(const Fraction &other) {
  float num = numerator * other.denominator + other.numerator * denominator;
  float denom = denominator * other.denominator;
  reduce();
  return Fraction(num, denom);
}

Fraction Fraction::operator-(const Fraction &other) {
  float num = numerator * other.denominator - other.numerator * denominator;
  float denom = denominator * other.denominator;
  reduce();
  return Fraction(num, denom);
}

Fraction Fraction::operator*(const Fraction &other) {

  float num = numerator * other.numerator;
  float denom = denominator * other.denominator;
  reduce();
  return Fraction(num, denom);
}

Fraction Fraction::operator/(const Fraction &other) {
  int num = numerator * other.denominator;
  int denom = denominator * other.numerator;
  reduce();

  return Fraction(num, denom);
}

bool Fraction::operator==(const Fraction &other) const {
  return numerator == other.numerator && denominator == other.denominator;
}

bool Fraction::operator!=(const Fraction &other) const {
  return !(*this == other);
}

bool Fraction::operator>(const Fraction &other) const {
  return numerator * other.denominator > other.numerator * denominator;
}

bool Fraction::operator<(const Fraction &other) const {
  return numerator * other.denominator < other.numerator * denominator;
}

bool Fraction::operator>=(const Fraction &other) const {
  return numerator * other.denominator >= other.numerator * denominator;
}

bool Fraction::operator<=(const Fraction &other) const {
  return numerator * other.denominator <= other.numerator * denominator;
}

Fraction &Fraction::operator++() {
  numerator += denominator;
  reduce();

  return *this;
}

Fraction Fraction::operator++(int) {
  Fraction temp(*this);
  ++(*this);
  return temp;
}
Fraction &Fraction::operator--() {
  numerator -= denominator;
  reduce();

  return *this;
}
Fraction Fraction::operator--(int) {
  Fraction temp(*this);
  --(*this);
  return temp;
}

void Fraction::reduce() {
  if (denominator == 0) {
    cerr << "Error: denominator cannot be zero." << endl;
    return;
  }

  if (numerator == 0) {
    denominator = 1;
    return;
  }

  int sign = 1;
  if (numerator < 0) {
    sign *= -1;
    numerator *= -1;
  }

  if (denominator < 0) {
    sign *= -1;
    denominator *= -1;
  }

  int divisor = gcd(numerator, denominator);
  numerator = sign * numerator / divisor;
  denominator = denominator / divisor;
}

int Fraction::gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int Fraction::getNumerator() { return this->numerator; }
int Fraction::getDenominator() { return this->denominator; }
