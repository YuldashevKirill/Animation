#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "fig.hpp"
#include "tree.hpp"
#include "pig.hpp"
#include "scene.hpp"

using namespace my;
int main()
{
    Fl_Window *win = new Fl_Window(win_w, win_h, "animation");
    win->begin();
    Scene *s = new Scene();
    win->end();
    win->show();
    int code = Fl::run();
    delete s;
    delete win;
    return code;
}
