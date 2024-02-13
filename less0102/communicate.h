#include <wx/wx.h>
#include "panels.h"

class Communicate : public wxFrame
{
public:
    Communicate(const wxString& title);
    LeftPanel *m_lp;
    RightPanel *m_rp;
};

