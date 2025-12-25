#include <Core/Window.h>

int main() {
    // Look! No QMainWindow, no Slots, no Macros.
    // Just your clean Framework API.
    Core::Window win("My Awesome App", 800, 600);
    
    // This starts the Qt event loop internally
    win.Run();

    return 0;
}
