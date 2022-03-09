#include <iostream>

float calculateTorus(float minorRadius, float majorRadius)
{
  // this program will use 3.14 for pi, as it doesn't need to be super acccurate
  return ( 3.14 * ( minorRadius * minorRadius ) ) * ( 2 * 3.14 * majorRadius );
}

int main()
{
  std::cout << "Torus volume is: " << calculateTorus(3, 4) << '\n';
  return 0;
}
