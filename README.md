# mglyphs

[![Release Build](https://github.com/pd3v/intervals/actions/workflows/cmake+submodule.yml/badge.svg)](https://github.com/pd3v/intervals/actions/workflows/cmake+submodule.yml)

**mglyphs** returns a list of scales, modes and their respective notes in MIDI values based on user's key/octave input.

	Command syntax:

	mglyphs [-param] [key note + octave] 

	param = k or key

To run **mglyphs** type `./mglyphs`, press [Enter] in the command-line. Running it like this (without arguments) will return C scales'/modes' notes and their MIDI values, starting at c = 0 (MIDI).

<pre>
C Blues
________________________
|c  |ds |f  |fs |g  |as |
|0  |3  |5  |6  |7  |10 |
⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻
</pre>

Other example:

- `./mglyphs -k d3` - returns all scales/modes in the key of D, third octave, i.e., starting at d = 38 (MIDI)

<pre>
D3 Pentatonic
____________________
|d  |f  |g  |a  |c  |
|38 |41 |43 |45 |48 |
⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻
</pre>

### Scales listed
- Chromatic
- Major
- Minor	
- Whole
- Harmonic Minor
- Pentatonic
- Blues
	
### Modes listed	

- Ionian
- Dorian
- Phrygian
- Lydian 
- Mixolydian
- Aeolian
- Locrian


