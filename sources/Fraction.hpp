#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <unistd.h>
using namespace std;
namespace ariel {

class Fraction {
private:
  int numerator;
  int denominator;

  void reduce();
  int gcd(int abra, int babra);

public:
  Fraction();
  Fraction(int num, int denom);
  Fraction(float num, float denom);
  Fraction(float num);

  Fraction operator+(const Fraction &other);
  friend Fraction operator+(const float &f, const Fraction &frac) {
    float num = frac.numerator + f * frac.denominator;
    float denom = frac.denominator;
    return Fraction(num, denom);
  }

  Fraction operator-(const Fraction &other);
  friend Fraction operator-(const float &f, const Fraction &frac) {
    float num = f * frac.denominator - frac.numerator;
    float denom = frac.denominator;
    return Fraction(num, denom);
  }

  Fraction operator*(const Fraction &other);
  friend Fraction operator*(float f, const Fraction &frac) {
    float num = f * frac.numerator;
    return Fraction(num);
  }
  Fraction operator/(const Fraction &other);
  friend Fraction operator/(const float &f, const Fraction &frac) {
    if (frac.numerator == 0) {
      throw   "Error: cannot divide by zero.";
      return frac;
    }
    float result = f / (float)frac.numerator * frac.denominator;
    return Fraction(result);
  }

  bool operator==(const Fraction &other) const;
  bool operator!=(const Fraction &other) const;
  bool operator>(const Fraction &other) const;
  bool operator<(const Fraction &other) const;
  bool operator>=(const Fraction &other) const;
  bool operator<=(const Fraction &other) const;

  Fraction &operator++();   // pre-increment
  Fraction operator++(int); // post-increment
  Fraction &operator--();   // pre-decrement
  Fraction operator--(int); // post-decrement

  friend ostream &operator<<(ostream &ostr, const Fraction &frac) {
    ostr << frac.numerator << "/" << frac.denominator;
    return ostr;
  }

  friend istream &operator>>(istream &istr, Fraction &frac) {
    int num = 0;
    int denom = 1;
    char slash = '/';

    istr >> num >> slash >> denom;

    if (denom == 0) {
      throw "Error: denominator cannot be zero.";
      return istr;
    }

    frac.numerator = num;
    frac.denominator = denom;
    frac.reduce();

    return istr;
  }
  int getNumerator();
  int getDenominator();
};
} // namespace ariel
#endif