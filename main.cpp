#include <cstdlib>  // needed for EXIT_SUCCESS and EXIT_FAILURE
#include <iostream> // needed for cout and cin

float calculateTorus(float minorRadius, float majorRadius)
{
  // This program will use 3.14 for pi, as it doesn't need to be super acccurate
  float pi { 3.14 };
  // The two statements below could be combined, but I find returning a variable
  // instead of a compute value to be more readable

  float calculatedVolume { ( pi * ( minorRadius * minorRadius ) ) * ( 2 * pi * majorRadius ) };
  return calculatedVolume;
}

int main()
{
  // I want the program to exit with a failure error code if it doesn't succeed,
  // and I don't want multiple return statements, so I need to return a variable
  // that represents the exit status
  int statusToReturn{ };

  std::cout << "Enter minor radius: ";
  int minorRadiusInput{};
  std::cin >> minorRadiusInput;

  std::cout << "Enter major radius: ";
  int majorRadiusInput{};
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
    // the calculation succeeded, so we want the exit code to reflect that
    statusToReturn = { EXIT_SUCCESS };
  }
  else
  {
    std::cerr << "ERROR: Your major radius needs to be larger than your minor radius"
    << '\n';
    // The code failed, so we want the program to exit with an error
    statusToReturn = { EXIT_FAILURE };
  }

  return statusToReturn;
}
