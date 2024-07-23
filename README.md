# mglyphs

[![.github/workflows/cmake.yml](https://github.com/pd3v/mglyphs/actions/workflows/cmake.yml/badge.svg)](https://github.com/pd3v/mglyphs/actions/workflows/cmake.yml)

**mglyphs** returns a list of scales, modes, chords in a scales (notes names and MIDI values) based on user's key/octave input.

	Command syntax:

	mglyphs [-param] [key note + octave] 

and **param** can be:

`c` or `chords` - returns all listed scales/modes in the form of 4 note chords (notes names and MIDI values) for the specified key/oct.

`s` or `scales` - returns all listed scales/modes (notes names and MIDI values) for the specified key/oct.

`a` or `all` -  returns both the above; all scales'/modes' chords and scales'/modes' notes

To run **mglyphs** type `./build/mglyphs`, press [Enter] in the command-line. Running it like this (without arguments) will return C scales'/modes' notes and their MIDI values, starting at c = 0 (MIDI).

<pre>
C Blues
________________________
|c  |ds |f  |fs |g  |as |
|0  |3  |5  |6  |7  |10 |
⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻
</pre>

**scales** example:

- `./mglyphs -s d3` - returns all scales/modes in the key of D, third octave, i.e., starting at d = 38 (MIDI)

<pre>
D3 Pentatonic
____________________
|d  |f  |g  |a  |c  |
|38 |41 |43 |45 |48 |
⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻
</pre>

**chords** example:

- `./mglyphs -c d3` - returns all scales'/modes' chords in the key of D, third octave, i.e., starting at d = 38 (MIDI)

<pre>
D3 Mixolydian

_T____________II___________III__________IV___________V____________VI___________VII_________
|d  fs a  c  |e  g  b  d  |fs a  c  e  |g  b  d  fs |a  c  e  g  |b  d  fs a  |c  e  g  b  |
|38 42 45 48 |40 43 47 50 |42 45 48 52 |43 47 50 54 |45 48 52 55 |47 50 54 57 |48 52 55 59 |
⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻
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


