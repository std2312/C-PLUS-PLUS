; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CUserdlg
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NoteManage.h"

ClassCount=16
Class1=CNoteManageApp
Class2=CNoteManageDlg
Class3=CAboutDlg

ResourceCount=14
Resource1=IDD_RECVNOTE_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_PHONEBOOK_DIALOG
Resource4=IDD_LOGIN_DIALOG
Resource5=IDD_BOOK_DIALOG
Resource6=IDD_NOTESET_DIALOG
Resource7=IDD_NOTEMANAGE_DIALOG
Resource8=IDD_NOTE_DIALOG
Resource9=IDD_SENDNOTE_DIALOG
Resource10=IDD_ABOUTBOX
Resource11=IDD_USER_DIALOG
Class4=CPhoneBookdlg
Class5=COftenNotedlg
Class6=CRecvNotedlg
Class7=CRestoredlg
Class8=CSendNotedlg
Class9=CUserdlg
Class10=CLogin
Class11=CBookdlg
Class12=CNotedlg
Class13=CPhoneEdit
Resource12=IDD_OFTENNOTE_DIALOG
Class14=CNoteSet
Resource13=IDD_RESTORE_DIALOG
Class15=CNewNotedlg
Class16=CBmpButton
Resource14=IDD_NEWNOTE_DIALOG

[CLS:CNoteManageApp]
Type=0
HeaderFile=NoteManage.h
ImplementationFile=NoteManage.cpp
Filter=N

[CLS:CNoteManageDlg]
Type=0
HeaderFile=NoteManageDlg.h
ImplementationFile=NoteManageDlg.cpp
Filter=D
LastObject=CNoteManageDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=NoteManageDlg.h
ImplementationFile=NoteManageDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_NOTEMANAGE_DIALOG]
Type=1
Class=CNoteManageDlg
ControlCount=1
Control1=IDC_STATIC,static,1342177294

[DLG:IDD_SENDNOTE_DIALOG]
Type=1
Class=CSendNotedlg
ControlCount=9
Control1=IDC_LIST1,SysListView32,1350631813
Control2=IDC_EDIT1,edit,1352732740
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_BUTNOTE,button,1342242944
Control6=IDC_BUTBOOK,button,1342242944
Control7=IDC_BUTDEL,button,1342242944
Control8=IDC_BUTSEND,button,1342242944
Control9=IDC_BUTCLEAR,button,1342242944

[DLG:IDD_PHONEBOOK_DIALOG]
Type=1
Class=CPhoneBookdlg
ControlCount=15
Control1=IDC_LIST1,SysListView32,1350631813
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,button,1342177287
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_COMBO1,combobox,1344340226
Control8=IDC_COMBO2,combobox,1344340226
Control9=IDC_STATIC,static,1342308352
Control10=IDC_COMBO3,combobox,1344340226
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT2,edit,1350631552
Control13=IDC_BUTADD,button,1342242944
Control14=IDC_BUTMOD,button,1342242944
Control15=IDC_BUTDEL,button,1342242944

[DLG:IDD_RECVNOTE_DIALOG]
Type=1
Class=CRecvNotedlg
ControlCount=2
Control1=IDC_LIST1,SysListView32,1350631813
Control2=IDC_STATIC,static,1342308352

[DLG:IDD_RESTORE_DIALOG]
Type=1
Class=CRestoredlg
ControlCount=11
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350633600
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT2,edit,1350633600
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT3,edit,1352730692
Control8=IDC_EDIT4,edit,1352732740
Control9=IDC_STATIC,button,1342177287
Control10=IDC_BUTSEND,button,1342242944
Control11=IDC_BUTDEL,button,1342242944

[DLG:IDD_OFTENNOTE_DIALOG]
Type=1
Class=COftenNotedlg
ControlCount=7
Control1=IDC_EDIT1,edit,1352732740
Control2=IDC_LIST1,SysListView32,1350631813
Control3=IDC_BUTMOD,button,1342242944
Control4=IDC_BUTDEL,button,1342242944
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,button,1342177287
Control7=IDC_BUTADD,button,1342242944

