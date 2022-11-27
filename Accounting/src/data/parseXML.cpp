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
#include "parseXML.h"

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#ifdef __WXMSW__
#include <wx/msw/msvcrt.h>      // redefines the new() operator 
#endif

static std::vector<wxString> parseXML(wxString path){
	wxXmlDocument xmlDoc;

	if (!xmlDoc.Load(path)) {
		//handle error
	}



}