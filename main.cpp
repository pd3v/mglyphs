#include <iostream>
#include "diatonic.h"

using namespace scale_;

void printMIDI(const scaleT& scale) {
	for (auto& note : scale)
		std::cout << note << ' ';

	std::cout << '\n';
}

int main() {

  // create D# Major scale
  //auto DSharpMajor = scale(Ds,scale_::major);
  //std::cout << "D# Major tonic note is:" << DSharpMajor.at(0) << std::endl;
  //std::cout << "D# Major major 3rd note is:" << DSharpMajor.at(4) << std::endl;

	// create scales
	// auto CMajorScale = scale(C,scale_::major);
 	//auto DSharpPentaMajorOctave4 = scale("a1",scale_::pentatonicminor);

	std::cout << "\nscales MIDI notes\n-----------------\n\n";

	std::cout << "C Chromatic scale:\t";
	printMIDI(scale(C,scale_::chromatic));
	
	std::cout << "C Major scale:\t\t";
	printMIDI(scale(C,scale_::major));
	
	std::cout << "C Minor scale:\t\t";
	printMIDI(scale(C,scale_::minor));

	std::cout << "C Whole notes scale:\t";
	printMIDI(scale(C,scale_::whole));

	std::cout << "C Harmonic Minor scale:\t";
	printMIDI(scale(C,scale_::harmonicminor));

	std::cout << "C Pentatonic scale:\t";
	printMIDI(scale(C,scale_::pentatonicminor));
	
	std::cout << '\n';
	
  return 0;
}
