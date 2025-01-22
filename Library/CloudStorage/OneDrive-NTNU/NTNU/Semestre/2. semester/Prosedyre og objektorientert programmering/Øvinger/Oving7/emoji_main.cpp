#include "AnimationWindow.h"
#include "Emoji.h"


// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main()
{
	//EmptyFace(Face l_e, Face r_e, Color c_e, Point c, int r) empt;

	const Point tl{150, 150};
	const Point tl1{300, 150};
	const Point tl2{450, 150};
	const Point tl3{600, 150};

	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};

	//EmptyFace myFace{Face{Point{tl.x-(emojiRadius/2), tl.y-(emojiRadius/4)}, emojiRadius/6}, Face{Point{tl.x+(emojiRadius/2), tl.y-(emojiRadius/4)}, emojiRadius/6}, Color::black, tl, emojiRadius};
	//myFace.draw(win);

	/* TODO:
	 *  - initialiser emojiene
	 *  - Tegn emojiene til vinduet
	 **/


	SmilingFace smile(Face{Point{tl.x-(emojiRadius/2), tl.y-(emojiRadius/4)}, emojiRadius/6}, Face{Point{tl.x+(emojiRadius/2), tl.y-(emojiRadius/4)}, emojiRadius/6}, Color::black, tl, emojiRadius);
	smile.draw(win);

	SadFace sad(Face{Point{tl1.x-(emojiRadius/2), tl1.y-(emojiRadius/4)}, emojiRadius/6}, Face{Point{tl1.x+(emojiRadius/2), tl1.y-(emojiRadius/4)}, emojiRadius/6}, Color::black, tl1, emojiRadius);
	sad.draw(win);

	WinkingFace wink(Face{Point{tl2.x-(emojiRadius/2), tl2.y-(emojiRadius/4)}, emojiRadius/6}, Face{Point{tl2.x+(emojiRadius/2), tl2.y-(emojiRadius/4)}, emojiRadius/6}, Color::black, tl2, emojiRadius);
	wink.draw(win);

	SurprisedFace surprised(Face{Point{tl3.x-(emojiRadius/2), tl3.y-(emojiRadius/4)}, emojiRadius/6}, Face{Point{tl3.x+(emojiRadius/2), tl3.y-(emojiRadius/4)}, emojiRadius/6}, Color::black, tl3, emojiRadius);
	surprised.draw(win);




	win.wait_for_close();

	return 0;
}
