#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji {
public:
    virtual void draw(AnimationWindow&) = 0;
    virtual ~Emoji(){}; //destruktør
};

class Face : Emoji {
protected:
    Point centre;
    int radius;
public:
    Face(Point c, int r) : centre(c), radius(r) {};
    //void draw(AnimationWindow&) = 0;
    void draw(AnimationWindow& win) override;
    const Point getCentre() {return centre;};
    const int getRadius() {return radius;};
};

class EmptyFace : public Face {
protected:
    Face left_eye;
    Face right_eye;
    Color color_eye;
    
public:
    //EmptyFace(Face l_e, Face r_e, Color c_e, Point c, int r) : Face(centre{c},radius{r}), left_eye{l_e}, right_eye{r_e}, color_eye{c_e}  {};
    EmptyFace(Face l_e, Face r_e, Color c_e, Point c, int r) : Face(c,r), left_eye{l_e}, right_eye{r_e}, color_eye{c_e}  {};
    const Face getLeftEye() {return left_eye;};
    const Face getRightEye() {return right_eye;};
    

    void draw(AnimationWindow& win) override;
};

class SmilingFace : EmptyFace {
public:
    SmilingFace(Face l_e, Face r_e, Color c_e, Point c, int r) : EmptyFace(l_e,r_e,c_e,c,r) {};
    void draw(AnimationWindow& win) override;
};

class SadFace : EmptyFace {
public:
    SadFace(Face l_e, Face r_e, Color c_e, Point c, int r) : EmptyFace(l_e,r_e,c_e,c,r) {};
    void draw(AnimationWindow& win) override;
};

class WinkingFace : EmptyFace {
public:
    WinkingFace(Face l_e, Face r_e, Color c_e, Point c, int r) : EmptyFace(l_e,r_e,c_e,c,r) {};
    void draw(AnimationWindow& win) override;
};

class SurprisedFace : EmptyFace {
public:
    SurprisedFace(Face l_e, Face r_e, Color c_e, Point c, int r) : EmptyFace(l_e,r_e,c_e,c,r) {};
    void draw(AnimationWindow& win) override;
};