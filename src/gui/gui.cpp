#include "gui/gui.hpp"

#include "../utils.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace dndcg {
namespace gui {
enum { ID_Hello = 1 };
Gui::Gui() : wxFrame(NULL, wxID_ANY, L"DoD Karaktär Generator") {
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    wxColour col1, col2;
    col1.Set(wxT("#4f5049"));
    col2.Set(wxT("#ededed"));
    wxPanel* panel = new wxPanel(this, -1);
    panel->SetBackgroundColour(col1);
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    wxPanel* midPan = new wxPanel(panel, wxID_ANY);
    midPan->SetBackgroundColour(col2);

    vbox->Add(midPan, 1, wxEXPAND | wxALL, 20);
    panel->SetSizer(vbox);

    Centre();

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    Bind(
        wxEVT_MENU, [=](wxCommandEvent&) { wxLogMessage("Hello world from wxWidgets!"); }, ID_Hello);
    Bind(wxEVT_MENU, &Gui::onAbout, this, wxID_ABOUT);
    Bind(
        wxEVT_MENU, [=](wxCommandEvent&) { Close(true); }, wxID_EXIT);
}

void Gui::onAbout(wxCommandEvent& event) {
    wxMessageBox(L"Karaktärs-generator för Drakar och Demoner,\nspeciellt anpassad för Experts rollformulär.", "Om DnDCG",
                 wxOK | wxICON_INFORMATION);
}

Gui::~Gui() {
    // ImGui_ImplOpenGL2_Shutdown();
    // ImGui_ImplSDL2_Shutdown();
    // ImGui::DestroyContext();

    // SDL_GL_DeleteContext(gl_context);
    // SDL_DestroyWindow(window);
    // SDL_Quit();
}

}  // namespace gui
}  // namespace dndcg