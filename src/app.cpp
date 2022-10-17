#include "app.hpp"

#include "stats/character.hpp"
#include "db_handler.hpp"
#include "gui/gui.hpp"

namespace dndcg {
namespace app {
bool App::OnInit() {
    dndcg::db::DbHandler db("../db/dndcg.db");
    dndcg::gui::Gui* frame = new dndcg::gui::Gui();
    frame->Show(true);
    return true;
}
}  // namespace app
}  // namespace dndcg
