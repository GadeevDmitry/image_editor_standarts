#ifndef PLUGIN_TOOL_H
#define PLUGIN_TOOL_H

#include "Event.h"
#include "Render.h"
#include "Interface.h"

//==================================================================================================

namespace plugin
{
    struct ToolI
    {
        virtual const Texture *get_icon() = 0;
        virtual const char    *get_name() = 0;

        virtual void paint_on_press  (RenderTargetI &perm, RenderTargetI &temp, const MouseContext &context, const MouseButton &pressed , const Color &color) = 0;
        virtual void paint_on_release(RenderTargetI &perm, RenderTargetI &temp, const MouseContext &context, const MouseButton &released, const Color &color) = 0;
        virtual void paint_on_move   (RenderTargetI &perm, RenderTargetI &temp, const MouseContext &context, const vec2d       &offset  , const Color &color) = 0;
        virtual void deactivate      (RenderTargetI &perm, RenderTargetI &temp,                                                           const Color &color) = 0;
    };

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    class Tool: public ToolI
    {};

    struct ToolManagerI
    {
        virtual void   set_color(const Color &color) = 0;
        virtual void   set_tool (const Tool  *tool ) = 0;

        virtual       Tool  *get_tool () const = 0;
        virtual const Color &get_color() const = 0;

        virtual void paint_on_move   (RenderTarget &perm, RenderTarget &temp, const MouseContext &context, const vec2d       &offset)   = 0;
        virtual void paint_on_press  (RenderTarget &perm, RenderTarget &temp, const MouseContext &context, const MouseButton &pressed)  = 0;
        virtual void paint_on_release(RenderTarget &perm, RenderTarget &temp, const MouseContext &context, const MouseButton &released) = 0;
        virtual void disable_tool    (RenderTarget &perm, RenderTarget &temp) = 0;
    };

    struct ToolCreateI
    {
        virtual Tool *create_tool(ToolI &toolI) = 0;
    };
}

#endif // PLUGIN_TOOL_H
