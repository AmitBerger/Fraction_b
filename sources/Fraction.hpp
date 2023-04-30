#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>
#include <unistd.h>
using namespace std;
namespace ariel {

class Fraction {
private:
  int numerator;
  int denominator;

  void reduce();
  int gcd(int num, int denom);

public:
  Fraction();
  Fraction(int num, int denom);
  Fraction(float num, float denom);
  Fraction(float num);

  Fraction operator+(const Fraction &other);
  friend Fraction operator+(const float &flo_num, const Fraction &frac) {
    float num = (float)frac.numerator + flo_num * (float)frac.denominator;
    float denom = (float)frac.denominator;
    return Fraction(num, denom);
  }

  Fraction operator-(const Fraction &other);
  friend Fraction operator-(const float &flo_num, const Fraction &frac) {
    float num = flo_num * (float)frac.denominator - (float)frac.numerator;
    float denom = (float)frac.denominator;
    return Fraction(num, denom);
  }

  Fraction operator*(const Fraction &other);
  friend Fraction operator*(float flo_num, const Fraction &frac) {
    float num = flo_num * (float)frac.numerator;
    float denom = (float)frac.denominator;
    return Fraction(num, denom);
  }
  Fraction operator/(const Fraction &other);
  friend Fraction operator/(const float &flo_num, const Fraction &frac) {
    if (frac.numerator == 0) {
      throw "Error: cannot divide by zero.";
      return frac;
    }
    Fraction flo_Frac(flo_num);
    float num = (float)(flo_Frac.numerator * frac.denominator);
    float denom = (float)(flo_Frac.denominator * frac.numerator);
    return Fraction(num, denom);
  }

  bool operator==(const Fraction &other) const;
  friend bool operator==(float flo_num, const Fraction &frac) {
    Fraction num(flo_num);
    return (num == frac);
  }
  friend bool operator==(const Fraction &frac, float flo_num) {
    Fraction num(flo_num);
    return (num == frac);
  }
  bool operator!=(const Fraction &other) const;

  bool operator>(const Fraction &other) const;
  friend bool operator>(float flo_num, const Fraction &frac) {
    Fraction num(flo_num);
    return (num > frac);
  }
  friend bool operator>(const Fraction &frac, float flo_num) {
    Fraction num(flo_num);
    return (frac > num);
  }

  bool operator<(const Fraction &other) const;
  friend bool operator<(float flo_num, const Fraction &frac) {
    Fraction num(flo_num);
    return (num < frac);
  }
  friend bool operator<(const Fraction &frac, float flo_num) {
    Fraction num(flo_num);
    return (frac < num);
  }

  bool operator>=(const Fraction &other) const;
  friend bool operator>=(float flo_num, const Fraction &frac) {
    Fraction num(flo_num);
    return (num >= frac);
  }
  friend bool operator>=(const Fraction &frac, float flo_num) {
    Fraction num(flo_num);
    return (frac >= num);
  }

  bool operator<=(const Fraction &other) const;
  friend bool operator<=(float flo_num, const Fraction &frac) {
    Fraction num(flo_num);
    return (num <= frac);
  }
  friend bool operator<=(const Fraction &frac, float flo_num) {
    Fraction num(flo_num);
    return (frac <= num);
  }
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

    if (!(istr >> num >> denom)) {
      throw runtime_error("Invalid input format");
    }

    if (denom == 0) {
      throw runtime_error("Divide by zero");
    }

    frac = Fraction(num, denom);
    frac.reduce();

    return istr;
  }

  int getNumerator();
  int getDenominator();
};
} // namespace ariel
#endif