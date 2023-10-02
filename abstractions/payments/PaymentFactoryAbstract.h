#pragma once
#include "PaymentAbstract.h"
#include <iostream>
class PaymentFactoryAbstract 
{
public:
	virtual PaymentAbstract* getPaymentRate(std::string person) = 0;
};

