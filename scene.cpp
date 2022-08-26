#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "fig.hpp"
#include "tree.hpp"
#include "pig.hpp"
#include "scene.hpp"
using namespace my;

void Scene::Timer_CB(void *user) 
{
    Scene *s = (Scene*)user;
    s->move();
    s->redraw();
    Fl::repeat_timeout(0.055, Timer_CB, user);
}

Scene::Scene() : Fl_Box(0, 0, win_w, win_h, nullptr)
{
    fig[0] = new Tree(tree_start_x, tree_start_y);
    fig[1] = new Pig(animal_start_x, animal_start_y);
    Fl::add_timeout(0.025, Timer_CB, (void*)this);
}

void Scene::draw()
{
    Fl_Box::draw();
    box(FL_FLAT_BOX);
    color(my_color);
    fig[0]->draw(0, 0);
    fig[1]->draw(0, 0);
}

void Scene::move()
{
    fig[0]->move();
    fig[1]->move();
}

Scene::~Scene() 
{
    delete fig[0];
    delete fig[1];
}
