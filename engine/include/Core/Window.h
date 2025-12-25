#pragma once

#include <string>
#include <memory>
// #include "Core/Core.h" // Uncomment if using DLL export macros like CORE_API

namespace Core {

    class Window {
    public:
        Window(const std::string& title, int width, int height);
        ~Window();

        // Starts the main application loop
        void Run();

    private:
        // Opaque pointer to the implementation (Pimpl Idiom)
        struct Impl;
        std::unique_ptr<Impl> m_pImpl;
    };

}
