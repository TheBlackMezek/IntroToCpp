
#include <iostream>


void p(std::string s);
void brk();
void pause();


int main()
{

	std::cout << "Hello AIE" << std::endl;
	p("p() test");
	brk();

	p("Favorite song:");
	p("Soviet History in Tetris");
	brk();


	pause();


	brk();
	p("I am the man who arranges the blocks");
	p("That descend upon me from up above");
	p("They come down and I spin them around");
	p("'Till they fit in the ground like hand in glove");
	brk();


	pause();


	brk();
	p("I am the MAN who arRANges the BLOCKS");
	p("THAT deSCEND up-on ME from UP a-BOVE");
	p("THEY come DOWN and i SPIN them aROUND");
	p("'till they FIT in the GROUND like HAND in GLOVE");
	brk();


	pause();


	brk();
	p("TIMber to Ashes and Iron to RUST");
	p("ALL the VERSE will BURN to DUST");
	brk();
	p("timber 2syllable IDEAL:ber ACCEPTABLE:er");
	//Each word has syllable number, ideal rhyme, acceptable rhyme
	p("BER: timber, lumber, slumber, number, tumbler");
	//Each rhyme bit (syllable? need name) has list of all words with that rhyme, maybe use pointers to where word is stored?
	//Each word should maybe have a pointer to its rhyme lists/arrays/whatever
	p("TIMBER SYNONYMS: wood, lumber");
	//Each word has synonyms, maybe in [1][i] of word's own array
	//How to store MEANING?
	//Basic meaning ideas: visual attribs, like color, sparkle, etc; emotional associations, like comfort, home, fear, anger;
	//Emotional associations are more relative than normal attribs, possibility to customize for individuals
	brk();


	/*
	p("0");
	p("1");
	p("2");
	p("3");
	p("4");
	p("5");
	brk();

	p("5");
	p("4");
	p("3");
	p("2");
	p("1");
	p("0");
	brk();
	*/

	system("pause");

	return 0;
}

void p(std::string s)
{
	std::cout << s.c_str() << std::endl;
}

void brk()
{
	std::cout << std::endl;
}

void pause()
{
	system("pause");
}