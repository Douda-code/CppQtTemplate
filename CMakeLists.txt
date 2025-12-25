# --- Generic Template Setup ---

# 1. Get the project name from the top line (e.g., "SuperTool")
set(APP_NAME ${PROJECT_NAME}) 

# 2. Setup Your App using the variable
add_executable(${APP_NAME} src/main.cpp)

# 3. Link to Core
target_link_libraries(${APP_NAME} PRIVATE Core Qt6::Widgets)

set_target_properties(${APP_NAME} PROPERTIES WIN32_EXECUTABLE ON)
