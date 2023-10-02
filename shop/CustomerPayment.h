#pragma once
#include "PaymentAbstract.h"

class CustomerPayment:public PaymentAbstract
{
public:
	CustomerPayment() = default;
	float getRate() override
	{
		return 1;
	}
};

