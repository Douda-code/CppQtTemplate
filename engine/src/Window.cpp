#include <Core/Window.h>
#include <QApplication>
#include <QMainWindow>

namespace Core {
    
    // The "Hidden" Qt Class
    struct Window::Impl : public QMainWindow {
        int argc = 0;
        char** argv = nullptr;
        std::unique_ptr<QApplication> app;

        Impl(const std::string& title, int width, int height) {
            // Qt needs argc/argv
            app = std::make_unique<QApplication>(argc, argv);
            
            setWindowTitle(QString::fromStdString(title));
            resize(width, height);
            show();
        }
    };

    // Forwarding calls to the Impl
    Window::Window(const std::string& title, int width, int height)
        : m_pImpl(std::make_unique<Impl>(title, width, height)) {}

    Window::~Window() = default;

    void Window::Run() {
        // Starts the Qt Event Loop
        m_pImpl->app->exec();
    }
}
