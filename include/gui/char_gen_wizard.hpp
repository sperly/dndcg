#pragma once

#include <wx/wizard.h>
#include <wx/wx.h>

#include <memory>
#include <vector>

namespace dndcg {
namespace gui {
class CharacterGenerationWizard {
 public:
    CharacterGenerationWizard(wxFrame* parent);
    ~CharacterGenerationWizard() { wizard->Destroy(); };

    void Run();

 private:
    wxWizard* wizard;
    characters::Character& character_;
    std::vector<wxWizardPageSimple*> pages;

    wxWizardPageSimple* generatePage1();
};
}  // namespace gui
}  // namespace dndcg
