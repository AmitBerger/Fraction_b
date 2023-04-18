#include "doctest.h"
#include "sources/Fraction.hpp"
#include <sstream>
#include <string>
using namespace ariel;
using namespace std;

TEST_CASE("Default constructor") {
  Fraction f;
  CHECK(f.getNumerator() == 0);
  CHECK(f.getDenominator() == 1);
}

TEST_CASE("Constructor with integer parameters") {
  Fraction f(2, 3);
  CHECK(f.getNumerator() == 2);
  CHECK(f.getDenominator() == 3);
}

TEST_CASE("Constructor with floating-point parameter") {
  Fraction f(0.5);
  CHECK(f.getNumerator() == 1);
  CHECK(f.getDenominator() == 2);
}

TEST_CASE("Addition operator") {
  Fraction f1(1, 2);
  Fraction f2(1, 3);
  Fraction f3 = f1 + f2;
  CHECK(f3.getNumerator() == 5);
  CHECK(f3.getDenominator() == 6);
}

TEST_CASE("Subtraction operator") {
  Fraction f1(1, 2);
  Fraction f2(1, 3);
  Fraction f3 = f1 - f2;
  CHECK(f3.getNumerator() == 1);
  CHECK(f3.getDenominator() == 6);
}

TEST_CASE("Multiplication operator") {
  Fraction f1(2, 3);
  Fraction f2(3, 4);
  Fraction f3 = f1 * f2;
  CHECK(f3.getNumerator() == 1);
  CHECK(f3.getDenominator() == 2);
}

TEST_CASE("Division operator") {
  Fraction f1(2, 3);
  Fraction f2(3, 4);
  Fraction f3 = f1 / f2;
  CHECK(f3.getNumerator() == 8);
  CHECK(f3.getDenominator() == 9);
}

TEST_CASE("Equality operator") {
  Fraction f1(1, 2);
  Fraction f2(2, 4);
  CHECK(f1 == f2);
}

TEST_CASE("Inequality operator") {
  Fraction f1(1, 2);
  Fraction f2(2, 3);
  CHECK(f1 != f2);
}

TEST_CASE("Greater than operator") {
  Fraction f1(3, 4);
  Fraction f2(1, 2);
  CHECK(f1 > f2);
}

TEST_CASE("Less than operator") {
  Fraction f1(1, 2);
  Fraction f2(3, 4);
  CHECK(f1 < f2);
}

TEST_CASE("Greater than or equal to operator") {
  Fraction f1(3, 4);
  Fraction f2(1, 2);
  Fraction f3(3, 4);
  CHECK(f1 >= f2);
  CHECK(f1 >= f3);
}

TEST_CASE("Less than or equal to operator") {
  Fraction f1(1, 2);
  Fraction f2(3, 4);
  Fraction f3(1, 2);
  CHECK(f1 <= f2);
  CHECK(f1 <= f3);
}

TEST_CASE("Prefix increment operator") {
  Fraction f(1, 2);
  ++f;
  CHECK(f.getNumerator() == 3);
  CHECK(f.getDenominator() == 2);
}

TEST_CASE("Postfix increment operator") {
  Fraction f(1, 2);
  Fraction f2 = f++;
  CHECK(f2.getNumerator() == 1);
  CHECK(f2.getDenominator() == 2);
  CHECK(f.getNumerator() == 3);
  CHECK(f.getDenominator() == 2);
}
TEST_CASE("Prefix dincrement operator") {
  Fraction f(3, 2);
  --f;
  CHECK(f.getNumerator() == 1);
  CHECK(f.getDenominator() == 2);
}

