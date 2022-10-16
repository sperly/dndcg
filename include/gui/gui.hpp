#pragma once

// #include <SDL2/SDL.h>
// #include <SDL2/SDL_opengl.h>
#include <memory>
#include <optional>
// #include "imgui.h"
// #include "imgui_impl_opengl2.h"
// #include "imgui_impl_sdl.h"

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

namespace dndcg {
namespace gui {
// struct Image {
//     // GLuint image;
//     int width;
//     int height;
// };

class Gui : public wxFrame {
   public:
    Gui();
    ~Gui();

    // int Init();
    // std::optional<Image> LoadTextureFromFile(const char* filename);
    // void MainLoop();

   private:
    // bool show_demo_window;
    // bool show_another_window;
    // ImVec4 clear_color;
    // SDL_Window* window;
    // SDL_GLContext gl_context;
    // std::optional<Image> logo;
    void onAbout(wxCommandEvent& event);
};
}  // namespace gui
}  // namespace dndcg