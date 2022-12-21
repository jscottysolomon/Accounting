/**
* @author Scotty Solomon
* @version 1.0
*/

#include <wx/wx.h>
#include "Accounting.h"
#include "companyMain.hpp"


enum
{
    ID_Hello = 1,
    FILE_MENU = 2,
    OPEN_COMPANY = 3,
    CREATE_COMPANY = 4,
    ACCOUNTING = 5,
    EMPLOYEE = 6,
    PAY_EMPLOYEE = 7,
    REOCCURRING = 8
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame()
    : wxFrame(nullptr, wxID_ANY, "Accounting")
{
    //FILE column
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(OPEN_COMPANY, "&Open Company...\tCtrl-O");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    
    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    //ACCOUNTING menu
    wxMenu* menuOptions = new wxMenu;

    //EMPLOYEE menu
    wxMenu* menuEmployee = new wxMenu;
    menuEmployee->Append(PAY_EMPLOYEE, "&Pay Employees");
    menuEmployee->AppendSeparator();
    menuEmployee->Append(REOCCURRING, "&Manage Reoccurring");

    //Addding menus to menuBars
    wxMenuBar* menuBar = new wxMenuBar; //delete ptr

    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuOptions, "&Accountant");
    menuBar->Append(menuEmployee, "&Employees");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MyFrame::OnOpen, this, OPEN_COMPANY);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    _CrtDumpMemoryLeaks();
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a current work in progress!");
}

void MyFrame::OnOpen(wxCommandEvent& event)
{
    companyMain* view = new companyMain(this);
    view->Show(true);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

