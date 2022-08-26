#ifndef PIG
#define PIG

#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
namespace my {
    class Pig : public Figure
    {
        int px, py;
        int to_right;
        int shift;
        enum {
            body_width = 300,
            body_heigth = 200,
            leg_w = 20,
            between_legs = 30,
            between_ears = 53,
            ear_x = 17,
            ear_y = 17,
            ear_h = 30,
            ear_w = 15,
            sh_head_x = 20,
            sh_head_y = 60, 
            sh_nose_x = 25,
            sh_nose_y = 10,
            head_width = 120,
            head_heigth = 120,
            eye_size = 20,
            nose_shift = 13,
            nose_shx = 28,
            eye_x = 10,
            eye_y = 14,
            eye_shx1 = -5,
            eye_shx2 = 35,
            eye_shy = 30,
            PIG_COLOR = 170,
            NOSE_COLOR = 160,
            nose_w = 50,
            nose_h = 40,
            tail_shift = 10,
            tail_x = 50,
            tail_y1 = 70,
            tail_y2 = 30,
            tail_y3 = 100,
            pig_parts = 14
        };
        Figure *prim[pig_parts];
    public:
        Pig(int ax, int ay);
        virtual void draw(int ax, int ay) const;
        virtual void move();
        virtual ~Pig();
    };
}
#endif
