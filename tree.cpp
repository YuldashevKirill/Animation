#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "fig.hpp"
#include "tree.hpp"
using namespace my;

Tree::Tree(int ax, int ay) : px(ax), 
                             py(ay),
                             to_right(1)
{ 
    double mul = 0.8;
    prim[0] = new Rectangle(0, 0, rect_w, rect_h, my_brown_col);
    int x1 = rect_w/2 - triang1_side/2;
    prim[1] = new Triangle(x1, 0, x1 + triang1_side/2, -triang1_h, x1 + triang1_side, 0, true, FL_GREEN);
    
    int x2 = x1 + (triang1_side - triang1_side*mul)/2;
    int y2 = -triang1_h;
    prim[2] = new Triangle(x2, y2, x2 + triang1_side*mul/2, y2 - triang1_h*mul, x2 + triang1_side*mul, y2, 
                          true, FL_GREEN);
                          
    int x3 = x2 + (triang1_side*mul - triang1_side*mul*mul)/2;
    int y3 = y2 - triang1_h*mul;
    prim[3] = new Triangle(x3, y3, x3 + triang1_side*mul*mul/2, y3 - triang1_h*mul*mul, 
                           x3 + triang1_side*mul*mul, y3, true, FL_GREEN);
}

void Tree::move()
{
    int tmpx = px + prim[1]->get_px3();
    if (tmpx > win_w)
        to_right = -1;
    if (px + prim[1]->get_px1() <= 0)
        to_right = 1;
    px += 4*to_right;
    for (int i = 0; i < 4; i++)
        prim[i]->move();
}

void Tree::draw(int ax, int ay) const
{
    for (int i = 0; i < 4; i++)
        prim[i]->draw(px, py);
}

Tree::~Tree()
{
    for (int i = 0; i < 4; i++)
        delete prim[i];
}
