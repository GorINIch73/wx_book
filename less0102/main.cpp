#include "main.h"
#include "communicate.h"
//#include "panels.h"
#include <wx/app.h>

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    
    Communicate *commnc = new Communicate(wxT("Communicate"));

    commnc->Show(true);

    return true;
}
