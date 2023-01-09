/**
* @author Scotty Solomon
* @version 1.0
*/

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !_CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string>

#include <wx/wx.h>
#include <wx/xml/xml.h>
#include <wx/string.h>
#include <wx/fileconf.h>

#include "parseXML.hpp"

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
				if (data->GetName() == "TRNTYPE") {
					ret += data->GetNodeContent();
				}
				else if (data->GetName() == "DTPOSTED") {
					ret += data->GetNodeContent();
				}
				else if (data->GetName() == "TRNAMT") {
					ret += data->GetNodeContent();
				}
				else if (data->GetName() == "NAME") {
					ret += data->GetNodeContent();
				}
				else {
					//memo
				}

				data = data->GetNext();
			}
			//ret += stmTtrn->GetName();
			stmTtrn = stmTtrn->GetNext();
		}
		//xmlDocument deletes all its xmlNode pointers when it goes out of scope
	}

	//addRule("", "", "", 0);

	iFile->Close();
	delete iFile;
	iFile = nullptr;
	return ret;
}
