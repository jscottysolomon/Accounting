/**
* @author Scotty Solomon
* @version 1.0
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string.h>

#include <wx/wx.h>
#include <wx/xml/xml.h>
#include <wx/string.h>
#include <wx/fileconf.h>

#include <soci/soci.h>
#include <soci/mysql/soci-mysql.h>

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

	addRule("", "", "", 0);

	iFile->Close();
	delete iFile;
	iFile = nullptr;
	return ret;
}

boolean addRule(wxString identifier, wxString vendor, wxString category, int ein) {
	//Reading config file
	wxFileConfig config("config.properties");

	//Retrieve information from config.properties
	wxString host = config.Read("database.host");
	wxString user = config.Read("database.user");
	wxString password = config.Read("database.password");
	wxString dbname = config.Read("database.dbname");

	std::string host_str = host.ToStdString();
	std::string user_str = user.ToStdString();
	std::string password_str = password.ToStdString();
	std::string dbname_str = dbname.ToStdString();

	soci::session sql(soci::mysql, "host=" + host_str + " user=" + user_str + " password=" + password_str + " db=" + dbname_str);


	sql.close();
	return false;
}

boolean addRule(wxString memo) {
	return false;
}
