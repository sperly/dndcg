#include "gui/char_gen_wizard.hpp"

#include "wx/richtext/richtextctrl.h"

#include "stats/character.hpp"

namespace dndcg {
namespace gui {

CharacterGenerationWizard::CharacterGenerationWizard(wxFrame* parent, characters::Character& character)
    : wizard(new wxWizard(parent, wxID_ANY, wxT("Absolutely Useless Wizard"), wxNullBitmap, wxDefaultPosition, wxDEFAULT_DIALOG_STYLE),
             character_(character)) {
    pages.emplace_back(generatePage1());
}

void CharacterGenerationWizard::Run() {
    if (wizard->RunWizard(pages[0])) {
        wxMessageBox(wxT("The wizard successfully completed"), wxT("That'sall"), wxICON_INFORMATION | wxOK);
    }
}

wxWizardPageSimple* CharacterGenerationWizard::generatePage1() {
    wxWizardPageSimple* page = new wxWizardPageSimple(wizard, NULL, NULL, wxNullBitmap);

    wxRichTextCtrl* richTextCtrl = new wxRichTextCtrl(page, -1, "Lite text...", wxDefaultPosition, wxSize(200, 200), wxRE_MULTILINE,
                                                      wxDefaultValidator, wxTextCtrlNameStr);

    return page;
}

}  // namespace gui
}  // namespace dndcg