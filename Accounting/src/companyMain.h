#pragma once
#ifndef COMPANYMAIN_H
#define COMPANYMAIN_H

class companyMain : public wxFrame 
{
public:
	companyMain(wxFrame* parent);
	//~companyMain();
private:
	void onImport(wxCommandEvent& event);
};

#endif