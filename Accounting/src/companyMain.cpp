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

companyMain::companyMain() : wxFrame(nullptr, wxID_ANY, "Accounting") {
	wxMenu* menuBanking = new wxMenu;

	menuBanking->Append(ID_BCENTER, "&Banking Center\tCtrl-C");
	menuBanking->AppendSeparator();
	menuBanking->Append(ID_RECONCILE, "&Reconcile\tCtrl-R");
	menuBanking->AppendSeparator();
	menuBanking->Append(ID_IMPORT, "Import File...\tCtrl-I");

	wxMenuBar* menuBar = new wxMenuBar;

	menuBar->Append(menuBanking, "&Banking");

	SetMenuBar(menuBar);
}

companyMain::~companyMain()
{
}
