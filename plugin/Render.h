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

    //--------------------------------------------------------------------------------------------------

    struct RenderTargetI
    {
        virtual void     set_pixel   (const vec2d &pos   ,                      const Color &color) = 0;
        virtual void     draw_line   (const vec2d &point1, const vec2d &point2, const Color &color) = 0;
        virtual void     draw_rect   (const vec2d &pos   , const vec2d &size  , const Color &color) = 0;
        virtual void     draw_ellipse(const vec2d &pos   , const vec2d &size  , const Color &color) = 0;
        virtual void     draw_texture(const vec2d &pos   , const vec2d &size  , const Texture *texture) = 0;
        virtual void     draw_text   (const vec2d &pos   , const char *content, const uint16_t &char_size, const Color &color) = 0;

        virtual Texture *get_texture () const = 0;

        virtual void     display     () = 0;
        virtual void     clear       (const Color &color) = 0;
    };

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    struct RenderableI
    {
        virtual void render(RenderTargetI &target) = 0;
    };

    class RenderTarget: public RenderTargetI
    {};

    struct RenderCreateI
    {
        // Плагин может запросить у хоста RenderTarget. Хост создаст необходимую СТРУКТУРУ
        // и вернет указатель на интерфейс RenderTarget. Единственный способ создать RenderTarget
        // для плагина - через данную функцию (т.е, если плагин вызовет хостовую функцию и передаст
        // RenderTarget* в качестве аргумента, то хост скастует ее к своей СТРУКТУРЕ).
        //
        // По оканчании использования плагин должен удалить RenderTargetI* через оператор delete.
        virtual RenderTarget *create_render_target(unsigned width, unsigned height) = 0;
    };
};

#endif // PLUGIN_RENDER_H
