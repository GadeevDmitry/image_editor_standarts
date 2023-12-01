#ifndef PLUGIN_RENDER_H
#define PLUGIN_RENDER_H

#include <cinttypes>

//==================================================================================================

namespace plugin
{
    struct Color
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };

    struct Texture
    {
        uint64_t height;
        uint64_t width;
        Color   *pixels;
    };

    struct vec2d
    {
        double x;
        double y;
    };

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    struct RenderTargetI
    {
        virtual void     set_pixel   (vec2d pos   ,               Color color) = 0;
        virtual void     draw_line   (vec2d point1, vec2d point2, Color color) = 0;
        virtual void     draw_rect   (vec2d pos   , vec2d size  , Color color) = 0;
        virtual void     draw_ellipse(vec2d pos   , vec2d size  , Color color) = 0;
        virtual void     draw_texture(vec2d pos   , vec2d size  , const Texture *texture) = 0;
        virtual void     draw_text   (vec2d pos   , const char *content, uint16_t char_size, Color color) = 0;

        virtual Texture *get_texture () = 0;

        virtual void     display     () = 0;
        virtual void     clear       () = 0; // Transparent
    };
};

#endif // PLUGIN_RENDER_H
