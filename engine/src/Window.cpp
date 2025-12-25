#include <Core/Window.h>
#include <QApplication>
#include <QMainWindow>

namespace Core {

    // Global static variables to keep QApplication happy.
    // Qt requires argc/argv references to remain valid for the app's lifetime.
    static int argc = 0;
    static char** argv = nullptr;

    // Helper: Ensures QApplication exists before any QWidget is created.
    static void EnsureQtApp() {
        if (!QApplication::instance()) {
            // We intentionally leak this pointer because QApplication acts as a singleton
            // that must exist for the duration of the program.
            new QApplication(argc, argv);
        }
    }

    // The actual implementation of the Window using Qt
    struct Window::Impl : public QMainWindow {
        Impl(const std::string& title, int width, int height) {
            setWindowTitle(QString::fromStdString(title));
            resize(width, height);
            show(); // Make sure the window is visible immediately
        }
    };

    Window::Window(const std::string& title, int width, int height) {
        // CRITICAL: Initialize QApplication *before* creating the Impl (QMainWindow)
        EnsureQtApp();

        // Now it is safe to construct the window
        m_pImpl = std::make_unique<Impl>(title, width, height);
    }

    Window::~Window() = default;

    void Window::Run() {
        // Hand control over to the Qt Event Loop
        QApplication::exec();
    }
}
