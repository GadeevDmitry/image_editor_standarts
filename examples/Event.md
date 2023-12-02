# Хост
```c++
class host::plugin_event_processable_t: event_processable_t
{
    plugin::EventProcessableI &eventI;

    // при необходимости конвертирует хостовый интерфейс в плагиновский
    virtual bool on_mouse_press  (...) override { eventI.on_mouse_press  (...); }
    virtual bool on_mouse_release(...) override { eventI.on_mouse_release(...); }
    ...
};

class host::EventProcessable: plugin::EventProcessable
{
    host::plugin_event_processable_t event_processable;

    // просто proxy
    virtual bool on_mouse_press  (...) override { event_processable.eventI.on_mouse_press  (...); }
    virtual bool on_mouse_release(...) override { event_processable.eventI.on_mouse_release(...); }
};

//--------------------------------------------------------------------------------------------------

struct host::EventCreateI: plugin::EventCreateI
{
    virtual pliugin::EventProcessable *create_event_processable(EventProcessable &eventI)
    {
        return new host::EventProcessable(eventI);
    };
};

```