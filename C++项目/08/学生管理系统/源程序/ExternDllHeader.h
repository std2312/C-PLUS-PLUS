
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//                            ����RXDLL�к���

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
/*
����ԭ�ͣ�CString CharToLetterCode(CString string)
��Ҫ����: ����ָ���ַ�����ƴ�����롣 
������:                                          
	String:Ҫ���ƴ��������ַ�����*/ 

typedef CString(_CharToLetterCode)(CString);
extern _CharToLetterCode* CharToLetterCode;
/**************************************************************
CString Padl(CString String, int digit, CString Fill,int Style)
��Ҫ����: ���ַ���ǰ���ָ���������ַ��� 
������:                                          
	String��Դ�ַ��� ��       
	digit���ַ����ĳ��ȡ�                           
	fill: �����ַ�����
	Style: �����ַ�����䷽ʽ ���Ϊ1ʱ�����ַ�ǰ���  ���Ϊ0 ���ַ��������*/
typedef CString(_Padl)(CString,int,CString,int);
extern _Padl* Padl;
/**************************************************************
CTime CStringTOCTime(CString cDate)
��Ҫ����: ��ʱ���ַ���ת����CTime���͡� 
������:                                          
	cDate��ָ���ַ����ַ��� �� */
typedef CTime(_CStringTOCTime)(CString);
extern _CStringTOCTime* CStringTOCTime; 
/**************************************************************
CString CTimeToCString(CTime date)    
��Ҫ����: ��CTime��������ת����ʱ���ַ����� 
������:                                          
	date:CTime�������� ��*/
typedef CString(_CTimeToCString)(CTime);
extern _CTimeToCString* CTimeToCString; 
/**************************************************************
CString MoneyToChineseCode(CString sMoney)
��Ҫ����: ������������Сд���ת���ɺ��ִ�д��� 
������:                                          
	sMoney:Сд����ַ�����*/
typedef CString(_MoneyToChineseCode)(CString);
extern _MoneyToChineseCode* MoneyToChineseCode; 
