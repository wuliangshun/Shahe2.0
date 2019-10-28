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
	*@brief 准入规则组合包执行接口
	*@param custNo:        客户编号
	        custType:      客户类型  0:个人
                                     1:微小企业
                                     2:中小型企业
								     3:大型企业
								     4:超大型企业
			custName:      客户名称
			cardType:      证件类型  1:身份证号码
			                         2:营业执照编号
								     3:组织编号
								     4:社会信用代码
								     5:税务登记号码
								     6:三证合一号码
			cardNo:        证件号码
			ruleTime:      请求规则发起时间  YYYY-MM-DD hh:mm:ss
			reqFlow:       请求流水号
			groupCode:     组合包标志（唯一标记）GROUP_CODE_11 房抵贷准入
                                            GROUP_CODE_12 留置类准入
											GROUP_CODE_13 信用类准入
			healthStatus:  健康情况  1:健康
			                         2:不健康
			isHaveShop:    是否有经营店铺
			shopYear:      经营店铺年限(一年及以上通过)
	*@ret:  rtAdmit        结构体
	        {
			    success:   是否成功
				errorCode: 错误代码
				msg:       消息
				data:      Obj(嵌入结构体)
				{
				ruleName:  规则名称
				code:      通过标识 1:通过
				                    2:不通过
				result:    通过结果 1:准入通过
                                    2:准入拒绝
				}
			}
	**********************************/

	/***********************************
	*@brief 评级规则组合包执行接口
	*@param custNo:        客户编号
	        custType:      客户类型  0:个人
                                     1:微小企业
                                     2:中小型企业
								     3:大型企业
								     4:超大型企业
			custName:      客户名称
			cardNo:        身份证号码
			assetsHouse:   是否有房子资产
			assetsCar:     是否有车资产
			ruleTime:      请求规则发起时间  YYYY-MM-DD hh:mm:ss
			reqFlow:       请求流水号
			groupCode:     组合包标志（唯一标记）GROUP_CODE_11 房抵贷准入
                                            GROUP_CODE_12 留置类准入
											GROUP_CODE_13 信用类准入
	*@ret:  rtAdmit2        结构体
	        {
			    success:   是否成功
				errorCode: 错误代码
				msg:       消息
				data:      Obj(嵌入结构体)
				{
				ruleName:  规则名称
				code:      通过标识 1:通过
				                    2:不通过
				result:    通过结果 1:准入通过
                                    2:准入拒绝
				}
				rate:      评级结果
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



