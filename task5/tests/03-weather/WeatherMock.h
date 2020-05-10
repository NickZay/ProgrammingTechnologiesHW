//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#pragma once

#include <gmock/gmock.h>
#include "cpr/cpr.h"
#include "Weather.h"

class WeatherMock : public Weather {
public:
  	//заглушка
	MOCK_METHOD(cpr::Response, Get, (const std::string& city));
};



