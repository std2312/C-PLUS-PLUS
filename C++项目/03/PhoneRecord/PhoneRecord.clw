; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRecordDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PhoneRecord.h"

ClassCount=13
Class1=CPhoneRecordApp
Class2=CPhoneRecordDlg
Class3=CAboutDlg

ResourceCount=13
Resource1=IDD_PHONEIN_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDD_PHONERECORD_DIALOG
Resource5=IDD_PHONEOUT_DIALOG
Resource6=IDD_EMPLOYEES_DIALOG
Resource7=IDD_CLIENT_DIALOG
Class4=CClientDlg
Class5=CEmployeeDlg
Class6=CManufactureDlg
Resource8=IDD_PHONEBOOK_DIALOG
Resource9=IDD_MANUFACTURE_DIALOG
Resource10=IDD_RECORD_DIALOG
Resource11=IDD_LOGIN_DIALOG
Resource12=IDR_MENU1
Class7=CDialupDlg
Class8=CInceptDlg
Class9=CPhoneinDlg
Class10=CPhoneoutDlg
Class11=CRecordDlg
Class12=CPhoneBook
Class13=CLogindlg
Resource13=IDR_MENU2

[CLS:CPhoneRecordApp]
Type=0
HeaderFile=PhoneRecord.h
ImplementationFile=PhoneRecord.cpp
Filter=N

[CLS:CPhoneRecordDlg]
Type=0
HeaderFile=PhoneRecordDlg.h
ImplementationFile=PhoneRecordDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST1

[CLS:CAboutDlg]
Type=0
HeaderFile=PhoneRecordDlg.h
ImplementationFile=PhoneRecordDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PHONERECORD_DIALOG]
Type=1
Class=CPhoneRecordDlg
ControlCount=15
Control1=IDC_LIST1,SysListView32,1350631813
Control2=IDC_PHONEIN,button,1342242827
Control3=IDC_PHONEOUT,button,1342242827
Control4=IDC_RECORD,button,1342242827
Control5=IDC_CLIENT,button,1342242827
Control6=IDC_EMPLOYEE,button,1342242827
Control7=IDC_MANUFACTURE,button,1342242827
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,static,1342308352
Control10=IDC_COMBO1,combobox,1344340226
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT1,edit,1350631552
Control13=IDC_DIALUP,button,1342242827
Control14=IDC_HANGUP,button,1342242827
Control15=IDC_PHONEBOOK,button,1342242827

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_MENUPHONEOUT
Command2=ID_MENUPHONEIN
Command3=ID_MENURECORD
Command4=ID_MENUCLIENT
Command5=ID_MENUEMPLOYEES
Command6=ID_MENUMANUFACTURE
Command7=ID_MENUABOUT
Command8=ID_MENUEXIT
CommandCount=8

[MNU:IDR_MENU2]
Type=1
Class=?
Command1=ID_MENUSHOW
Command2=ID_MENUHIDE
Command3=ID_MENUCLOSE
CommandCount=3

[CLS:CClientDlg]
Type=0
HeaderFile=ClientDlg.h
ImplementationFile=ClientDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CClientDlg
VirtualFilter=dWC

[CLS:CEmployeeDlg]
Type=0
HeaderFile=EmployeeDlg.h
ImplementationFile=EmployeeDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CEmployeeDlg
VirtualFilter=dWC

[CLS:CManufactureDlg]
Type=0
HeaderFile=ManufactureDlg.h
ImplementationFile=ManufactureDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST1
VirtualFilter=dWC

[DLG:IDD_MANUFACTURE_DIALOG]
Type=1
Class=CManufactureDlg
ControlCount=10
Control1=IDC_LIST1,SysListView32,1350631428
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT2,edit,1352732740
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BUTADD,button,1342242827
Control7=IDC_BUTSAVE,button,1342242827
Control8=IDC_BUTMOD,button,1342242827
Control9=IDC_BUTDEL,button,1342242827
Control10=IDC_STATIC,button,1342177287

[DLG:IDD_CLIENT_DIALOG]
Type=1
Class=CClientDlg
ControlCount=19
Control1=IDC_LIST1,SysListView32,1350633477
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT3,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT4,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT6,edit,1350631552
Control13=IDC_EDIT5,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDIT7,edit,1352732740
Control16=IDC_BUTADD,button,1342242827
Control17=IDC_BUTSAVE,button,1342242827
Control18=IDC_BUTMOD,button,1342242827
Control19=IDC_BUTDEL,button,1342242827

