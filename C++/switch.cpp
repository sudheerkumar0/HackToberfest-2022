#include <iostream>
using namespace std;

int main() {
  int day = 4;
  switch (day) {
    case 6:
      cout << "Today is Saturday";
      break;
    case 7:
      cout << "Today is Sunday";
      break;
    default:
      cout << "Looking forward to the Weekend";
  }
  return 0;
}
