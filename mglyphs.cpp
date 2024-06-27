#include <iostream>
#include <algorithm>
#include <iomanip>
#include "diatonic.h"

using namespace scale_;

void printGlyphs(const std::vector<std::string>& scaleG) {	
	std::cout << std::left;

	for (int i = 0; i < scaleG.size(); ++i)
		std::cout << "____";

	std::cout << "\n";
	std::cout << '|';

	for (auto& note : scaleG)
		std::cout << std::setw(3) << note << '|';

	std::cout << "\n";
}

void printMIDI(const scaleT& scale) {
	std::cout << '|';

	for (auto& note : scale)
		std::cout << std::setw(3) << note << '|';

	std::cout << "\n";	
	
	for (int i = 0; i < scale.size(); ++i)
		std::cout << "⎻⎻⎻⎻";

	std::cout << "\n";
}

int main(int argc, char **argv) {
	scaleT s; scaleGlyphT sG;
	std::string key = "c"; // C as default key

	if (argc > 2) {
    try {
      std::string param = argv[1];
			if (param == "-k" || param == "-key")
				key = argv[2];
			else
				std::cout << "No such parameter.\n" << std::flush;
		} catch(...) {
      std::cout << "Error in parameter.\n" << std::flush;
    }
	}

	std::cout << '\n' << key << " scales -> MIDI\n";
	std::cout << "-----------------\n";

	std::cout <<  key << " Chromatic\n";
	s = scale(key, scale_::chromatic);
	sG = scaleNotes(s);
	printGlyphs(sG);	
	printMIDI(s);
	
	std::cout << key << " Major\n";
	s = scale(key, scale_::major);
	sG = scaleNotes(s);
	printGlyphs(sG);	
	printMIDI(s);
	
	std::cout << key << " Minor\n";
	s = scale(key, scale_::minor);
	sG = scaleNotes(s);
	printGlyphs(sG);	
	printMIDI(s);
	
	std::cout << key << " Whole notes\n";
	s = scale(key, scale_::whole);
	sG = scaleNotes(s);
	printGlyphs(sG);
	printMIDI(s);

	std::cout << key << " Harmonic Minor\n";
	s = scale(key, scale_::harmonicminor);
	sG = scaleNotes(s);
	printGlyphs(sG);
	printMIDI(s);

	std::cout << key << " Pentatonic\n";
	s = scale(key, scale_::pentatonicminor);
	sG = scaleNotes(s);
	printGlyphs(sG);
	printMIDI(s);

	std::cout << key << " Blues\n";
	s = scale(key, scale_::blues);
	sG = scaleNotes(s);
	printGlyphs(sG);
	printMIDI(s);

	std::cout << '\n' << key << " modes\n";
	std::cout << "--------\n";

	std::cout << key << " Ionian\n";
	s = scale(key, scale_::ionian);
	sG = scaleNotes(s);
	printGlyphs(sG);
	printMIDI(s);

	std::cout << key << " Dorian\n";
	s = scale(key, scale_::dorian);
	sG = scaleNotes(s);
	printGlyphs(sG);
	printMIDI(s);

	std::cout << key << " Phrygian\n";
	s = scale(key, scale_::phrygian);
	sG = scaleNotes(s);
	printGlyphs(sG);
	printMIDI(s);

	std::cout << key << " Lydian\n";
	s = scale(key, scale_::lydian);
	sG = scaleNotes(s);
	printGlyphs(sG);
	printMIDI(s);

	std::cout << key << " Mixolydian\n";
	s = scale(key, scale_::mixolydian);
	sG = scaleNotes(s);
	printGlyphs(sG);
	printMIDI(s);

	std::cout << key << " Aeolian\n";
	s = scale(key, scale_::aeolian);
	sG = scaleNotes(s);
	printGlyphs(sG);
	printMIDI(s);

	std::cout << key << " Locrian\n";
	s = scale(key, scale_::locrian);
	sG = scaleNotes(s);
	printGlyphs(sG);
	printMIDI(s);

  return 0;
}
