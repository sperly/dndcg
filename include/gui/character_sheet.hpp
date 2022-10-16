#pragma once

#include <wx/wx.h>

class CharacterSheet : public wxPanel {
   public:
    CharacterSheet(wxPanel* parent, int id);

    wxPanel* m_parent;

    void OnSize(wxSizeEvent& event);
    void OnPaint(wxPaintEvent& event);
};
