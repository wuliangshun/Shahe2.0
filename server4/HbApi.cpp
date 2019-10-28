#include "HbApi.h"

HbApi::HbApi()
{
}

HbApi::~HbApi()
{
}

rtAdmit* HbApi::admitGroupRule(const char* custNo, tint custType, const char* custName, int cardType,
	const char* cardNo, const char* ruleTime, const char* reqFlow, const char* groupCode,
	const char* healthStatus, const char* isHaveShop, const char* shopYear)
{
	rtAdmit* rta = new rtAdmit;

	rta->success = true;
	rta->errorCode = 1000000;
	strcpy(rta->data.result, "1");
	strcpy(rta->msg, "请求成功");

	return rta;
}

rtAdmit2* HbApi::RatingRule(const char* custNo, tint custType, const char* custName,
		const char* cardNo, const char* assetsHouse, const char* assetsCar,
		 const char* ruleTime, const char* reqFlow, const char* groupCode)
{
	rtAdmit2* rta = new rtAdmit2;

	rta->success = true;
	rta->errorCode = 1000000;
	strcpy(rta->data.result, "1");
	strcpy(rta->msg, "请求成功");
    strcpy(rta->rate,"A");
	return rta;
}
