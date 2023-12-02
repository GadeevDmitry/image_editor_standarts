#ifndef PLUGIN_FILTER_H
#define PLUGIN_FILTER_H

#include "Render.h"
#include "Interface.h"

//==================================================================================================

namespace plugin
{
    struct FilterI
    {
        virtual const char *get_name() = 0;
        virtual void apply(RenderTargetI &perm) = 0;
    };

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    class Filter: public FilterI
    {};

    struct FilterManagerI
    {
        virtual void    set_filter(Filter *filter) = 0;
        virtual Filter *get_filter() const         = 0;

        virtual void apply_filter(RenderTarget &perm) = 0;
    };

    struct FilterCreateI
    {
        virtual Filter *create_filter(FilterI &filterI) = 0;
    };

};

#endif // PLUGIN_FILTER_H
