#include "communicate.h"
#include <clocale>
#include <wx/gdicmn.h>
#include <wx/generic/panelg.h>
#include <wx/sizer.h>

Communicate::Communicate(const wxString& title)
    :wxFrame(NULL,wxID_ANY,title,wxDefaultPosition,wxSize(290,150))
{
    wxPanel *panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

    m_lp = new LeftPanel(panel);
    m_rp = new RightPanel(panel);

    hbox->Add(m_lp,1,wxEXPAND|wxALL,5);
    hbox->Add(m_rp,1,wxEXPAND|wxALL,5);

    this->Centre();

}
