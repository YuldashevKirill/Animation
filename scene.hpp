#ifndef SC
#define SC

#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
namespace my {
    class Scene : public Fl_Box
    {
        enum { my_color = 254 };
        Figure *fig[2];
        static void Timer_CB(void *user);
    public:
        Scene();
        void draw();
        void move();
        ~Scene();
    };
}
#endif
