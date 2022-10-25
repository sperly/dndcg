#include "gui/gui.hpp"

#include <vector>

#include "gui/character_sheet.hpp"

#include "db_handler.hpp"
#include "stats/character.hpp"
#include "utils.hpp"

#include <wx/wizard.h>
#include <wx/wx.h>

namespace dndcg {
namespace gui {
enum { ID_Hello = 1, ID_Open, ID_Edit };

Gui::Gui(const wxString& title, dndcg::db::DbHandler& db_handler)
    : wxFrame((wxFrame*)NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150)), db_handler_(db_handler) {  // NOLINT

    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Open, "&Open\tCtrl-L", "Open database for character data.");
    menuFile->Append(ID_Edit, "Edit Character\tCtrl-E", "Edit current character");

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
        wxEVT_MENU,
        [this](wxCommandEvent&) {
            std::unique_ptr<std::vector<std::pair<int, std::pair<std::string, std::string>>>> characters =
                this->db_handler_.GetCharacters();
        },
        ID_Open);
    Bind(wxEVT_MENU, &Gui::onAbout, this, wxID_ABOUT);
    Bind(
        wxEVT_MENU, [=](wxCommandEvent&) { Close(true); }, wxID_EXIT);
}

void Gui::onAbout(wxCommandEvent& event) {
    // wxMessageBox(L"Karaktärs-generator för Drakar och Demoner,\nspeciellt anpassad för Experts rollformulär.", "Om DnDCG",
    //              wxOK | wxICON_INFORMATION);

    std::vector<wxWizardPageSimple*> pages;
    wxWizard* wizard =
        new wxWizard(this, wxID_ANY, wxT("Absolutely Useless Wizard"), wxNullBitmap, wxDefaultPosition, wxDEFAULT_DIALOG_STYLE);

    pages.emplace_back(new wxWizardPageSimple(wizard, NULL, NULL, wxNullBitmap));

    wizard->RunWizard(pages[0]);

    wizard->Destroy();
}

}  // namespace gui
}  // namespace dndcg