[DLG:IDD_NOTE_DIALOG]
Type=1
Class=CNotedlg
ControlCount=1
Control1=IDC_LIST1,SysListView32,1350631813

[DLG:IDD_BOOK_DIALOG]
Type=1
Class=CBookdlg
ControlCount=9
Control1=IDC_LIST1,SysListView32,1350631813
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_BUTTONALL,button,1342242944
Control6=IDC_COMBO1,combobox,1344340226
Control7=IDC_BUTTONDEP,button,1342242944
Control8=IDC_COMBO2,combobox,1344340226
Control9=IDC_BUTTONDUTY,button,1342242944

[DLG:IDD_LOGIN_DIALOG]
Type=1
Class=CLogin
ControlCount=5
Control1=IDOK,button,1073807361
Control2=IDCANCEL,button,1073807360
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631584
Control5=IDC_STATIC,static,1342177294

[DLG:IDD_USER_DIALOG]
Type=1
Class=CUserdlg
ControlCount=9
Control1=IDC_LIST1,SysListView32,1350631428
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_BUTTONADD,button,1342242944
Control7=IDC_BUTTONMOD,button,1342242944
Control8=IDC_BUTTONDEL,button,1342242944
Control9=IDC_CANCEL,button,1342242944

[CLS:CPhoneBookdlg]
Type=0
HeaderFile=PhoneBookdlg.h
ImplementationFile=PhoneBookdlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CPhoneBookdlg
VirtualFilter=dWC

[CLS:COftenNotedlg]
Type=0
HeaderFile=OftenNotedlg.h
ImplementationFile=OftenNotedlg.cpp
BaseClass=CDialog
Filter=D
LastObject=COftenNotedlg
VirtualFilter=dWC

[CLS:CRecvNotedlg]
Type=0
HeaderFile=RecvNotedlg.h
ImplementationFile=RecvNotedlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CRecvNotedlg
VirtualFilter=dWC

[CLS:CRestoredlg]
Type=0
HeaderFile=Restoredlg.h
ImplementationFile=Restoredlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CRestoredlg
VirtualFilter=dWC

[CLS:CSendNotedlg]
Type=0
HeaderFile=SendNotedlg.h
ImplementationFile=SendNotedlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSendNotedlg
VirtualFilter=dWC

[CLS:CUserdlg]
Type=0
HeaderFile=Userdlg.h
ImplementationFile=Userdlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST1
VirtualFilter=dWC

[CLS:CLogin]
Type=0
HeaderFile=Login.h
ImplementationFile=Login.cpp
BaseClass=CDialog
Filter=D
LastObject=CLogin
VirtualFilter=dWC

[CLS:CBookdlg]
Type=0
HeaderFile=Bookdlg.h
ImplementationFile=Bookdlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTONALL
VirtualFilter=dWC

[CLS:CNotedlg]
Type=0
HeaderFile=Notedlg.h
ImplementationFile=Notedlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST1
VirtualFilter=dWC

[CLS:CPhoneEdit]
Type=0
HeaderFile=PhoneEdit.h
ImplementationFile=PhoneEdit.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC

[DLG:IDD_NOTESET_DIALOG]
Type=1
Class=CNoteSet
ControlCount=11
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350633600
Control4=IDC_STATIC,static,1342308352
Control5=IDC_BUTGET,button,1342242944
Control6=IDC_EDIT2,edit,1350633600
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT3,edit,1350631552
Control9=IDC_STATIC,button,1342177287
Control10=IDC_BUTSAVE,button,1342242944
Control11=IDC_EDIT4,edit,1350633600

[CLS:CNoteSet]
Type=0
HeaderFile=NoteSet.h
ImplementationFile=NoteSet.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CNoteSet

[DLG:IDD_NEWNOTE_DIALOG]
Type=1
Class=CNewNotedlg
ControlCount=1
Control1=IDC_STATIC,static,1342177294

[CLS:CNewNotedlg]
Type=0
HeaderFile=NewNotedlg.h
ImplementationFile=NewNotedlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CNewNotedlg

[CLS:CBmpButton]
Type=0
HeaderFile=BmpButton.h
ImplementationFile=BmpButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC

