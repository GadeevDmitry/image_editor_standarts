# Хост
>```c++
>struct RenderCreateI
>{
>    // Плагин может запросить у хоста render_target. Хост создаст необходимую СТРУКТУРУ
>    // и вернет указатель на интерфейс RenderTargetI. Единственный способ создать render_target
>    // для плагина - через данную функцию (т.е, если плагин вызовет хостовую функцию и передаст
>    // RenderTargetI* в качестве аргумента, то хост в праве кастовать RenderTargetI к своей СТРУКТУРЕ).
>    //
>    // По оканчании использования плагин должен удалить RenderTargetI* через оператор delete.
>    virtual RenderTarget *create_render_target(unsigned width, unsigned height) = 0;
>};
>```

```c++
// Та самая СТРУКТУРА
class host::RenderTarget: public plugin::RenderTarget
{
    // хостовая render_target
    render_target_t render_target;

public:
    virtual void draw_line(...) override
    {
        render_target.draw_line(...);
    }
    ...
};

//--------------------------------------------------------------------------------------------------

struct host::RenderCreateI: public plugin::RenderCreateI
{
    virtual plugin::RenderTarget *create_render_target(unsigned width, unsigned height) override
    {
        return new host::RenderTarget(width, height);
    }
};

```
