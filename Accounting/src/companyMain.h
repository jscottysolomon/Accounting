#pragma once
#ifndef COMPANYMAIN_H
#define COMPANYMAIN_H

class companyMain : public wxFrame 
{
public:
	companyMain(wxFrame* parent);
private:
	void onImport(wxCommandEvent& event);
	void onBankCenter(wxCommandEvent& event);
};

#endif