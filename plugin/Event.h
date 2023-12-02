#ifndef PLUGIN_EVENT_H
#define PLUGIN_EVENT_H

#include <cinttypes>
#include "Render.h"

//==================================================================================================

namespace plugin
{
    enum class Key
    {
        Unknown = -1,
        A = 0,
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        I,
        J,
        K,
        L,
        M,
        N,
        O,
        P,
        Q,
        R,
        S,
        T,
        U,
        V,
        W,
        X,
        Y,
        Z,
        Num0,
        Num1,
        Num2,
        Num3,
        Num4,
        Num5,
        Num6,
        Num7,
        Num8,
        Num9,
        Escape,
        LControl,
        LShift,
        LAlt,
        LSystem,
        RControl,
        RShift,
        RAlt,
        RSystem,
        Menu,
        LBracket,
        RBracket,
        Semicolon,
        Comma,
        Period,
        Apostrophe,
        Slash,
        Backslash,
        Grave,
        Equal,
        Hyphen,
        Space,
        Enter,
        Backspace,
        Tab,
        PageUp,
        PageDown,
        End,
        Home,
        Insert,
        Delete,
        Add,
        Subtract,
        Multiply,
        Divide,
        Left,
        Right,
        Up,
        Down,
        Numpad0,
        Numpad1,
        Numpad2,
        Numpad3,
        Numpad4,
        Numpad5,
        Numpad6,
        Numpad7,
        Numpad8,
        Numpad9,
        F1,
        F2,
        F3,
        F4,
        F5,
        F6,
        F7,
        F8,
        F9,
        F10,
        F11,
        F12,
        F13,
        F14,
        F15,
        Pause,

        KeyCount,
    };

    struct KeyboardContext
    {
        bool alt;
        bool shift;
        bool ctrl;

        Key  key;
    };

    //--------------------------------------------------------------------------------------------------

    enum class MouseButton
    {
        Unknown = -1,
        Left = 0,
        Right,

        MouseButtonCount
    };

    struct MouseContext
    {
        vec2d     position;
        MouseButton button;
    };

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    enum class EventType
    {
        Unknown = -1,
        MousePress = 0,
        MouseRelease,
        MouseMove,
        KeyPress,
        KeyRelease,
	    Clock,

        NumOfEvents
    };

    struct EventProcessableI
    {
        virtual bool on_mouse_move   (const MouseContext    &context, const vec2d       &offset)   = 0;
        virtual bool on_mouse_release(const MouseContext    &context, const MouseButton &released) = 0;
        virtual bool on_mouse_press  (const MouseContext    &context, const MouseButton &pressed)  = 0;
        virtual bool on_key_press    (const KeyboardContext &context, const Key         &pressed)  = 0;
        virtual bool on_key_release  (const KeyboardContext &context, const Key         &released) = 0;
        virtual bool on_clock        (      uint64_t         delta  ) = 0;

	    virtual uint8_t get_priority() const = 0;
    };

    struct EventManagerI
    {
        virtual void register_object  (EventProcessableI *object)   = 0;
        virtual void set_priority     (EventType, uint8_t priority) = 0;
        virtual void unregister_object(EventProcessableI *object)   = 0;
    };
}

#endif // PLUGIN_EVENT_H
