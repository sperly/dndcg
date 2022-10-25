cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

project("DnDCharGen"
    VERSION 0.1
    DESCRIPTION "Generator for \"Drakar och Demoner\" characters"
    LANGUAGES CXX
)

# set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/external/imgui)
# find_package(SDL2 REQUIRED)
# find_package(OpenGL REQUIRED)
find_package(SQLite3 REQUIRED)

# find_package(GTK3)

# set(wxWidgets_CONFIG_OPTIONS --toolkit=base --prefix=/usr)
find_package(wxWidgets REQUIRED xrc stc richtext ribbon propgrid aui gl media html qa adv core xml net base)

include(${wxWidgets_USE_FILE})

add_subdirectory(${CMAKE_SOURCE_DIR}/extern/SQLiteCpp)

# add_subdirectory(${CMAKE_SOURCE_DIR}/external/wxWidgets)
add_executable(${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/app.cpp
    ${CMAKE_SOURCE_DIR}/src/character.cpp
    ${CMAKE_SOURCE_DIR}/src/db_handler.cpp
    ${CMAKE_SOURCE_DIR}/src/gui/gui.cpp

    # ${CMAKE_SOURCE_DIR}/src/gui/char_gen_wizard.cpp

    # ${IMGUI_DIR}/imgui.cpp
    # ${IMGUI_DIR}/imgui_draw.cpp
    # ${IMGUI_DIR}/imgui_demo.cpp
    # ${IMGUI_DIR}/imgui_tables.cpp
    # ${IMGUI_DIR}/imgui_widgets.cpp
    # ${IMGUI_DIR}/backends/imgui_impl_sdl.cpp
    # ${IMGUI_DIR}/backends/imgui_impl_opengl2.cpp
)

include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/stb
    ${SQLITE3_INCLUDE_DIRS}
    ${wxWidgets_INCLUDE_DIRS}

    # ${SDL2_INCLUDE_DIR}
    # ${OPENGL_INCLUDE_DIR}
    # ${IMGUI_DIR}
    # ${IMGUI_DIR}/backends
)

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC

    # ${OPENGL_LIBRARIES}
    # ${SDL2_LIBRARIES}
    ${wxWidgets_LIBRARIES}
    SQLiteCpp
    sqlite3
)

target_compile_definitions(${PROJECT_NAME} PUBLIC ${wxWidgets_DEFINITIONS})

target_compile_options(${PROJECT_NAME} PRIVATE
    ${wxWidgets_CXX_FLAGS}
)
