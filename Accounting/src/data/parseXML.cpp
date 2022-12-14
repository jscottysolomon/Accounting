/**
* @author Scotty Solomon
* @version 1.0
*/

#include <wx/wxprec.h>
#include <list>
#include <wx/xml/xml.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <wx/string.h>
#include "parseXML.hpp"

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#ifdef __WXMSW__
#include <wx/msw/msvcrt.h>      // redefines the new() operator 
#endif

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
wxString parseXML(wxWindow * parent){
	wxFileDialog* iFile = new wxFileDialog(parent, "Select a file to import");
	int status = iFile->ShowModal();
	wxString ret = wxEmptyString;

	if (status == wxID_OK) {
		ret = "";

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

		//dealocating memory
		
		
		
		
		//delete stmTtrn;
		//stmTtrn = nullptr;
		/*delete bankTranList;
		bankTranList = nullptr;
		delete stmtrs;
		stmtrs = nullptr;
		delete stmTrnrs;
		stmTrnrs = nullptr;
		delete bankMsg;
		bankMsg = nullptr;*/
	}

	iFile->Close();
	delete iFile;
	iFile = nullptr;
	return ret;
}
