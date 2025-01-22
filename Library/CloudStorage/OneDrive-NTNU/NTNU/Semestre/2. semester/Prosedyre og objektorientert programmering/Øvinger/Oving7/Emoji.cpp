#include "Emoji.h"

void Face::draw(AnimationWindow& win) {
    //AnimationWindow win(800,600);
    win.draw_circle(centre,radius,Color::yellow);
    //win.wait_for_close();
}

void EmptyFace::draw(AnimationWindow& win) {
    Face::draw(win);
    win.draw_circle(left_eye.getCentre(), left_eye.getRadius(), color_eye);
    win.draw_circle(right_eye.getCentre(), right_eye.getRadius(), color_eye);
}

void SmilingFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);
    //win.draw_arc(centre, radius/8, 180+30, 180-30, 1, color_eye);
    win.draw_arc({centre.x,centre.y+(radius/4)}, radius/2, radius/3, 180, 270);
    win.draw_arc({centre.x,centre.y+(radius/4)}, radius/2, radius/3, 270, 360);
}

void SadFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);
    win.draw_arc({centre.x,centre.y+(radius/2)}, radius/2, radius/3, 0, 180);
}

void WinkingFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);
    win.draw_circle(right_eye.getCentre(), right_eye.getRadius(), Color::yellow);
    win.draw_arc(right_eye.getCentre(), right_eye.getRadius(), right_eye.getRadius(), 0, 180);
    win.draw_arc({centre.x,centre.y+(radius/4)}, radius/2, radius/3, 180, 270);
    win.draw_arc({centre.x,centre.y+(radius/4)}, radius/2, radius/3, 270, 360);
}

void SurprisedFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);
    win.draw_circle({centre.x,centre.y+radius/2},radius/4, color_eye);
}