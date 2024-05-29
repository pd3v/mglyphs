#include <iostream>
#include "diatonic.h"

using namespace scale_;

int main() {
  std::cout << "c++ and actions + submodule diatonic" << std::endl;

  // create D# Major scale
  //auto DSharpMajor = scale(Ds,scale_::major);
  //std::cout << "D# Major tonic note is:" << DSharpMajor.at(0) << std::endl;
  //std::cout << "D# Major major 3rd note is:" << DSharpMajor.at(4) << std::endl;

	// create scales
	auto DSharpMajor = scale(Ds,scale_::major);
 	auto DSharpPentaMajorOctave4 = scale("a1",scale_::pentatonicminor);
	for (auto& note : DSharpPentaMajorOctave4)
		std::cout << note << '\n';

  return 0;
}
