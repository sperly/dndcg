#pragma once

#include <wx/wx.h>

#include "db_handler.hpp"

namespace dndcg {
namespace app {
class App : public wxApp {
 public:
    App();
    ~App() = default;

    virtual bool OnInit();

 private:
    dndcg::db::DbHandler db_;
};
}  // namespace app
}  // namespace dndcg
