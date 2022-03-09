#include <iostream>

float calculateTorus(float minorRadius, float majorRadius)
{
  // this program will use 3.14 for pi, as it doesn't need to be super acccurate
  return ( 3.14 * ( minorRadius * minorRadius ) ) * ( 2 * 3.14 * majorRadius );
}

int main()
{
  std::cout << "Enter minor radius: ";
  int minorRadiusInput { };
  std::cin >> minorRadiusInput;

  std::cout << "Enter major radius: ";
  int majorRadiusInput { };
  std::cin >> majorRadiusInput;

  if (minorRadiusInput < majorRadiusInput)
  {
    std::cout << "Your calculated torus volume is: "
    << calculateTorus(minorRadiusInput, majorRadiusInput)
    << '\n';
  }
  else
  {
    std::cerr << "ERROR: Your major radius needs to be larger than your minor radius"
    << '\n';
  }

  return 0;
}
