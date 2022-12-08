#include <wx/wxprec.h>
#include <vector>
#include <wx/xml/xml.h>
#include <string.h>
#include <wx/string.h>
#include <iostream>
#include "data/parseXML.hpp"
#include "companyMain.hpp" 

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

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
	Destroy();
}

/**
* On selecting an xml file to import, the file is parased
* 
* .QBO file struture to retrieve tranactions:
* 
* <OFX>
*	<SIGNONMSGSRSV1>
*	<BANKMSGSRSV1>
*		<STMTRNRS>
*		<STMTRS>
*			<CURDEF>
*			<BANKACCTFROM>
*			<BANKTRANLIST>
*				<DTSTART>
*				<DTEND>
*				<STMTTRN>
*					<TRNTYPE>
*					<DTPOSTED>
*					<TRNAMT>
*					<FITID>
*					<MEMO>
*/
void companyMain::onImport(wxCommandEvent& event)
{
	wxFileDialog * iFile = new wxFileDialog(this, "Select a file to import");
	int ret = iFile->ShowModal();

	wxTextCtrl* textBox = new wxTextCtrl(panel, wxID_ANY);
	
	if (ret == wxID_OK) {
		wxString ret = "";

		wxXmlDocument xmlDoc;
		xmlDoc.Load(iFile->GetPath());

		if (xmlDoc.GetRoot()->GetName() != "OFX") {
			//ret = wxEmptyString;

		}
		
		//BANKMSGSRSV1
		wxXmlNode* bankMsg = xmlDoc.GetRoot()->GetChildren();
		bankMsg = bankMsg->GetNext();

		//STMTTRNRS
		wxXmlNode* stmTrnrs = bankMsg->GetChildren();

		//stmtrs
		wxXmlNode* stmtrs = stmTrnrs->GetChildren();
		stmtrs = stmtrs->GetNext();
		stmtrs = stmtrs->GetNext();

		//BANKTRANLIST
		wxXmlNode* bankTranList = stmtrs->GetChildren();
		bankTranList = bankTranList->GetNext(); //bank info here <BANKACCTFROM>
		bankTranList = bankTranList->GetNext();

		wxXmlNode* stmTtrn = bankTranList->GetChildren();
		stmTtrn = stmTtrn->GetNext();
		stmTtrn = stmTtrn->GetNext();

		wxXmlNode* data = stmTtrn->GetChildren();

		/*ret += data->GetNodeContent();
		data = data->GetNext();
		ret += data->GetNodeContent();
		data = data->GetNext();
		ret += data->GetNodeContent();
		data = data->GetNext();

		stmTtrn = stmTtrn->GetNext();
		data = stmTtrn->GetChildren();
		ret += data->GetNodeContent();
		data = data->GetNext();*/

		wxString test = "";

		for(int ii = 0; ii < 4; ii++) {
			for(int xx = 1; xx < 3; xx++) {
				test += data->GetNodeContent();
				data = data->GetNext();
			}

			stmTtrn = stmTtrn->GetNext();
			data = stmTtrn->GetChildren();
		}

		textBox->AppendText(test);

	}
	iFile->Close();
	delete iFile;
}

void companyMain::onBankCenter(wxCommandEvent& event) {
	wxPanel* bankCenter = new wxPanel();
}

void companyMain::OnClose(wxCloseEvent& event)
{
	Close(true);
}
