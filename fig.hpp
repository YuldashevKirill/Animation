#ifndef FIG
#define FIG

#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
namespace my {
    enum {
        win_w = 1600,
        win_h = 900,
        tree_start_x = 340,
        tree_start_y = 740,
        animal_start_x = 1100,
        animal_start_y = 550,
        front_leg_h = 180,
        back_leg_h = 150,
    };
    class Figure
    {
    public:
        virtual void draw(int ax, int ay) const = 0;
        virtual void move() = 0;
        virtual int get_px1() const { return 0; }
        virtual int get_px3() const { return 0; }
        virtual ~Figure() {};
    };

    class Rectangle : public Figure
    {
        int px, py;
        int sh;
        int width, heigth;
        Fl_Color color;
    public:
        Rectangle(int ax, int ay, int w, int h, Fl_Color acol);
        virtual void draw(int ax, int ay) const;
        virtual void move();
        virtual ~Rectangle();
    };

    class Triangle : public Figure
    {
        int px1, py1, px2, py2, px3, py3;
        int sh;
        bool shift;
        Fl_Color color;
    public:
        Triangle(int ax1, int ay1, int ax2, int ay2, int ax3, int ay3, bool ashift, Fl_Color acol);
        virtual int get_px1() const;
        virtual int get_px3() const;
        virtual void draw(int ax, int ay) const;
        virtual void move();
        virtual ~Triangle();
    };

    class Ellipse : public Figure
    {
        int px, py;
        int width, heigth;
        int only_board;
        Fl_Color color;
    public:
        Ellipse(int ax, int ay, int w, int h, int board, Fl_Color acol);
        virtual void draw(int ax, int ay) const;
        virtual void move();
        virtual ~Ellipse();
    };
}

#endif
