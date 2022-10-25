#pragma once

#include <wx/wizard.h>
#include <wx/wx.h>
#include <vector>

namespace dndcg {
namespace gui {
class CharacterGenerationWizard : public wxWizard {
 public:
    CharacterGenerationWizard();
    ~CharacterGenerationWizard(){};

 private:
    wxWizard* wizard;
    std::vector<wxWizardPage*> pages;
};
}  // namespace gui
}  // namespace dndcg
