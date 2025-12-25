#include <Core/Window.h>
#include <iostream>

int main() {
    // No Qt includes needed here!
    Core::Window window("Engine Template Window", 800, 600);
    
    // The engine handles the loop
    window.Run();

    return 0;
}
