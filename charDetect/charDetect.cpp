// charDetect.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "charDetect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
/**/
#include "src\uchardet.h"
typedef void* uchardet_t;
/**/

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CcharDetectApp

BEGIN_MESSAGE_MAP(CcharDetectApp, CWinApp)
END_MESSAGE_MAP()


// CcharDetectApp ����

CcharDetectApp::CcharDetectApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CcharDetectApp ����

CcharDetectApp theApp;


// CcharDetectApp ��ʼ��

BOOL CcharDetectApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
/* uchardet_new  */
extern "C" __declspec(dllexport) uchardet_t chardet_new(void) 
{  
	return uchardet_new();
}
/* uchardet_delete */
extern "C" __declspec(dllexport) void chardet_delete(uchardet_t ud) 
{  
    uchardet_delete(ud); 
}
/* uchardet_handle_data */
extern "C" __declspec(dllexport) int chardet_handle_data(uchardet_t ud, const char * data, size_t len) 
{  
	return uchardet_handle_data( ud, data,  len);
}
/* uchardet_data_end */
extern "C" __declspec(dllexport) void chardet_data_end(uchardet_t ud) 
{  
    uchardet_data_end(ud);
}
/* uchardet_reset */
extern "C" __declspec(dllexport) void chardet_reset(uchardet_t ud) 
{  
    uchardet_reset(ud);
}
extern "C" __declspec(dllexport) const char* chardet_get_charset(uchardet_t ud) 
{  
	return uchardet_get_charset(ud);
}