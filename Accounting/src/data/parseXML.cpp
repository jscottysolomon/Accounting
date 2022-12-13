/**
* @author Scotty Solomon
* @version 1.0
*/

#include <wx/wxprec.h>
#include <list>
#include <wx/string.h>
#include <wx/xml/xml.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "parseXML.hpp"

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#ifdef __WXMSW__
#include <wx/msw/msvcrt.h>      // redefines the new() operator 
#endif

wxString parseXML(wxWindow * parent){
	wxFileDialog* iFile = new wxFileDialog(parent, "Select a file to import");
	int ret = iFile->ShowModal();

	wxString ret = "";

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

		wxXmlNode* data;



		while (stmTtrn) {
			data = stmTtrn->GetChildren();
			while (data) {
				ret += data->GetNodeContent();
				data = data->GetNext();
			}
			ret += stmTtrn->GetName();
			stmTtrn = stmTtrn->GetNext();
		}
	}


	return ret;
}