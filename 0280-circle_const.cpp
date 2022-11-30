// circle_const.cpp
#include <iostream>
#include <cstdlib>
using namespace std;

// Определение своей функции-предиката.
// проверить попадание в круг
bool in_circle(float x, float y,
  float cx, float cy, float r)
  // координаты центра круга и его радиус
{
  // Константы -- после инициализации значения не изменяются.
  const float dx = x - cx,
              dy = y - cy;

  return dx * dx + dy * dy <= r * r;
}

int main()
{
  cout << "Enter a sequence of coordinates x, y: ";
  // Определение переменных; условие продолжения; последнее действие на каждом повторении.
  for (float x, y; cin >> x >> y;)
  {
    const bool within_the_circle = in_circle(x, y, 1, -1, 3);
    cout << "(x, y) within the circle == " << within_the_circle << endl;
  }
  return EXIT_SUCCESS;
}