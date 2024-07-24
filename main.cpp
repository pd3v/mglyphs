#include <iostream>
#include <algorithm>
#include <iomanip>
#include "diatonic.h"

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
			
			if (param == "-s" || param == "-scales" || param == "-c" || param == "-chords" || param == "-a" || param == "-all")
				key = argv[2];
			else
				std::cout << "No such parameter.\n" << std::flush;
		} catch(...) {
      std::cout << "Error in parameter.\n" << std::flush;
    }
	} 
	else if (argc == 1)
		param = "-a";

	if (param == "-s" || param == "-scales" || param == "-a" || param == "-all") {
		scaleT s; scaleGlyphT sG;

		std::cout << '\n' << key << " scales -> MIDI\n";
		std::cout << "-----------------\n";

		std::cout <<  key << " Chromatic\n";
		s = scale_::scale(key, scale_::chromatic);
		sG = scale_::toGlyphs(s);
		printGlyphs(sG);	
		printMIDI(s);
		
		std::cout << key << " Major\n";
		s = scale_::scale(key, scale_::major);
		sG = scale_::toGlyphs(s);
		printGlyphs(sG);	
		printMIDI(s);
		
		std::cout << key << " Minor\n";
		s = scale_::scale(key, scale_::minor);
		sG = scale_::toGlyphs(s);
		printGlyphs(sG);	
		printMIDI(s);
		
		std::cout << key << " Whole notes\n";
		s = scale_::scale(key, scale_::whole);
		sG = scale_::toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << key << " Harmonic Minor\n";
		s = scale_::scale(key, scale_::harmonicminor);
		sG = scale_::toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << key << " Pentatonic Major\n";
		s = scale_::scale(key, scale_::pentatonicmajor);
		sG = scale_::toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << key << " Pentatonic (Minor)\n";
		s = scale_::scale(key, scale_::pentatonicminor);
		sG = scale_::toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << key << " Blues\n";
		s = scale_::scale(key, scale_::blues);
		sG = scale_::toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << '\n' << key << " modes\n";
		std::cout << "--------\n";

		std::cout << key << " Ionian\n";
		s = scale_::scale(key, scale_::ionian);
		sG = scale_::toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << key << " Dorian\n";
		s = scale_::scale(key, scale_::dorian);
		sG = scale_::toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << key << " Phrygian\n";
		s = scale_::scale(key, scale_::phrygian);
		sG = scale_::toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << key << " Lydian\n";
		s = scale_::scale(key, scale_::lydian);
		sG = scale_::toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << key << " Mixolydian\n";
		s = scale_::scale(key, scale_::mixolydian);
		sG = scale_::toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << key << " Aeolian\n";
		s = scale_::scale(key, scale_::aeolian);
		sG = scale_::toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);

		std::cout << key << " Locrian\n";
		s = scale_::scale(key, scale_::locrian);
		sG = scale_::toGlyphs(s);
		printGlyphs(sG);
		printMIDI(s);
	}

	if (param == "-c" || param == "-chords" || param == "-a" || param == "-all") {
		toneT tChords; toneGlyphT tG;

		std::cout << '\n' << key << " chords -> MIDI\n";
		std::cout << "-----------------\n";

		std::cout << key << " Chromatic\n";
		tChords = tone_::tone(key, scale_::chromatic);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);

		std::cout << key << " Major\n";
		tChords = tone_::tone(key, scale_::major);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);

		std::cout << key << " Minor\n";
		tChords = tone_::tone(key, scale_::minor);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
		
		std::cout << key << " Whole notes\n";
		tChords = tone_::tone(key, scale_::whole);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
		
		std::cout << key << " Harmonic Minor\n";
		tChords = tone_::tone(key, scale_::harmonicminor);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
		
		std::cout << key << " Pentatonic\n";
		tChords = tone_::tone(key, scale_::pentatonicminor);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
		
		std::cout << key << " Blues\n";
		tChords = tone_::tone(key, scale_::blues);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
		
		std::cout << '\n' << key << " modes\n";
		std::cout << "--------\n";

		std::cout << key << " Ionian\n";
		tChords = tone_::tone(key, scale_::ionian);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
		
		std::cout << key << " Dorian\n";
		tChords = tone_::tone(key, scale_::dorian);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
	
		std::cout << key << " Phrygian\n";
		tChords = tone_::tone(key, scale_::phrygian);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
		
		std::cout << key << " Lydian\n";
		tChords = tone_::tone(key, scale_::lydian);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
		
		std::cout << key << " Mixolydian\n";
		tChords = tone_::tone(key, scale_::mixolydian);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
		
		std::cout << key << " Aeolian\n";
		tChords = tone_::tone(key, scale_::aeolian);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
		
		std::cout << key << " Locrian\n";
		tChords = tone_::tone(key, scale_::locrian);
		tG = tone_::toGlyphs(tChords);
		printGlyphs(tG);
		printMIDI(tChords);
	}

 return 0;
}
