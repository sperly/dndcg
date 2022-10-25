#include "app.hpp"

#include "db_handler.hpp"
#include "gui/gui.hpp"
#include "stats/character.hpp"

namespace dndcg {
namespace app {
bool App::OnInit() {
    dndcg::db::DbHandler db("../db/dndcg.db");

    dndcg::gui::Gui* frame = new dndcg::gui::Gui(L"DoD Karaktär Generator", db);
    frame->Show(true);
    return true;
}
}  // namespace app
}  // namespace dndcg
