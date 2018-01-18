; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCaptureDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "capture.h"
LastPage=0

ClassCount=10
Class1=CCaptureApp
Class2=CAboutDlg
Class3=CCaptureDlg
Class4=COverlay

ResourceCount=8
Resource1=IDD_PANEL_DIALOG
Resource2=IDD_ABOUTBOX
Class5=CPreView
Class6=CPanel
Resource3=IDD_CONTROLFORM_DIALOG
Resource4=IDD_PLAY_DIALOG
Class7=CAutodlg
Resource5=IDD_AUTOMATISM_DIALOG
Class8=CPlaydlg
Resource6=IDD_CAPTURE_DIALOG
Class9=CLogin
Resource7=IDD_LOGIN_DIALOG
Class10=CManagedlg
Resource8=IDD_MANAGE_DIALOG

[CLS:CCaptureApp]
Type=0
BaseClass=CWinApp
HeaderFile=Capture.h
ImplementationFile=Capture.cpp
Filter=N
VirtualFilter=AC
LastObject=CCaptureApp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=CaptureDlg.cpp
ImplementationFile=CaptureDlg.cpp

[CLS:CCaptureDlg]
Type=0
BaseClass=CDialog
HeaderFile=CaptureDlg.h
ImplementationFile=CaptureDlg.cpp
Filter=W
VirtualFilter=dWC
LastObject=CCaptureDlg

[CLS:COverlay]
Type=0
BaseClass=CDialog
HeaderFile=Overlay.h
ImplementationFile=Overlay.cpp

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CAPTURE_DIALOG]
Type=1
Class=CCaptureDlg
ControlCount=27
Control1=IDC_SNAPSHOT,button,1342373888
Control2=IDC_BMP,button,1342177284
Control3=IDC_JPG,button,1342177284
Control4=IDC_VGA,button,1342177284
Control5=IDC_PCI,button,1342177284
Control6=IDC_SETTING,button,1342242816
Control7=IDC_STATIC1,button,1342177287
Control8=IDC_RELEN,button,1342242816
Control9=IDC_REFOCI,button,1342242816
Control10=IDC_INFOCI,button,1342242816
Control11=IDC_INLEN,button,1342242816
Control12=IDC_REAPERTURE,button,1342242816
Control13=IDC_INAPERTURE,button,1342242816
Control14=IDC_INBRUSH,button,1342242816
Control15=IDC_REBRUSH,button,1342242816
Control16=IDC_STATIC2,button,1342177287
Control17=IDC_BUTTONUP,button,1342242816
Control18=IDC_BUTTONLEFT,button,1342242816
Control19=IDC_BUTTONRIGHT,button,1342242816
Control20=IDC_BUTTONDOWN,button,1342242816
Control21=IDC_MSCOMM1,{648A5600-2C6E-101B-82B6-000000000014},1342242816
Control22=IDC_CONTROL,button,1342373888
Control23=IDC_AUTOMATISM,button,1342373888
Control24=IDC_KINESCOPE,button,1342373888
Control25=IDC_PLAY,button,1342373888
Control26=IDC_MANAGE,button,1342373888
Control27=IDC_STOP,button,1342242816

[CLS:CPreView]
Type=0
HeaderFile=PreView.h
ImplementationFile=PreView.cpp
BaseClass=CStatic
Filter=W
VirtualFilter=WC
LastObject=CPreView

[DLG:IDD_PANEL_DIALOG]
Type=1
Class=CPanel
ControlCount=0

[CLS:CPanel]
Type=0
HeaderFile=Panel.h
ImplementationFile=Panel.cpp
BaseClass=CDialog
Filter=W
VirtualFilter=dWC

[DLG:IDD_CONTROLFORM_DIALOG]
Type=1
Class=?
ControlCount=31
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_PORT,combobox,1344340226
Control4=IDC_PORTSET,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_SETTINGS,edit,1350631552
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,static,1342308352
Control10=IDC_ACTIONS,combobox,1344339970
Control11=IDC_CMDSET,button,1342242816
Control12=IDC_STATIC,static,1342308352
Control13=IDC_BYTE1,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_BYTE2,edit,1350631552
Control16=IDC_STATIC,static,1342308352
Control17=IDC_BYTE3,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDC_BYTE4,edit,1350631552
Control20=IDC_STATIC,static,1342308352
Control21=IDC_BYTE5,edit,1350631552
Control22=IDC_STATIC,static,1342308352
Control23=IDC_BYTE6,edit,1350631552
Control24=IDC_STATIC,static,1342308352
Control25=IDC_BYTE7,edit,1350631552
Control26=IDC_STATIC,static,1342308352
Control27=IDC_BYTE8,edit,1350631552
Control28=IDC_STATIC,static,1342308352
Control29=IDC_BYTENUM,edit,1350631552
Control30=IDC_STATIC,static,1342308352
Control31=IDC_ACTIONNUM,edit,1350631552

[DLG:IDD_AUTOMATISM_DIALOG]
Type=1
Class=CAutodlg
ControlCount=11
Control1=IDC_TIMECHECK,button,1342242818
Control2=IDC_DATETIMEPICKER1,SysDateTimePick32,1342242857
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_DATETIMEPICKER2,SysDateTimePick32,1342242857
Control6=IDC_STATIC,button,1342177287
Control7=IDC_AMPLITUDE,button,1342177284
Control8=IDC_HORIZONTAL,button,1342177284
Control9=IDC_VERTICAL,button,1342177284
Control10=IDC_STATIC,static,1342177298
Control11=IDC_OK,button,1342242816

[CLS:CAutodlg]
Type=0
HeaderFile=Autodlg.h
ImplementationFile=Autodlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAutodlg

[DLG:IDD_PLAY_DIALOG]
Type=1
Class=CPlaydlg
ControlCount=3
Control1=IDC_PLAY,button,1342242816
Control2=IDC_MEDIAPLAYER1,{22D6F312-B0F6-11D0-94AB-0080C74C7E95},1342242816
Control3=IDC_PATH,static,1342308352

[CLS:CPlaydlg]
Type=0
HeaderFile=Playdlg.h
ImplementationFile=Playdlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_PATH
VirtualFilter=dWC

[DLG:IDD_LOGIN_DIALOG]
Type=1
Class=CLogin
ControlCount=5
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_EDIT2,edit,1350631584
Control3=IDC_OK,button,1073807360
Control4=IDC_CANCEL,button,1073807360
Control5=IDC_STATIC,static,1342177294

[CLS:CLogin]
Type=0
HeaderFile=Login.h
ImplementationFile=Login.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT1

[DLG:IDD_MANAGE_DIALOG]
Type=1
Class=CManagedlg
ControlCount=12
Control1=IDC_LIST1,SysListView32,1350631428
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_BUTTONADD,button,1342242816
Control7=IDC_BUTTONMOD,button,1342242816
Control8=IDC_BUTTONDEL,button,1342242816
Control9=IDC_BUTTON4,button,1342242816
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC1,static,1342177287
Control12=IDC_EDIT3,edit,1353777348

[CLS:CManagedlg]
Type=0
HeaderFile=Managedlg.h
ImplementationFile=Managedlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CManagedlg

