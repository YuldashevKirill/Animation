#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "fig.hpp"
using namespace my;

Rectangle::Rectangle(int ax, int ay, int w, int h, Fl_Color acol) : px(ax),
                                                                    py(ay),
                                                                    sh(0),
                                                                    width(w),
                                                                    heigth(h),
                                                                    color(acol)
{}

void Rectangle::move() 
{
    if (heigth != front_leg_h && heigth != back_leg_h)
        return;
    sh++;
    if (heigth == front_leg_h)
    {
        if (sh == 2)
        {
            px -= 15;
        }
        if (sh == 4)
        {
            px += 15;
        }
    }
    if (heigth == back_leg_h)
    {
        if (sh == 2)
        {
            px += 15;
        }
        if (sh == 4)
        {
            px -= 15;
        }
    }
    if (sh == 4)
        sh = 0;
}

void Rectangle::draw(int ax, int ay) const
{
    fl_color(color);
    fl_rectf(px + ax, py + ay, width, heigth);
}

Rectangle::~Rectangle()  {}

Triangle::Triangle(int ax1, int ay1, int ax2, int ay2, int ax3, int ay3, bool ashift, Fl_Color acol)
                    : px1(ax1),
                      py1(ay1),
                      px2(ax2),
                      py2(ay2),
                      px3(ax3),
                      py3(ay3),
                      shift(ashift),
                      sh(0),
                      color(acol) {};

int Triangle::get_px1() const
{
    return px1;
}

int Triangle::get_px3() const
{
    return px3;
}

void Triangle::move()
{
    if (!shift)
        return;
    int th = 3;
    if (abs(sh)%16 < 8)
    {
        px1 += th;
        px3 -= th;
    }
    else
    {
        px1 -= th;
        px3 += th;
    }
    sh++;
    if (sh == 16)
        sh = 0;    
    
}
void Triangle::draw(int ax, int ay) const
{
    fl_color(color);
    fl_polygon(px1 + ax, py1 + ay, px2 + ax, py2 + ay, px3 + ax, py3 + ay);
}

Triangle::~Triangle()   {}


Ellipse::Ellipse(int ax, int ay, int w, int h, int board, Fl_Color acol) : px(ax),
                                                                           py(ay),
                                                                           width(w),
                                                                           heigth(h),
                                                                           only_board(board),
                                                                           color(acol)
{};

void Ellipse::move() {}

void Ellipse::draw(int ax, int ay) const
{
    fl_color(color);
    if (only_board)
        fl_arc(ax + px, py + ay, width, heigth, 0, 360);
    else
        fl_pie(ax + px, py + ay, width, heigth, 0, 360);
}

Ellipse::~Ellipse() {}
