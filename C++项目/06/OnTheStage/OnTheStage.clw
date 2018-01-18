; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CInsertdlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "OnTheStage.h"

ClassCount=4
Class1=COnTheStageApp
Class2=COnTheStageDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_INSERT_DIALOG
Class4=CInsertdlg
Resource4=IDD_ONTHESTAGE_DIALOG
Resource5=IDD_LOGIN_DIALOG

[CLS:COnTheStageApp]
Type=0
HeaderFile=OnTheStage.h
ImplementationFile=OnTheStage.cpp
Filter=N

[CLS:COnTheStageDlg]
Type=0
HeaderFile=OnTheStageDlg.h
ImplementationFile=OnTheStageDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=COnTheStageDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=OnTheStageDlg.h
ImplementationFile=OnTheStageDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ONTHESTAGE_DIALOG]
Type=1
Class=COnTheStageDlg
ControlCount=14
Control1=IDC_LIST1,SysListView32,1350631813
Control2=IDC_TITLE,static,1342308353
Control3=IDC_STATICT,static,1342308352
Control4=IDC_BUTTONADD,button,1342242816
Control5=IDC_BUTTONOK,button,1342242816
Control6=IDC_STATICY,static,1342308352
Control7=IDC_EDIT1,edit,1350631552
Control8=IDC_STATICS,static,1342308352
Control9=IDC_EDIT2,edit,1350631552
Control10=IDC_TIME,static,1342308352
Control11=IDC_STATICD,static,1342308352
Control12=IDC_DATE,static,1342308352
Control13=IDC_STATICZ,static,1342308352
Control14=IDC_EDIT3,edit,1350631552

[DLG:IDD_INSERT_DIALOG]
Type=1
Class=CInsertdlg
ControlCount=6
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_EDIT2,edit,1350639744
Control3=IDOK,button,1342242816
Control4=IDC_COMBO1,combobox,1344339970
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,button,1342177287

[CLS:CInsertdlg]
Type=0
HeaderFile=Insertdlg.h
ImplementationFile=Insertdlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_LOGIN_DIALOG]
Type=1
Class=?
ControlCount=5
Control1=IDOK,button,1073807361
Control2=IDCANCEL,button,1073807360
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631584
Control5=IDC_STATIC,static,1342177294

