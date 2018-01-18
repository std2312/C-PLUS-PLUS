; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSysSetting
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "server.h"
LastPage=0

ClassCount=10
Class1=CCustomGroup
Class2=CServerApp
Class3=CAboutDlg
Class4=CServerDlg
Class5=CSysSetting

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDD_SYSSETTING_DIALOG
Resource3=IDD_LOGIN_DIALOG
Class6=CLogin
Resource4=IDD_SERVER_DIALOG
Class7=COprManage
Class8=CCustomHeader
Class9=CCustomListCtrl
Class10=CCustomButton
Resource5=IDD_OPRMANAGE_DIALOG

[CLS:CCustomGroup]
Type=0
BaseClass=CStatic
HeaderFile=CustomGroup.h
ImplementationFile=CustomGroup.cpp

[CLS:CServerApp]
Type=0
BaseClass=CWinApp
HeaderFile=Server.h
ImplementationFile=Server.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=ServerDlg.cpp
ImplementationFile=ServerDlg.cpp
LastObject=IDOK

[CLS:CServerDlg]
Type=0
BaseClass=CDialog
HeaderFile=ServerDlg.h
ImplementationFile=ServerDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDC_BACKGROUND

[CLS:CSysSetting]
Type=0
BaseClass=CDialog
HeaderFile=SysSetting.h
ImplementationFile=SysSetting.cpp
LastObject=CSysSetting
Filter=D
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SERVER_DIALOG]
Type=1
Class=CServerDlg
ControlCount=11
Control1=IDC_BTUP,button,1342242827
Control2=IDC_BTLEFT,button,1342242827
Control3=IDC_BTRIGHT,button,1342242827
Control4=IDC_BTDOWN,button,1342242827
Control5=IDC_BTRESTORE,button,1342242827
Control6=IDC_BACKGROUND,static,1350565895
Control7=IDC_SYSSETTING,button,1342242827
Control8=IDC_OPERATORMGE,button,1342242827
Control9=IDC_QUIT,button,1342242827
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,button,1342177287

[DLG:IDD_SYSSETTING_DIALOG]
Type=1
Class=CSysSetting
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=IDC_CLIENTIP,SysIPAddress32,1342242816
Control3=IDC_CONFIRM,button,1342242816
Control4=IDC_CANCEL,button,1342242816
Control5=IDC_STATIC,static,1342177283

[DLG:IDD_LOGIN_DIALOG]
Type=1
Class=CLogin
ControlCount=8
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_USERNAME,edit,1350631552
Control4=IDC_PASSWORD,edit,1350631584
Control5=IDC_STATIC,static,1342181383
Control6=IDC_STATIC,static,1342177283
Control7=IDC_LOGIN,button,1342242816
Control8=IDC_BTCANCLE,button,1342242816

[CLS:CLogin]
Type=0
HeaderFile=Login.h
ImplementationFile=Login.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CLogin

[DLG:IDD_OPRMANAGE_DIALOG]
Type=1
Class=COprManage
ControlCount=12
Control1=IDC_LISTINFO,SysListView32,1350631425
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_USER,edit,1350631552
Control7=IDC_PASS,edit,1350631584
Control8=IDC_CONFIRMPASS,edit,1350631584
Control9=IDC_BTADD,button,1342242816
Control10=IDC_BTUPDATE,button,1342242816
Control11=IDC_BTDELETE,button,1342242816
Control12=IDC_STATIC,static,1342308352

[CLS:COprManage]
Type=0
HeaderFile=OprManage.h
ImplementationFile=OprManage.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=COprManage

[CLS:CCustomHeader]
Type=0
HeaderFile=CustomHeader.h
ImplementationFile=CustomHeader.cpp
BaseClass=CHeaderCtrl
Filter=W
VirtualFilter=JWC

[CLS:CCustomListCtrl]
Type=0
HeaderFile=CustomListCtrl.h
ImplementationFile=CustomListCtrl.cpp
BaseClass=CListCtrl
Filter=W
VirtualFilter=FWC

[CLS:CCustomButton]
Type=0
HeaderFile=CustomButton.h
ImplementationFile=CustomButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC
LastObject=CCustomButton

