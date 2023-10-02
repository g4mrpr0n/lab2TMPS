#pragma once
#include "PaymentAbstract.h"

class AdminPayment :public PaymentAbstract
{
public:
	AdminPayment() = default;
	float getRate() override
	{
		return 0.5;
	}
};

