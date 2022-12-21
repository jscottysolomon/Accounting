#include <wx/wx.h>
#include <vector>
#include <wx/xml/xml.h>
#include <string.h>
#include <wx/string.h>
#include <iostream>
#include "../../include/parseXML.hpp"
#include "../../include/companyMain.hpp"

#ifdef __WXMSW__
#include <wx/msw/msvcrt.h>      // redefines the new() operator 
#endif

/**
* Window that pop-ups when a user opens a company's file
* 
* @author Scotty Solomon
*/

enum {
	ID_BCENTER = 9,
	ID_RECONCILE = 10,
	ID_IMPORT = 12
};

/**
* Constructor that sets up menu and window panel
*
*/
companyMain::companyMain(wxFrame* parent) : wxFrame(parent, wxID_ANY, "Accounting") {
	//Banking Menu
	panel = new wxPanel(this);

	wxMenu* menuBanking = new wxMenu;
	menuBanking->Append(ID_BCENTER, "&Banking Center\tCtrl-B");
	menuBanking->AppendSeparator();
	menuBanking->Append(ID_RECONCILE, "&Reconcile\tCtrl-R");
	menuBanking->AppendSeparator();
	menuBanking->Append(ID_IMPORT, "Import File...\tCtrl-I");

	wxMenuBar*  menuBar = new wxMenuBar();

	menuBar->Append(menuBanking, "&Banking");

	SetMenuBar(menuBar);

	Bind(wxEVT_MENU, &companyMain::onImport, this, ID_IMPORT);
	Bind(wxEVT_MENU, &companyMain::onBankCenter, this, ID_BCENTER);
}

//Deconstructor
companyMain::~companyMain()
{
	//Delets most raw pointers to wxWidget objects
	Destroy();
	//delete manuBar;
}


void companyMain::onImport(wxCommandEvent& event)
{
	wxString retString = parseXML(this);
	wxTextCtrl* textBox = new wxTextCtrl(panel, wxID_ANY);
	textBox->AppendText(retString);
	//textbox is leaked, I think.
}

void companyMain::onBankCenter(wxCommandEvent& event) {
	wxPanel* bankCenter = new wxPanel();
}

void companyMain::OnClose(wxCloseEvent& event)
{
	Close(true);
}
