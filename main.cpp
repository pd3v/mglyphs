#include <iostream>
#include "externals/diatonic/include/diatonic.h"

using namespace scale_;

int main() {
  std::cout << "c++ and actions + submodule diatonic" << std::endl;

  // create scales
  auto DSharpMajor = scale(Ds,scale_::major);
  std::cout << "D# Major 2nd note is:" << DSharpMajor.at(1) << std::endl;

  return 0;
}
