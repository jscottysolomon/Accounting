/**
* @author Scotty Solomon
* @version 1.0
*/

#include <wx/wxprec.h>
#include <vector>
#include "data/parseXML.h"
#include"companyMain.hpp"

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#ifdef __WXMSW__
#include <wx/msw/msvcrt.h>      // redefines the new() operator 
#endif





enum {
	ID_BCENTER = 9,
	ID_RECONCILE = 10,
	ID_IMPORT = 12
};

companyMain::companyMain(wxFrame* parent) : wxFrame(parent, wxID_ANY, "Accounting") {

	//Accountant Menu
	//wxMenu* menuAccountant = new wxMenu

	//Banking Menu
	wxMenu* menuBanking = new wxMenu;
	menuBanking->Append(ID_BCENTER, "&Banking Center\tCtrl-B");
	menuBanking->AppendSeparator();
	menuBanking->Append(ID_RECONCILE, "&Reconcile\tCtrl-R");
	menuBanking->AppendSeparator();
	menuBanking->Append(ID_IMPORT, "Import File...\tCtrl-I");

	wxMenuBar*  menuBar = new wxMenuBar;

	menuBar->Append(menuBanking, "&Banking");

	SetMenuBar(menuBar);

	Bind(wxEVT_MENU, &companyMain::onImport, this, ID_IMPORT);
	Bind(wxEVT_MENU, &companyMain::onBankCenter, this, ID_BCENTER);
}

companyMain::~companyMain()
{
	Destroy();
}

void companyMain::onImport(wxCommandEvent& event)
{
	wxFileDialog iFile(this, "Select a file to import");
	int ret = iFile.ShowModal();
	wxString path = iFile.GetPath();
	iFile.Close();
	std::printf("test");

	if (ret == wxID_OK) {
		//std::vector<wxString> data =
		
	}
}

void companyMain::onBankCenter(wxCommandEvent& event) {
	wxPanel* bankCenter = new wxPanel();
}

void companyMain::OnClose(wxCloseEvent& event)
{
	Close(true);
}
