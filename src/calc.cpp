#include <iostream>
#include <limits>
#include <stdlib.h>
#include <math.h>

#define PW(x) (powf(x, 2))

static const char *genericInputErr = "Wrong value. Try again:";

using namespace std;

template <typename T>
static void inputValue(T *value, const char* errStr);

int main(void) {
  float x0;
  float xn;
  float dx;
  float a;
  float b;
  float c;

  cout << "Input x0:";
  inputValue(&x0, genericInputErr);

  cout << "Input xn:";
  inputValue(&xn, genericInputErr);

  cout << "Input dx:";
  inputValue(&dx, genericInputErr);

  cout << "Input a:";
  inputValue(&a, genericInputErr);

  if (a == 0) {
    cerr << "Wrong value for a." << endl;
    exit(EXIT_FAILURE);
  }

  cout << "Input b:";
  inputValue(&b, genericInputErr);

  cout << "Input c:";
  inputValue(&c, genericInputErr);

  if (c == 0) {
    cerr << "Wrong vaue for c" << endl;
    exit(EXIT_FAILURE);
  }


  cout.width(11);
  cout.precision(3);

  cout << "X" << "\t" << "Y" << endl;

  float x;
  for (x = x0; x <= xn; x += dx) {
    double y = 0;

    if (x < 5 && b != 0) {
      y = a * PW(x + 7) - b;
    }
    else if (x > 5 && b == 0) {
      y = (x - a * c) / (a * x);
    }
    else {
      y = x / c;
    }

    cout.width(11);
    cout.precision(3);
    cout << x << "\t" << y << endl;
  }

  return 0;
}

template <typename T>
static void inputValue(T *value, const char* errStr) {
  cin >> *value;

  while (!cin.good()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cerr << errStr;
    cin >> *value;
  }
}
