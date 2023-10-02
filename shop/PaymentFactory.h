#pragma once
#include "PaymentFactoryAbstract.h"
#include "CustomerPayment.h"
#include "AdminPayment.h"

class PaymentFactory:public PaymentFactoryAbstract
{
public:
	PaymentAbstract* getPaymentRate(std::string person) override
	{
		if (person == "Customer")
			return new CustomerPayment();
		else if (person == "Admin")
			return new AdminPayment();
	}
};

