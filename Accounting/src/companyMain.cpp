/**
* @author Scotty Solomon
* @version 1.0
*/

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include"companyMain.h"

enum {
	ID_BCENTER = 9,
	ID_RECONCILE = 10,
	ID_IMPORT = 12
};

companyMain::companyMain(wxFrame* parent) : wxFrame(parent, wxID_ANY, "Accounting") {

	//Accountant Menu
	//wxMenu* menuAccountant = new wxMenu;
	

	//Banking Menu
	wxMenu* menuBanking = new wxMenu;
	menuBanking->Append(ID_BCENTER, "&Banking Center\tCtrl-B");
	menuBanking->AppendSeparator();
	menuBanking->Append(ID_RECONCILE, "&Reconcile\tCtrl-R");
	menuBanking->AppendSeparator();
	menuBanking->Append(ID_IMPORT, "Import File...\tCtrl-I");

	wxMenuBar* menuBar = new wxMenuBar;

	menuBar->Append(menuBanking, "&Banking");

	SetMenuBar(menuBar);

	Bind(wxEVT_MENU, &companyMain::onImport, this, ID_IMPORT);
	Bind(wxEVT_MENU, &companyMain::onBankCenter, this, ID_BCENTER);
}

void companyMain::onImport(wxCommandEvent& event)
{
	wxFileDialog* iFile = new wxFileDialog(this, "Select a file to import");
	int ret = iFile->ShowModal();
	wxString path = iFile->GetPath();

	if (ret == wxID_OK) {
		//TODO: parse file
	}
}

void companyMain::onBankCenter(wxCommandEvent& event) {
	wxPanel* bankCenter = new wxPanel();
}