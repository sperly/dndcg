#include "gui/character_sheet.hpp"

CharacterSheet::CharacterSheet(wxPanel* parent, int id) : wxPanel(parent, id, wxDefaultPosition, wxSize(-1, 30), wxSUNKEN_BORDER) {

    m_parent = parent;

    Connect(wxEVT_PAINT, wxPaintEventHandler(CharacterSheet::OnPaint));
    Connect(wxEVT_SIZE, wxSizeEventHandler(CharacterSheet::OnSize));
}

void CharacterSheet::OnPaint(wxPaintEvent& event) {}

void CharacterSheet::OnSize(wxSizeEvent& event) {
    Refresh();
}