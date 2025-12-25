# Define the library
add_library(Core STATIC src/Window.cpp)

# Enable Qt "Magic" (MOC) only for this library
set_target_properties(Core PROPERTIES AUTOMOC ON)

# Include directories
target_include_directories(Core PUBLIC include)

# Link Qt to the Engine
target_link_libraries(Core PRIVATE Qt6::Widgets)
