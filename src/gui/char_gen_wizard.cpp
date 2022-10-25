#include "gui/char_gen_wizard.hpp"

namespace dndcg {
namespace gui {

CharacterGenerationWizard::CharacterGenerationWizard()
    : wizard{new wxWizard(this, wxID_ANY, wxT("Absolutely Useless Wizard"), wxNullBitmap, wxDefaultPosition,
                          wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER)} {
    pages.emplace_back(new wxWizardPageSimple());
}

void CharacterGenerationWizard::Run() {
    if (wizard->RunWizard(pages[0])) {
        wxMessageBox(wxT("The wizard successfully completed"), wxT("That'sall"), wxICON_INFORMATION | wxOK);
    }
}

}  // namespace gui
}  // namespace dndcg