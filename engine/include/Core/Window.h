// Window.h 
#pragma once
#include <memory>
#include <string>

namespace Core {
    class Window {
    public:
        Window(const std::string& title, int width, int height);
        ~Window();

        // The method that starts the Qt Event Loop
        void Run(); 

    private:
        struct Impl; // Hidden Qt implementation
        std::unique_ptr<Impl> m_pImpl;
    };
}
