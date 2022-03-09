#include <cstdlib>  // needed for EXIT_SUCCESS and EXIT_FAILURE
#include <iostream> // needed for std::cout and std::cin
#include <limits>   // needed for std::numeric_limits

void ignoreLine()
{
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

float calculateTorus(float minorRadius, float majorRadius)
{
  // This program will use 3.14 for pi, as it doesn't need to be super acccurate
  float pi { 3.14 };

  /* The two statements below could be combined, but I find returning a variable
  instead of a compute value to be more readable */
  float calculatedVolume { ( pi * ( minorRadius * minorRadius ) ) * ( 2 * pi * majorRadius ) };
  return calculatedVolume;
}

float getFloat()
{
  while (true) // loop until a value is returned.
  {
    std::cout << "Enter a float value: ";
    float val{};
    std::cin >> val;

    if (std::cin.fail())
    {
      std::cin.clear(); // clear the error and go back to normal operation
      ignoreLine();
      std::cout << "Not valid input, try again!" << '\n';
    }
    else
    {
      ignoreLine(); // ignore extraneous input
      return val;
    }
  }
}

int main()
{
  /* I want the program to exit with a failure error code if it doesn't succeed,
  and I don't want multiple return statements, so I need to return a variable
  that represents the exit status */
  int statusToReturn{};

  std::cout << "This program will calculate the volume of a torus." << '\n';
  std::cout << "You will start by entering a value for the minor radius." << '\n';
  float minorRadiusInput{ getFloat() };

  std::cout << "Next, you will enter a value for the major radius." << '\n';
  float majorRadiusInput{ getFloat() };

  // The major radius of a torus is larger than the minor radius, so check that!
  if (minorRadiusInput < majorRadiusInput)
  {
    /* This is another variable only used once, but it's much more readable than
    calling the function in the print statement */
    float volume{ calculateTorus(minorRadiusInput, majorRadiusInput) };

    std::cout << "Your calculated torus volume is: "
    << volume
    << '\n';
    // The calculation succeeded, so we want the exit code to reflect that
    statusToReturn = EXIT_SUCCESS;
  }
  else
  {
    std::cerr << "ERROR: Your major radius needs to be larger than your minor radius. "
              << "You will need to start again!"
              << '\n';
    // The code failed, so we want the program to exit with an error
    statusToReturn = EXIT_FAILURE;
  }

  return statusToReturn;
}