TEST_CASE("Postfix dincrement operator") {
  Fraction f(3, 2);
  Fraction f2 = f--;
  CHECK(f2.getNumerator() == 3);
  CHECK(f2.getDenominator() == 2);
  CHECK(f.getNumerator() == 1);
  CHECK(f.getDenominator() == 2);
}
TEST_CASE("reduce method") {
  Fraction a(100, 50);
  Fraction b(50, 100);
  Fraction c(3, 9);
  Fraction d(4, 6);
  Fraction e(8, 32);
  // Fraction f(0, 0);

  CHECK(a.getNumerator() == 2);
  CHECK(a.getDenominator() == 1);
  CHECK(b.getNumerator() == 1);
  CHECK(b.getDenominator() == 2);
  CHECK(c.getNumerator() == 1);
  CHECK(c.getDenominator() == 3);
  CHECK(d.getNumerator() == 2);
  CHECK(d.getDenominator() == 3);
  CHECK(e.getNumerator() == 1);
  CHECK(e.getDenominator() == 4);
  CHECK_THROWS(Fraction(0, 0));
}
TEST_CASE("Fraction input operator >>") {
  Fraction frac;
  stringstream input("3/4");

  input >> frac;

  CHECK(frac.getNumerator() == 3);
  CHECK(frac.getDenominator() == 4);
}

TEST_CASE("Fraction input operator >> with zero denominator") {
  Fraction frac;
  stringstream input("3/0");

  CHECK_THROWS(input >> frac);
}

TEST_CASE("Fraction output operator <<") {
  Fraction frac(3, 4);
  Fraction f1{};
  Fraction f2{};
  Fraction f3{};
  Fraction f4{};
  Fraction f5{};
  Fraction f6{};
  stringstream output;

  output << frac;

  CHECK(output.str() == "3/4");

  istringstream iss1{"1/2"};
  iss1 >> f1;
  CHECK(f1 == Fraction(1, 2));

  istringstream iss2{"2/3"};
  iss2 >> f2;
  CHECK(f2 == Fraction(2, 3));

  istringstream iss3{"-1/2"};
  iss3 >> f3;
  CHECK(f3 == Fraction(-1, 2));

  istringstream iss4{"1/-2"};
  iss4 >> f4;
  CHECK(f4 == Fraction(-1, 2));

  istringstream iss5{"-1/-2"};
  iss5 >> f5;
  CHECK(f5 == Fraction(1, 2));

  istringstream iss6{"0/5"};
  iss6 >> f6;
  CHECK(f6 == Fraction(0, 1));
}

TEST_CASE("Fraction output operator << with negative fraction") {
  Fraction frac(-3, 4);
  Fraction f1{1, 2};
  Fraction f2{2, 3};
  Fraction f3{-1, 2};
  Fraction f4{1, -2};
  Fraction f5{-1, -2};
  Fraction f6{0, 5};
  stringstream output;

  output << frac;

  CHECK(output.str() == "-3/4");

  ostringstream oss1;
  oss1 << f1;
  CHECK(oss1.str() == "1/2");

  ostringstream oss2;
  oss2 << f2;
  CHECK(oss2.str() == "2/3");

  ostringstream oss3;
  oss3 << f3;
  CHECK(oss3.str() == "-1/2");

  ostringstream oss4;
  oss4 << f4;
  CHECK(oss4.str() == "-1/2");

  ostringstream oss5;
  oss5 << f5;
  CHECK(oss5.str() == "1/2");

  ostringstream oss6;
  oss6 << f6;
  CHECK(oss6.str() == "0/1");
}
TEST_CASE("Negative Fractions") {
  Fraction f1(-1, 3);
  Fraction f2(2, -5);
  Fraction f3(-7, -8);
  Fraction f4;

  CHECK_EQ(f1.getNumerator(), -1);
  CHECK_EQ(f1.getDenominator(), 3);
  CHECK_EQ(f2.getNumerator(), -2);
  CHECK_EQ(f2.getDenominator(), 5);
  CHECK_EQ(f3.getNumerator(), 7);
  CHECK_EQ(f3.getDenominator(), 8);

  stringstream ss1("-4/5");
  ss1 >> f4;
  CHECK_EQ(f4.getNumerator(), -4);
  CHECK_EQ(f4.getDenominator(), 5);

  stringstream ss2("3/-2");
  ss2 >> f4;
  CHECK_EQ(f4.getNumerator(), -3);
  CHECK_EQ(f4.getDenominator(), 2);
}
