# Accounting
## Overview
### Main Goal
  The current goal of this repository is to develop accounting software that can be used by professionals to manage multiple client company from one main directory. Most accounting software available targets buisness owners, rather than accountants. This software is intended to be used by professionals managing multiple clients and attempts to offer quality-of-life improvements over traditional accounting software.
  
## Quality of Life Goals
Although this software is early in development, projected quality of life imporvements for accounting professionals includes: User-generated "rules" for bookkeeping shared across mutlipe companies, the ability to create complex rules that take into account transaction memos and transaction amounts, the ability to bulk recategorize cleared bank transactions, automating reocurring payroll that is target toward owners of corporations, allowing payroll data for a company to be imported via .csv, the ability to bulk file quarterly payroll returns across multiple companies, and single notification hub to track any rejected payments across mutliple companies.
## Requirements
### 1. WxWidgets Library
  WxWidgets is an open source gui library for C and C++ development. A locally built installation of the library is required. The WxWidgets library can be retrieved from www.wxwidgets.org/ and can be built in Visual Studios using the included .sln file in WxWidgets/build/msw
### 2. WXWIN Environment Variable
  Requires %WXWIN% enviroment variable to be pointing to the main directory of the WxWidets library.
