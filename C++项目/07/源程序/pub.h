///////////////////////////////////////////////////////////////////////////////////////////
#ifndef __PUB_H
#define __PUB_H

//ͼ��������ṹ
typedef struct _tag_BookMoveMain
{
	CString strAdjustNo;  //��������
	CString strCKName;    //�ֿ�
	CString strDesk;      //��̨
	CString strOperator;   //����Ա
	DATE    datetime;     //ʱ��
}BOOK_MOVE_MAIN, *LPBOOK_MOVE_MAIN;

//ͼ�������ϸ
typedef struct _tag_BookMove
{
	CString strAdjustNo;  //��������
	CString strDXCode;    //������
	double  dCount;       //����
}BOOK_MOVE, *LPBOOK_MOVE;

//ͼ��ֿ�
typedef struct _tag_BookStorage
{
	CString strDXCode; //������
	CString strCKName; //�ֿ�
	double  dCount;    //����
}BOOK_STOREAGE, *LPBOOK_STOREAGE;

//ͼ������
typedef struct _tag_BookKinds
{
	CString strKinds;  //ͼ������
}BOOK_KINDS, *LPBOOK_KINDS;

//��Ʒ�������ṹ
typedef struct _tag_SellMain
{
	CString strSellNo;   //���۵���
	CString strCustomer;   //�˿�
	CString strOperator; //����Ա
	double  dZHE;        //�ۿ�
	double  dTotalMoney; //�ܼ�
	double  dSrcMoney;   //Ӧ�ս��
	double  dDesMoney;   //ʵ�ս��
	DATE    datetime;    //ʱ��
	CString strCounter;     //��̨
}SELL_MAIN, *LPSELL_MAIN;

//��Ӧ����Ϣ�ṹ
typedef struct _tag_ProviderInfo
{
	CString strProName;    //��Ӧ������
	CString strCEO;        //����
	CString strManager;    //������
	CString strPhone;      //��ϵ�绰
	CString strAddress;    //��ϸ��ַ
	CString strNetAddress; //��ַ
	CString strEmail;      //����
}PROVIDER_INFO, *LPPROVIDER_INFO;

//�ֿ���Ϣ�ṹ
typedef struct _tag_StorageInfo
{
	CString strCK; //�ֿ�
}STOREAGE_INFO, *LPSTOREAGE_INFO;

//��̨��Ϣ�ṹ
typedef struct _tag_Counter_Info
{
	CString strCounterName;  //��̨����
}COUNTER_INFO, *LPCOUNTER_INFO;

//ͼ����Ϣ��ṹ
typedef struct _tag_BookInfo  
{
	CString  strBookName;  //�鼮����
	CString  strZHJCode;   //������
	CString  strDXCode;    //������
	CString  strAuthor;	   //����
	CString  strPublic;    //������
	double   dPrice;       //�۸�
	CString  strMark;      //��ע
	CString  strKinds;      //����
}BOOK_INFO, *LPBOOK_INFO;

//��Ʒ������ϸ�ṹ
typedef struct _tag_SellSub
{
	CString strSellNo;  //���۵���
	CString strDXCode;  //������
	double  dPrice;     //����
	double  dCount;     //����
	double  dZHE;       //�ۿ�
	double  dMoney;     //���
}SELL_SUB, *LPSELL_SUB; 

//����Ա��Ϣ�ṹ
typedef struct _tag_Operator
{
	CString strOperName;  //����Ա����
	CString strOperPass;  //����Ա����
	int     iOperLevel;   //����Ա����
}OPERATOR, *LPOPERATOR;

//ͼ�����ṹ
typedef struct _tag_InStorageMain
{
	CString strInStorageNo; //��ⵥ��
	CString strProvider;    //��Ӧ��
	CString strOperator;    //����Ա
	double  dZHE;           //�ۿ�
	double  dTotallMoney;   //�ܼ�
	double  dSrcMoney;      //Ӧ�����
	double  dDesMoney;      //ʵ�����
	DATE    datetime;       //ʱ��
}IN_STORAGE_MAIN, *LPIN_STORAGE_MAIN;

//��̨ͼ��ṹ
typedef struct _tag_CounterBook
{
	CString strTXCode;  //������
	CString strCounter; //��̨����
	double  dCount;     //����
}COUNTER_BOOK, *LPCOUNTER_BOOK;

//�����ϸ�ṹ
typedef struct _tag_InStorageSub
{
	CString strInStorageNo; //��ⵥ��
	CString strTXCode;      //������
	double  dPrice;         //����
	double  dCount;         //����
	double  dZHE;           //�ۿ�
	double  dMoney;         //���
	CString strStorageName; //�ֿ�����
}IN_STORAGE_SUB, *LPIN_STORAGE_SUB;

//�����˻���ϸ�ṹ
typedef struct _tag_CancelSell_Sub
{
	CString strCancelSellNo;
	CString strTXCode;
	double  dPrice;
	double  dCount;
	double  dZHE;
	double  dMoney;
}CANCEL_SELL_SUB, *LPCANCEL_SELL_SUB;

//������
typedef struct _tag_TXCode
{
	CString strTXCode; //������
	double  dMoney;    //�ۼ�
}TX_CODE, *LPTX_CODE;

//����˻���ϸ�ṹ
typedef struct _tag_CancelInStorageSub
{
	CString strCancelNo;    //�˻�����
	CString strTXCode;      //������
	double  dPrice;         //����
	double  dCount;         //����
	double  dZHE;           //�ۿ�
	double  dMoney;         //���
	CString strStorageName; //�ֿ�����
}CANCELI_IN_STORAGE_SUB, *LPCANCELI_IN_STORAGE_SUB;

//����˻����ṹ
typedef struct _tag_CancelInStorageMain
{
	CString strCancelNo;  //�˻�����
	CString strProvider;  //��Ӧ��
	CString strOperator;  //����Ա
	double  dZHE;         //�ۿ�
	double  dSrcMoney;    //Ӧ�����
	double  dDesMoney;    //ʵ�����
	DATE    datetime;     //ʱ��
}CANCELI_IN_STORAGE_MAIN, *LPCANCELI_IN_STORAGE_MAIN;

//�����˻����ṹ
typedef struct _tag_CancelSellMain
{
	CString strCancelSellNo;  //�����˻�����
	CString strCustomer;      //�˿�
	CString strOperator;      //����Ա
	double  dZHE;             //�ۿ�
	double  dTotallMoney;     //�ܼ�
	double  dSrcMoney;        //Ӧ�����
	double  dDesMoney;        //ʵ�����
	DATE    datetime;         //ʱ��
	CString strCounter;	      //��̨
}CANCEL_SELL_MAIN, *LPCANCEL_SELL_MAIN;

#endif