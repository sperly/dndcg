#pragma once

#include <memory>
#include <optional>

#include <wx/wx.h>

#include <wx/frame.h>

#include "db_handler.hpp"

namespace dndcg {
namespace gui {
// struct Image {
//     // GLuint image;
//     int width;
//     int height;
// };

class Gui : public wxFrame {
 public:
    Gui(const wxString& title, dndcg::db::DbHandler& db_handler);
    ~Gui(){};

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
    dndcg::db::DbHandler& db_handler_;
};
}  // namespace gui
}  // namespace dndcg