#ifndef PLUGIN_APPLICATION_H
#define PLUGIN_APPLICATION_H

#include "Tool.h"
#include "Filter.h"
#include "Widget.h"

//==================================================================================================

namespace plugin
{
    struct Plugin;

    struct GuiI
    {
        // размер доступной для рисования площади (которую можно запросить)
        virtual vec2d get_size() = 0;

        /// @brief запросить RT.
        /// Хост создает новое окно / отдает какое-то, абсолютно пустое, с единственным RT на все окно.
        /// @param size -- размер запрашиваемой области
        /// @param pos  -- (относительное [относительно предоставленной области]) смещение запрашиваемой области
        virtual RenderTargetI* get_render_target(vec2d size, vec2d pos, Plugin *self) = 0;

        /// @brief Создает окно с параметрами, каким-то образом узнает у пользователя 
        ///     значения параметров и потом возвращает их интерфейсу через Interface::set_params
        /// @note окно не обязательно модальное, да и вообще implementation defined. Мем в том, что плагин находится в 
        ///     неопределенном/дефолтном состоянии между createParamWindow и Interface::set_params и взаимодействие с ним UB
        virtual void create_param_window(Array<const char *> param_names, Interface * self) = 0;

        /**
         * @brief Get the root widget of widget tree
         * 
         * @return WidgetI* root
         */
        virtual WidgetI* get_root();
    };

    struct App
    {
        GuiI           *root;
        EventManagerI  *event_manager; 
        ToolManagerI   *tool_manager;
        FilterManagerI *filter_manager; 
    };
}

#endif // PLUGIN_APPLICATION_H
