#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
namespace dndcg {
namespace app {
class App : public wxApp {
   public:
    virtual bool OnInit();
};
}  // namespace app
}  // namespace dndcg