[DLG:IDD_EMPLOYEES_DIALOG]
Type=1
Class=CEmployeeDlg
ControlCount=23
Control1=IDC_LIST1,SysListView32,1350633476
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT3,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT4,edit,1350631584
Control10=IDC_STATIC,static,1342308352
Control11=IDC_COMBO1,combobox,1344339970
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EDIT5,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDIT6,edit,1350631552
Control16=IDC_STATIC,static,1342308352
Control17=IDC_EDIT7,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDC_EDIT8,edit,1352732740
Control20=IDC_BUTADD,button,1342242827
Control21=IDC_BUTSAVE,button,1342242827
Control22=IDC_BUTMOD,button,1342242827
Control23=IDC_BUTDEL,button,1342242827

[DLG:IDD_PHONEOUT_DIALOG]
Type=1
Class=CPhoneoutDlg
ControlCount=9
Control1=IDC_LIST1,SysListView32,1350631557
Control2=IDC_STATIC,button,1342177287
Control3=IDC_COMBO1,combobox,1344340227
Control4=IDC_STATIC,static,1342308352
Control5=IDC_COMBO2,combobox,1344340226
Control6=IDC_STATIC,static,1342308352
Control7=IDC_BUTDIALUP,button,1342242827
Control8=IDC_BUTDEL,button,1342242827
Control9=IDC_BUTQUERY,button,1342242827

[DLG:IDD_PHONEIN_DIALOG]
Type=1
Class=CPhoneinDlg
ControlCount=9
Control1=IDC_LIST1,SysListView32,1350631557
Control2=IDC_STATIC,button,1342177287
Control3=IDC_COMBO1,combobox,1344340227
Control4=IDC_STATIC,static,1342308352
Control5=IDC_COMBO2,combobox,1344340226
Control6=IDC_STATIC,static,1342308352
Control7=IDC_BUTDIALUP,button,1342242827
Control8=IDC_BUTDEL,button,1342242827
Control9=IDC_BUTQUERY,button,1342242827

[DLG:IDD_RECORD_DIALOG]
Type=1
Class=CRecordDlg
ControlCount=9
Control1=IDC_LIST1,SysListView32,1350631685
Control2=IDC_STATIC,button,1342177287
Control3=IDC_EDIT1,edit,1350633600
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_BUTMODPATH,button,1342242827
Control8=IDC_BUTDEL,button,1342242827
Control9=IDC_BUTPLAY,button,1342242827

[CLS:CDialupDlg]
Type=0
HeaderFile=DialupDlg.h
ImplementationFile=DialupDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CDialupDlg

[CLS:CInceptDlg]
Type=0
HeaderFile=InceptDlg.h
ImplementationFile=InceptDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CInceptDlg

[CLS:CPhoneinDlg]
Type=0
HeaderFile=PhoneinDlg.h
ImplementationFile=PhoneinDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTQUERY
VirtualFilter=dWC

[CLS:CPhoneoutDlg]
Type=0
HeaderFile=PhoneoutDlg.h
ImplementationFile=PhoneoutDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CPhoneoutDlg
VirtualFilter=dWC

[CLS:CRecordDlg]
Type=0
HeaderFile=RecordDlg.h
ImplementationFile=RecordDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CRecordDlg
VirtualFilter=dWC

[DLG:IDD_PHONEBOOK_DIALOG]
Type=1
Class=CPhoneBook
ControlCount=1
Control1=IDC_LIST1,SysListView32,1350631425

[CLS:CPhoneBook]
Type=0
HeaderFile=PhoneBook.h
ImplementationFile=PhoneBook.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST1
VirtualFilter=dWC

[DLG:IDD_LOGIN_DIALOG]
Type=1
Class=CLogindlg
ControlCount=6
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_EDIT2,edit,1350631584
Control3=IDOK,button,1342242827
Control4=IDCANCEL,button,1342242827
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[CLS:CLogindlg]
Type=0
HeaderFile=Logindlg.h
ImplementationFile=Logindlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_LOGIN

