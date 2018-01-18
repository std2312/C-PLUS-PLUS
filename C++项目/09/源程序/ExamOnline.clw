; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CExamOnlineDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ExamOnline.h"

ClassCount=17
Class1=CExamOnlineApp
Class2=CExamOnlineDlg
Class3=CAboutDlg

ResourceCount=17
Resource1=IDD_BACKMANAGE
Resource2=IDR_MAINFRAME
Resource3=IDD_TEXTMANAGE
Resource4=IDD_EXAMONLINE
Resource5=IDD_FINDPASSWD
Class4=CLOGIN
Class5=CFind
Class6=CBack
Resource6=IDD_REGISTER
Class7=CRegister
Resource7=IDD_TESTRESULT
Class8=CTextManage
Resource8=IDD_COPY
Class9=CAddSubject
Resource9=IDD_SQLMANAGE
Class10=CAddTest
Resource10=IDD_ADDTEST
Class11=CTestChange
Resource11=IDD_ADDSUBJECT
Class12=CExamInfo
Resource12=IDD_EXAMINFO
Class13=CTestResult
Resource13=IDD_TESTCHANGE
Class14=CResultSelect
Resource14=IDD_RESULTSELECT
Class15=CSQLManage
Resource15=IDD_LOGIN
Class16=CCopy
Resource16=IDD_ABOUTBOX
Class17=CReturn
Resource17=IDD_SQLRETURN

[CLS:CExamOnlineApp]
Type=0
HeaderFile=ExamOnline.h
ImplementationFile=ExamOnline.cpp
Filter=N

[CLS:CExamOnlineDlg]
Type=0
HeaderFile=ExamOnlineDlg.h
ImplementationFile=ExamOnlineDlg.cpp
Filter=D
LastObject=IDC_STATIC1
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ExamOnlineDlg.h
ImplementationFile=ExamOnlineDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CLOGIN]
Type=0
HeaderFile=LOGIN.h
ImplementationFile=LOGIN.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_COMBO_TYPE
VirtualFilter=dWC

[CLS:CFind]
Type=0
HeaderFile=Find.h
ImplementationFile=Find.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_ANSWER
VirtualFilter=dWC

[CLS:CBack]
Type=0
HeaderFile=Back.h
ImplementationFile=Back.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BackTab
VirtualFilter=dWC

[CLS:CRegister]
Type=0
HeaderFile=Register.h
ImplementationFile=Register.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_IDCARD
VirtualFilter=dWC

[DLG:IDD_REGISTER]
Type=1
Class=CRegister
ControlCount=29
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_USERNAME,edit,1350631552
Control4=IDC_CHECKNAME,button,1342242816
Control5=IDC_TISHI,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_PASSWD,edit,1350631584
Control8=IDC_STATIC,static,1342308352
Control9=IDC_PASSWDREPEAT,edit,1350631584
Control10=IDC_STATIC,static,1342308352
Control11=IDC_QUESTION,combobox,1344339971
Control12=IDC_STATIC,static,1342308352
Control13=IDC_ANSWER,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_REALNAME,edit,1350631552
Control19=IDC_AGE,edit,1350639744
Control20=IDC_SEXMALE,button,1342177289
Control21=IDC_SEXFEMALE,button,1342177289
Control22=IDC_PHONE,edit,1350639744
Control23=IDC_STATIC,static,1342308352
Control24=IDC_REG,button,1342242816
Control25=IDC_RESET,button,1342242816
Control26=IDC_STATIC,button,1342177287
Control27=IDC_STATIC,button,1342177287
Control28=IDC_STATIC,static,1342308352
Control29=IDC_IDCARD,edit,1350631552

[DLG:IDD_LOGIN]
Type=1
Class=CLOGIN
ControlCount=9
Control1=IDC_STATIC,static,1350697474
Control2=IDC_EDIT_USERNAME,edit,1350631552
Control3=IDC_EDIT_USERPASSWD,edit,1350631584
Control4=IDC_STATIC,static,1350697474
Control5=IDC_STATIC,static,1350697474
Control6=IDC_COMBO_TYPE,combobox,1344340227
Control7=IDC_BUTTON_OK,button,1342242816
Control8=IDC_BUTTON_CANCEL,button,1342242816
Control9=IDC_BUTTON_REG,button,1342242816

[DLG:IDD_BACKMANAGE]
Type=1
Class=CBack
ControlCount=1
Control1=IDC_BackTab,SysTabControl32,1342182400

[DLG:IDD_TEXTMANAGE]
Type=1
Class=CTextManage
ControlCount=7
Control1=IDC_TextTree,SysTreeView32,1350631431
Control2=IDC_TextList,SysListView32,1350631425
Control3=IDC_ADDTEST,button,1342242816
Control4=IDC_CHANGE,button,1342242816
Control5=IDC_DEL,button,1342242816
Control6=IDC_ADDSUBJECT,button,1342242816
Control7=IDC_DELSUBJECT,button,1342242816

[CLS:CTextManage]
Type=0
HeaderFile=TextManage.h
ImplementationFile=TextManage.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_TextTree
VirtualFilter=dWC

[CLS:CAddSubject]
Type=0
HeaderFile=AddSubject.h
ImplementationFile=AddSubject.cpp
BaseClass=CDialog
Filter=D
LastObject=CAddSubject
VirtualFilter=dWC

