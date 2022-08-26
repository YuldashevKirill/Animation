#ifndef TR
#define TR

#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
namespace my {

class Tree : public Figure
{
    int px, py;
    int to_right; // 1 or -1
    Figure *prim[4];
    enum {
        my_brown_col = 64,
        rect_lt_x = 300,
        rect_lt_y = 740,
        rect_w = 50,
        rect_h = 120,
        triang1_ld_x = 130,
        triang1_ld_y = 740,
        triang1_side = 300,
        triang1_h = 200
    };
public:
    Tree(int ax, int ay);
    virtual void draw(int ax, int ay) const;
    virtual void move();
    virtual ~Tree();
};
}
#endif
