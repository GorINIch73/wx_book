#include "Listbox.h"
#include <wx/textdlg.h>


Listbox::Listbox(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(270, 200))
{

  wxPanel * panel = new wxPanel(this, -1);

  wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

  listbox = new wxListBox(panel, ID_LISTBOX, 
      wxPoint(-1, -1), wxSize(-1, -1)); 

  hbox->Add(listbox, 3, wxEXPAND | wxALL, 20);

  btnPanel = new MyPanel(panel);
  hbox->Add(btnPanel, 2, wxEXPAND | wxRIGHT, 10);

  Connect(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, 
      wxCommandEventHandler(Listbox::OnDblClick));

  panel->SetSizer(hbox);
  Center();  
}


MyPanel::MyPanel(wxPanel * parent)
       : wxPanel(parent, wxID_ANY)
{
  wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

  Listbox *lb = (Listbox *) parent->GetParent();
  m_lb = lb->listbox;

  m_newb = new wxButton(this, wxID_NEW, wxT("New"));
  m_renameb = new wxButton(this, ID_RENAME, wxT("Rename"));
  m_deleteb = new wxButton(this, wxID_DELETE, wxT("Delete"));
  m_clearb = new wxButton(this, wxID_CLEAR, wxT("Clear"));

  Connect(wxID_NEW, wxEVT_COMMAND_BUTTON_CLICKED, 
      wxCommandEventHandler(MyPanel::OnNew) );
  Connect(ID_RENAME, wxEVT_COMMAND_BUTTON_CLICKED, 
      wxCommandEventHandler(MyPanel::OnRename) );
  Connect(wxID_CLEAR, wxEVT_COMMAND_BUTTON_CLICKED, 
      wxCommandEventHandler(MyPanel::OnClear) );
  Connect(wxID_DELETE, wxEVT_COMMAND_BUTTON_CLICKED, 
      wxCommandEventHandler(MyPanel::OnDelete) );

  vbox->Add(-1, 20);
  vbox->Add(m_newb);
  vbox->Add(m_renameb, 0, wxTOP, 5);
  vbox->Add(m_deleteb, 0, wxTOP, 5);
  vbox->Add(m_clearb, 0, wxTOP, 5);

  SetSizer(vbox);
}

void MyPanel::OnNew(wxCommandEvent& event) 
{
  wxString str = wxGetTextFromUser(wxT("Add new item"));
  if (str.Len() > 0)
      m_lb->Append(str); 
}

void MyPanel::OnClear(wxCommandEvent& event) 
{
  m_lb->Clear();
}

void MyPanel::OnRename(wxCommandEvent& event) 
{
  wxString text;
  wxString renamed;
  
  int sel = m_lb->GetSelection();
  if (sel != -1) {
      text = m_lb->GetString(sel);
      renamed = wxGetTextFromUser(wxT("Rename item"), 
                  wxT("Rename dialog"), text);
  }

  if (!renamed.IsEmpty()) {
      m_lb->Delete(sel);
      m_lb->Insert(renamed, sel);
  }
}


void MyPanel::OnDelete(wxCommandEvent& event) 
{
  int sel = m_lb->GetSelection();
  if (sel != -1) {
      m_lb->Delete(sel);
  }
}

void Listbox::OnDblClick(wxCommandEvent& event) 
{
  wxString text;
  wxString renamed;

  int sel = listbox->GetSelection();
  if (sel != -1) {
      text = listbox->GetString(sel);
      renamed = wxGetTextFromUser(wxT("Rename item"), 
                  wxT("Rename dialog"), text);
  } 

  if (!renamed.IsEmpty()) {
      listbox->Delete(sel);
      listbox->Insert(renamed, sel);
  }
}
