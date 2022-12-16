#pragma once
#ifndef PARSEXML_H
#define PARSEXML_H

wxString parseXML(wxWindow* parent);
boolean addRule(wxString identifier, wxString vendor, wxString category, int ein);
boolean addRule(wxString memo);
struct transactions {
	wxString type;
	int date;
	int amt;
	wxString name;
	wxString memo;

	transactions(wxString type = wxEmptyString, int date = 0, int amt = 0,
		wxString name = wxEmptyString, wxString memo = wxEmptyString) :
		type(type), date(date), amt(amt), name(name), memo(memo) {}

};
#endif


