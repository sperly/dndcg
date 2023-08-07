#include "app.hpp"

#include "gui/gui.hpp"
#include "stats/character.hpp"

namespace dndcg {
namespace app {

App::App() : db_("../assets/db/dndcg.db") {}

bool App::OnInit() {
    dndcg::gui::Gui* frame = new dndcg::gui::Gui(L"DoD Karaktär Generator", db_);
    frame->Show(true);
    return true;
}
}  // namespace app
}  // namespace dndcg
