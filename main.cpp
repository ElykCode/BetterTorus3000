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

  // this is another variable only used once, but it's much more readable than
  // calling the function in the print statement
  float volume{ calculateTorus(minorRadiusInput, majorRadiusInput) };

  // The major radius of a torus is larger than the minor radius, so check that!
  if (minorRadiusInput < majorRadiusInput)
  {
    std::cout << "Your calculated torus volume is: "
    << volume
    << '\n';
  }
  else
  {
    std::cerr << "ERROR: Your major radius needs to be larger than your minor radius"
    << '\n';
  }

  return 0;
}
