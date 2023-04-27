#include "sources/Fraction.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

int main() {
  // Create some fractions
  Fraction a(1, 2);
  Fraction b(3, 4);
  Fraction c(1.5);
  Fraction d(0, 1);

  // Print the fractions
  cout << "a = " << a.getNumerator() << "/" << a.getDenominator() << endl;
  cout << "b = " << b.getNumerator() << "/" << b.getDenominator() << endl;
  cout << "c = " << c.getNumerator() << "/" << c.getDenominator() << endl;
  cout << "d = " << d.getNumerator() << "/" << d.getDenominator() << endl;

  // Add and subtract fractions
  Fraction e = a + b;
  Fraction f = a - b;
  cout << "a + b = " << e << endl;
  cout << "a - b = " << f << endl;

  // Multiply and divide fractions
  Fraction g = a * b;
  Fraction h = a / b;
  cout << "a * b = " << g << endl;
  cout << "a / b = " << h << endl;

  // Compare fractions
  cout << "a == b: " << (a == b) << endl;
  cout << "a != b: " << (a != b) << endl;
  cout << "a > b: " << (a > b) << endl;
  cout << "a < b: " << (a < b) << endl;
  cout << "a >= b: " << (a >= b) << endl;
  cout << "a <= b: " << (a <= b) << endl;

  // Increment and decrement fractions
  a++;
  b--;
  cout << "a++ = " << a << endl;
  cout << "b-- = " << b << endl;

  return 0;
}
