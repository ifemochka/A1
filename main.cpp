#include <iostream>
#include <vector>
#include <random>

bool isInsideCircle(double x, double y, double cx, double cy, double r) {
  return (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r;
}

int main() {
  srand(time(0));
  for (int i = 100; i <= 100000; i = i + 500) {
    double left = LLONG_MAX;
    double right = LLONG_MIN;
    double bottom = LLONG_MAX;
    double up = LLONG_MIN;

    std::vector<double> x(3), y(3), r(3);
    x[0] = 1;
    y[0] = 1;
    r[0] = 1;
    x[1] = 1.5;
    y[1] = 2;
    r[1] = sqrt(5) / 2;
    x[2] = 2;
    y[2] = 1.5;
    r[2] = sqrt(5) / 2;
    for (int i = 0; i < 3; ++i) {
      if (x[i] + r[i] > right) {
        right = x[i] + r[i];
      }
      if (x[i] - r[i] < left) {
        left = x[i] - r[i];
      }
      if (y[i] + r[i] > up) {
        up = x[i] + r[i];
      }
      if (y[i] - r[i] < bottom) {
        bottom = y[i] - r[i];
      }
    }

    double square = (up - bottom) * (right - left);

    int N = i;
    int countInside = 0;

    for (int i = 0; i < N; ++i) {
      double px = static_cast<double>(rand()) / RAND_MAX * (right - left) + left;
      double py = static_cast<double>(rand()) / RAND_MAX * (up - bottom) + bottom;

      if (isInsideCircle(px, py, x[0], y[0], r[0]) &&
          isInsideCircle(px, py, x[1], y[1], r[1]) &&
          isInsideCircle(px, py, x[2], y[2], r[2])) {
        countInside++;
      }
    }

    double intersectionArea = static_cast<double>(countInside) / N * square;

    double res = 0.9445171859;
    //std::cout << i << " " << intersectionArea << "\n";
    std::cout << i << " " << intersectionArea/res << "\n";
  }
}
