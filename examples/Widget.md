# Хост
```c++
class host::RegionRenderTarget: public plugin::RenderTargetI
{
    render_target_t &render_target;
    region_set_t    &region_set;

    virtual draw_line(const vec2d &point1, const vec2d &point2, const Color &color) override
    {
        // проксируем вместе с region_set
        render_target.draw_line(point_1, point_2, region_set);
    }
};

class host::plugin_widget_t: public widget_t
{
private:
    plugin::RenderableI       &renderI;
    plugin::EventProcessableI & eventI;

public:
    virtual bool on_mouse_press  (...) override { eventI.on_mouse_press  (...); }
    virtual bool on_mouse_release(...) override { eventI.on_mouse_release(...); }
    ...

    virtual void render(render_target_t &target)
    {
        host::RegionRenderTarget temp_target(target, region_set);
        renderI.render(temp_target);
    }
};
```
