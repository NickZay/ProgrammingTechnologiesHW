
#pragma once

#include <gtest/gtest.h>
#include "cpr/cpr.h"
#include <string>
#define private public
#include "WeatherMock.h"

class WeatherTestCase : public ::testing::Test {
public:
	WeatherMock moscow_weather;
	cpr::Response right_responce, wrong_responce, new_right_responce;
	
    	std::string parsed_json = "{\"cod\":\"200\",\"message\":0.0033,\"cnt\":40,\"list\":[{\"dt\":3333333333,\"main\":{\"temp\":270}}]}";
    	std::string new_parsed_json = "{\"cod\":\"200\",\"message\":0.0033,\"cnt\":40,\"list\":[{\"dt\":3333333333,\"main\":{\"temp\":260.0}}]}";
	
	WeatherTestCase();
};