[DLG:IDD_ADDSUBJECT]
Type=1
Class=CAddSubject
ControlCount=4
Control1=IDC_SubjectName,edit,1350631552
Control2=IDC_STATIC,static,1342308352
Control3=IDC_OK_BUTTON,button,1342242816
Control4=IDC_CANCEL_BUTTON,button,1342242816

[DLG:IDD_ADDTEST]
Type=1
Class=CAddTest
ControlCount=21
Control1=IDC_QUESTION,edit,1350631552
Control2=IDC_EDITA,edit,1350631552
Control3=IDC_EDITB,edit,1350631552
Control4=IDC_EDITC,edit,1350631552
Control5=IDC_EDITD,edit,1350631552
Control6=IDC_ANSWER,edit,1350631552
Control7=IDC_BUTTON_OK,button,1342242816
Control8=IDC_BUTTON_CANCEL,button,1342242816
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_SUBJECTCOMBO,combobox,1344340227
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_TOTLE,edit,1350639744
Control19=IDC_STATIC,button,1342178055
Control20=IDC_STATIC,button,1342178055
Control21=IDC_STATIC,button,1342178055

[CLS:CAddTest]
Type=0
HeaderFile=AddTest.h
ImplementationFile=AddTest.cpp
BaseClass=CDialog
Filter=D
LastObject=CAddTest
VirtualFilter=dWC

[DLG:IDD_TESTCHANGE]
Type=1
Class=CTestChange
ControlCount=6
Control1=IDC_QUESTION,edit,1350631552
Control2=IDC_STATIC,static,1342308352
Control3=IDC_ANSWER,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_OK,button,1342242816
Control6=IDC_CANCEL,button,1342242816

[CLS:CTestChange]
Type=0
HeaderFile=TestChange.h
ImplementationFile=TestChange.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_ANSWER

[DLG:IDD_EXAMONLINE]
Type=1
Class=CExamOnlineDlg
ControlCount=14
Control1=IDC_TEST,static,1350697473
Control2=IDC_TESTID,static,1342308352
Control3=IDC_RADIO_A,button,1342185225
Control4=IDC_RADIO_B,button,1342185225
Control5=IDC_RADIO_C,button,1342185225
Control6=IDC_RADIO_D,button,1342185225
Control7=IDC_NEXT,button,1342242816
Control8=IDC_BACK,button,1342242816
Control9=IDC_RESET,button,1342242816
Control10=IDC_STATIC,button,1342178055
Control11=IDC_STATIC,button,1342178055
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC1,static,1342308352
Control14=IDC_STATIC,static,1342308352

[DLG:IDD_EXAMINFO]
Type=1
Class=CExamInfo
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_SUBJECTCOMBO,combobox,1344340227
Control4=IDC_BUTTON_OK,button,1342242816
Control5=IDC_BUTTON_CANCEL,button,1342242816

[CLS:CExamInfo]
Type=0
HeaderFile=ExamInfo.h
ImplementationFile=ExamInfo.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_SUBJECTCOMBO

[CLS:CTestResult]
Type=0
HeaderFile=TestResult.h
ImplementationFile=TestResult.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_RESULTLIST

[DLG:IDD_RESULTSELECT]
Type=1
Class=CResultSelect
ControlCount=6
Control1=IDC_RESULTLIST,SysListView32,1350631425
Control2=IDC_STATIC,static,1342308352
Control3=IDC_TYPECOMBO,combobox,1344340227
Control4=IDC_Mark,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_SELECT,button,1342242816

[CLS:CResultSelect]
Type=0
HeaderFile=ResultSelect.h
ImplementationFile=ResultSelect.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_RESULTLIST

[DLG:IDD_SQLMANAGE]
Type=1
Class=CSQLManage
ControlCount=3
Control1=IDC_SQLCOPY,button,1342242816
Control2=IDC_SQLRETURN,button,1342242816
Control3=IDC_SQLNEW,button,1342242816

[CLS:CSQLManage]
Type=0
HeaderFile=SQLManage.h
ImplementationFile=SQLManage.cpp
BaseClass=CDialog
Filter=D
LastObject=CSQLManage
VirtualFilter=dWC

[DLG:IDD_COPY]
Type=1
Class=CCopy
ControlCount=8
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350633600
Control4=IDC_BUTTON_checkml,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT2,edit,1350631552
Control7=IDC_BUTTON_OK,button,1342242816
Control8=IDC_BUTTON_CANCEL,button,1342242816

[CLS:CCopy]
Type=0
HeaderFile=Copy.h
ImplementationFile=Copy.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CCopy

[DLG:IDD_SQLRETURN]
Type=1
Class=CReturn
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350633600
Control4=IDC_BUTTON_liulan,button,1342242816
Control5=IDC_BUTTON_return,button,1342242816
Control6=IDC_BUTTON_CANCEL,button,1342242816

[CLS:CReturn]
Type=0
HeaderFile=Return.h
ImplementationFile=Return.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CReturn

[DLG:IDD_FINDPASSWD]
Type=1
Class=CFind
ControlCount=9
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC_QUESTION,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_ANSWER,edit,1350631552
Control5=IDC_STATIC_PASSWD,static,1342308352
Control6=IDC_BUTTON_SEND,button,1342242816
Control7=IDC_BUTTON_EXIT,button,1342242816
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC_username,static,1342308352

[DLG:IDD_TESTRESULT]
Type=1
Class=CTestResult
ControlCount=3
Control1=IDC_RESULTLIST,SysListView32,1350631425
Control2=IDC_STATIC,static,1342308352
Control3=IDC_CANCEL,button,1342242816

