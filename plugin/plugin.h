#ifndef PLUGIN_PLUGIN_H
#define PLUGIN_PLUGIN_H

#include <cinttypes>

#include "Interface.h"
#include "application.h"

//==================================================================================================

namespace plugin
{
    struct Plugin
    {
        /* где-то тут лежит App*, но это дело автора плагина */

        uint64_t        id;
        const char   *name;
        InterfaceType type;

        virtual Interface *getInterface() = 0;
        virtual           ~Plugin      () = 0;
    };
}

extern "C" plugin::Plugin* getInstance(plugin::App *app);

#endif // PLUGIN_PLUGIN_H
