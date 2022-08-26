#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "fig.hpp"
#include "tree.hpp"
#include "pig.hpp"
using namespace my;

Pig::Pig(int ax, int ay) : px(ax),
                           py(ay),
                           to_right(1),
                           shift(0)
{
    prim[0] = new Ellipse(0, 0, body_width, body_heigth, 0, PIG_COLOR);
    prim[1] = new Rectangle(between_legs*2, body_heigth/2, leg_w, front_leg_h, PIG_COLOR);
    prim[2] = new Rectangle(between_legs*3, body_heigth/2, leg_w, back_leg_h, PIG_COLOR);
    prim[3] = new Rectangle(between_legs*6, body_heigth/2, leg_w, front_leg_h, PIG_COLOR);
    prim[4] = new Rectangle(between_legs*7, body_heigth/2, leg_w, back_leg_h, PIG_COLOR);
    
    int head_x = -head_width + sh_head_x;
    int head_y = (body_heigth - head_heigth)/2 - sh_head_y;
    prim[5] = new Ellipse(head_x, head_y, head_width, head_heigth, 0, PIG_COLOR);
    
    int nose_x = head_x + head_width/2 - sh_nose_x;
    int nose_y = head_y + head_heigth/2 - sh_nose_y;
    prim[6] = new Ellipse(nose_x , nose_y, nose_w, nose_h, 0, NOSE_COLOR);
    prim[7] = new Ellipse(nose_x + nose_shift, nose_y + nose_shift, eye_x, eye_y, 0, FL_BLACK);
    prim[8] = new Ellipse(nose_x + nose_shx, nose_y + nose_shift, eye_x, eye_y, 0, FL_BLACK);
    prim[9] = new Ellipse(nose_x + eye_shx1, nose_y - eye_shy, eye_size, eye_size, 0, FL_BLACK);
    prim[10] = new Ellipse(nose_x + eye_shx2, nose_y - eye_shy, eye_size, eye_size, 0, FL_BLACK);
    prim[11] = new Triangle(body_width - tail_shift, tail_y1, body_width + tail_x, tail_y2, 
                            body_width - tail_shift, tail_y3, false, PIG_COLOR);
    prim[12] = new Triangle(head_x + ear_x, head_y + ear_y, 
                            head_x + ear_x + ear_w, head_y + ear_y - ear_h, 
                            head_x + ear_x + 2*ear_w, head_y + ear_y, false, PIG_COLOR);
    prim[13] = new Triangle(head_x + ear_x + between_ears, head_y + ear_y, 
                            head_x + ear_x + between_ears + ear_w, head_y + ear_y - ear_h, 
                            head_x + ear_x + between_ears + 2*ear_w, head_y + ear_y, 
                            false, PIG_COLOR);
}

void Pig::move()
{
    if (px + body_width + tail_x >= win_w)
        to_right = -1;
    if (px - head_width + sh_head_x <= 0)
        to_right = 1;
    px += 6*to_right;
    for (int i = 0; i < pig_parts; i++)
        prim[i]->move();
}

void Pig::draw(int ax, int ay) const
{
    for (int i = 0; i < pig_parts; i++)
        prim[i]->draw(px, py);
}

Pig::~Pig() 
{
    for (int i = 0; i < pig_parts; i++)
        delete prim[i];
}
