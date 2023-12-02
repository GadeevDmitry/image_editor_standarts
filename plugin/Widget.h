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

    struct LabelWidgetI
    {
        virtual void set_string        (const char *string) = 0;
        virtual void set_string_color  (const Color &color) = 0;
        virtual void set_character_size(const uint8_t size) = 0;

        virtual void set_background    (const Color &color) = 0;
        virtual void set_string_offset (const vec2d &off  ) = 0;

        virtual const char  *get_string        () const = 0;
        virtual const Color &get_string_color  () const = 0;
        virtual     uint8_t  get_character_size() const = 0;

        virtual const Color &get_background    () const = 0;
        virtual const vec2d &get_string_offset () const = 0;

        // Создать текстуру label-виджета с заданными параметрами
        // для рендеринга. Необходимо вызывать после обновления параметров.
        virtual void create_texture();
    };

    struct ColorWidgetI
    {
        virtual void set_color(const Color &color) = 0;
        virtual const Color &get_color() const     = 0;
    };

    struct TextureWidgetI
    {
        virtual void set_texture(Texture *texture) = 0;
        virtual void set_texture(const char *file) = 0;

        virtual const Texture *get_texture() const = 0;
    };

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    class Widget: public EventProcessable, public WidgetI
    {};

    class LabelWidget: public Widget, public LabelWidgetI
    {};

    class ColorWidget: public Widget, public ColorWidgetI
    {};

    class TextureWidget: public Widget, public TextureWidgetI
    {};

    struct WidgetCreateI
    {
        virtual Widget *create_widget(RenderableI &renderI, EventProcessableI &eventI) = 0;

        virtual LabelWidget   *create_label_widget  (       EventProcessableI &eventI) = 0;
        virtual ColorWidget   *create_color_widget  (       EventProcessableI &eventI) = 0;
        virtual TextureWidget *create_texture_widget(       EventProcessableI &eventI) = 0;

        virtual Widget *create_window (const vec2d &pos, const vec2d &size, const char *name)        = 0;
        virtual Widget *create_canvas (const vec2d &pos, const vec2d &size, const Color &background) = 0;
        virtual Widget *create_editbox(const vec2d &pos, const vec2d &size)                          = 0;
    };
}

#endif // PLUGIN_WIDGET_H
