#include <iostream>
#include <algorithm>
#include <iomanip>
#include "diatonic.h"

using namespace scale_; 

void printGlyphs(const scaleGlyphT& scaleG) {	
	std::cout << std::left;

	for (int i = 0; i < scaleG.size(); ++i)
		std::cout << "____";

	std::cout << "\n";
	std::cout << '|';

	for (auto& note : scaleG)
		std::cout << std::setw(3) << note << '|';

	std::cout << "\n";
}

void printGlyphs(const toneGlyphT& toneG) {	
	int i = 0;
	std::cout << std::left;
	std::cout << "\n";

	for (auto& chordG : toneG)
		std::cout << "_" << std::setfill('_') << std::setw(12)  << idxChordPos.at(i++);

	std::cout << "\n";
	std::cout << '|';

	for (auto& chordG : toneG) {
		for (auto& note : chordG)
			std::cout << std::setfill(' ') << std::setw(3) << note;
		std::cout << '|';
	}

	std::cout << "\n";
}

void printMIDI(const scaleT& scale) {
	std::cout << '|';

	for (auto& note : scale)
		std::cout << std::setw(3) << note << '|';

	std::cout << "\n";	
	
	for (auto& note : scale)
		std::cout << "⎻⎻⎻⎻";

	std::cout << "\n";
}

void printMIDI(const toneT& tone) {
	std::cout << '|';

	for (auto& chord : tone) {
		for (auto& note : chord)
			std::cout << std::setw(3) << note;
		std::cout << '|';
	}
	std::cout << "\n";	
	
	for (auto& chord : tone) {
		for (auto& note : chord)
			std::cout << "⎻⎻⎻";
		std::cout << "⎻";
	}

	std::cout << "\n";
}

int main(int argc, char **argv) {
	std::string param;
	std::string key = "c"; // C as default key

	if (argc > 2) {
    try {
      param = argv[1];
			
			if (param == "-s" || param == "-scales")
				key = argv[2];
			else if (param == "-c" || param == "-chords") 	
				key = argv[2];
			else
				std::cout << "No such parameter.\n" << std::flush;
		} catch(...) {
      std::cout << "Error in parameter.\n" << std::flush;
    }
	}

	if (param == "-s" || param == "-scales") {
		scaleT s; scaleGlyphT sG;

		std::cout << '\n' << key << " scales -> MIDI\n";
		std::cout << "-----------------\n";

		std::cout <<  key << " Chromatic\n";
		s = scale(key, chromatic);
		sG = toGlyphs(s);
		printGlyphs(sG);	
		printMIDI(s);
		
		std::cout << key << " Major\n";
		s = scale(key, scale_::major);
		sG = toGlyphs(s);
		printGlyphs(sG);	
		printMIDI(s);
		
		std::cout << key << " Minor\n";
		s = scale(key, scale_::minor);
		sG = toGlyphs(s);
		printGlyphs(sG);	
		printMIDI(s);
		
		std::cout << key << " Whole notes\n";
		s = scale(key, scale_::whole);
		sG = toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << key << " Harmonic Minor\n";
		s = scale(key, scale_::harmonicminor);
		sG = toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << key << " Pentatonic Major\n";
		s = scale(key, scale_::pentatonicmajor);
		sG = toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << key << " Pentatonic (Minor)\n";
		s = scale(key, scale_::pentatonicminor);
		sG = toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << key << " Blues\n";
		s = scale(key, scale_::blues);
		sG = toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << '\n' << key << " modes\n";
		std::cout << "--------\n";

		std::cout << key << " Ionian\n";
		s = scale(key, scale_::ionian);
		sG = toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << key << " Dorian\n";
		s = scale(key, scale_::dorian);
		sG = toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << key << " Phrygian\n";
		s = scale(key, scale_::phrygian);
		sG = toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << key << " Lydian\n";
		s = scale(key, scale_::lydian);
		sG = toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << key << " Mixolydian\n";
		s = scale(key, scale_::mixolydian);
		sG = toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << key << " Aeolian\n";
		s = scale(key, scale_::aeolian);
		sG = toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << key << " Locrian\n";
		s = scale(key, scale_::locrian);
		sG = toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);
	} 
	else if (param == "-c" || param == "-chords") {
		toneT tChords; toneGlyphT tG;

		std::cout << '\n' << key << " chords -> MIDI\n";
		std::cout << "-----------------\n";

		std::cout << key << " Chromatic\n";
		tChords = tone_::tone(key, tone_::chromatic);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);

		std::cout << key << " Major\n";
		tChords = tone_::tone(key, tone_::major);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);

		std::cout << key << " Minor\n";
		tChords = tone_::tone(key, tone_::minor);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
		
		std::cout << key << " Whole notes\n";
		tChords = tone_::tone(key, tone_::whole);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
		
		std::cout << key << " Harmonic Minor\n";
		tChords = tone_::tone(key, tone_::harmonicminor);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
		
		std::cout << key << " Pentatonic\n";
		tChords = tone_::tone(key, tone_::pentatonicminor);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
		
		std::cout << key << " Blues\n";
		tChords = tone_::tone(key, tone_::blues);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
		
		std::cout << '\n' << key << " modes\n";
		std::cout << "--------\n";

		std::cout << key << " Ionian\n";
		tChords = tone_::tone(key, tone_::ionian);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
		
		std::cout << key << " Dorian\n";
		tChords = tone_::tone(key, tone_::dorian);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
	
		std::cout << key << " Phrygian\n";
		tChords = tone_::tone(key, tone_::phrygian);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
		
		std::cout << key << " Lydian\n";
		tChords = tone_::tone(key, tone_::lydian);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
		
		std::cout << key << " Mixolydian\n";
		tChords = tone_::tone(key, tone_::mixolydian);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
		
		std::cout << key << " Aeolian\n";
		tChords = tone_::tone(key, tone_::aeolian);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
		
		std::cout << key << " Locrian\n";
		tChords = tone_::tone(key, tone_::locrian);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
	}

 return 0;
}
