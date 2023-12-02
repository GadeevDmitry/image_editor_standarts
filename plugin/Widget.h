#ifndef PLUGIN_WIDGET_H
#define PLUGIN_WIDGET_H

#include "Event.h"
#include "Render.h"

//==================================================================================================

namespace plugin
{
    class Widget;
    struct WidgetI
    {
        virtual void   register_subwidget(Widget* subwidget) = 0;
        virtual void unregister_subwidget(Widget* subwidget) = 0;

        virtual const vec2d  &get_size  () const = 0;
        virtual const vec2d  &get_pos   () const = 0;
        virtual       Widget *get_parent()       = 0;

        virtual void set_pos(const vec2d &pos) = 0;
        virtual void move   (const vec2d &off) = 0;

        virtual void update() = 0;
    };

    class Widget: public EventProcessable, public WidgetI
    {};

    struct WidgetCreateI
    {
        virtual Widget *create_widget(EventProcessableI &eventI, RenderableI &renderI);
    };
}

#endif // PLUGIN_WIDGET_H
