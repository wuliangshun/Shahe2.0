#pragma once
#pragma warning(disable:4996)

#include <string.h>
#include <string>
#define tint short


struct Data
{
	char ruleName[20];
	tint code;
	char result[20];
};

typedef struct admitResult
{
	bool success;
	int errorCode;
	char msg[20];
	Data data;
} rtAdmit;

typedef struct admitResult2
{
	bool success;
	int errorCode;
	char msg[20];
	Data data;
	char rate[20];
} rtAdmit2;

class HbApi
{
public:
	HbApi();
	~HbApi();

	/***********************************
	*@brief ׼�������ϰ�ִ�нӿ�
	*@param custNo:        �ͻ����
	        custType:      �ͻ�����  0:����
                                     1:΢С��ҵ
                                     2:��С����ҵ
								     3:������ҵ
								     4:��������ҵ
			custName:      �ͻ�����
			cardType:      ֤������  1:���֤����
			                         2:Ӫҵִ�ձ��
								     3:��֯���
								     4:������ô���
								     5:˰��ǼǺ���
								     6:��֤��һ����
			cardNo:        ֤������
			ruleTime:      ���������ʱ��  YYYY-MM-DD hh:mm:ss
			reqFlow:       ������ˮ��
			groupCode:     ��ϰ���־��Ψһ��ǣ�GROUP_CODE_11 ���ִ�׼��
                                            GROUP_CODE_12 ������׼��
											GROUP_CODE_13 ������׼��
			healthStatus:  �������  1:����
			                         2:������
			isHaveShop:    �Ƿ��о�Ӫ����
			shopYear:      ��Ӫ��������(һ�꼰����ͨ��)
	*@ret:  rtAdmit        �ṹ��
	        {
			    success:   �Ƿ�ɹ�
				errorCode: �������
				msg:       ��Ϣ
				data:      Obj(Ƕ��ṹ��)
				{
				ruleName:  ��������
				code:      ͨ����ʶ 1:ͨ��
				                    2:��ͨ��
				result:    ͨ����� 1:׼��ͨ��
                                    2:׼��ܾ�
				}
			}
	**********************************/

	/***********************************
	*@brief ����������ϰ�ִ�нӿ�
	*@param custNo:        �ͻ����
	        custType:      �ͻ�����  0:����
                                     1:΢С��ҵ
                                     2:��С����ҵ
								     3:������ҵ
								     4:��������ҵ
			custName:      �ͻ�����
			cardNo:        ���֤����
			assetsHouse:   �Ƿ��з����ʲ�
			assetsCar:     �Ƿ��г��ʲ�
			ruleTime:      ���������ʱ��  YYYY-MM-DD hh:mm:ss
			reqFlow:       ������ˮ��
			groupCode:     ��ϰ���־��Ψһ��ǣ�GROUP_CODE_11 ���ִ�׼��
                                            GROUP_CODE_12 ������׼��
											GROUP_CODE_13 ������׼��
	*@ret:  rtAdmit2        �ṹ��
	        {
			    success:   �Ƿ�ɹ�
				errorCode: �������
				msg:       ��Ϣ
				data:      Obj(Ƕ��ṹ��)
				{
				ruleName:  ��������
				code:      ͨ����ʶ 1:ͨ��
				                    2:��ͨ��
				result:    ͨ����� 1:׼��ͨ��
                                    2:׼��ܾ�
				}
				rate:      �������
			}
	**********************************/
	rtAdmit* admitGroupRule(const char* custNo, tint custType, const char* custName, int cardType,
		const char* cardNo, const char* ruleTime, const char* reqFlow, const char* groupCode,
		const char* healthStatus, const char* isHaveShop, const char* shopYear);

	rtAdmit2* RatingRule(const char* custNo, tint custType, const char* custName,
		const char* cardNo, const char* assetsHouse, const char* assetsCar,
		 const char* ruleTime, const char* reqFlow, const char* groupCode);


private:

};



