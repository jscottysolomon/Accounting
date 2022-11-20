#pragma once
#ifndef COMPANYMAIN_H
#define COMPANYMAIN_H

class companyMain : public wxFrame 
{
public:
	companyMain();
	~companyMain();
private:
	void onImport(wxCommandEvent& event);
};

#endif