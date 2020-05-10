     
#pragma once

#include <gtest/gtest.h>
#include "cpr/cpr.h"
#include <string>
#include "cpr/cpr.h"
#define private public
#include "WeatherMock.h"

class WeatherTestCase : public ::testing::Test {
public:
	//заглушка  
	WeatherMock moscow_weather;
	cpr::Response right_responce, wrong_responce, new_right_responce;

    std::string parsed_json = "{\"cod\":\"200\",\"message\":0.0033,\"cnt\":40,\"list\":[{\"dt\":3333333333,\"main\":{\"temp\":270}}]}";
    std::string new_parsed_json = "{\"cod\":\"200\",\"message\":0.0033,\"cnt\":40,\"list\":[{\"dt\":3333333333,\"main\":{\"temp\":260.0}}]}";
	
    WeatherTestCase() {
    	wrong_responce = cpr::Response();
    	wrong_responce.status_code = 404;
	    
    	right_responce = cpr::Response();
    	right_responce.status_code = 200;
    	right_responce.text = parsed_json;

		new_right_responce = cpr::Response();
    	new_right_responce.status_code = 200;
    	new_right_responce.text = new_parsed_json;
    }
};


TEST_F(WeatherTestCase, FirstTestOnThrow) {
	using ::testing::_;
	//special return  	
	using ::testing::Return;
	
	//заглушка и метод  	
	EXPECT_CALL(moscow_weather, Get(_)).WillOnce(Return(wrong_responce));
  	
  	EXPECT_THROW(moscow_weather.GetDifferenceString("Murmansk", "Moscow"), 			std::invalid_argument);
}

TEST_F(WeatherTestCase, SecondTestOnGetDifStr) {
	using ::testing::_;
	using ::testing::Return;
	
	//два вызова  	
	EXPECT_CALL(moscow_weather, Get(_))
	.WillOnce(Return(right_responce))
	.WillOnce(Return(new_right_responce));
	
	//"Weather in Murmansk is warmer than in Moscow by 10 degrees"
	EXPECT_NO_THROW(moscow_weather.GetDifferenceString("Moscow", "Murmansk")); 
	
	EXPECT_CALL(moscow_weather, Get(_))
	.WillOnce(Return(new_right_responce))
	.WillOnce(Return(right_responce));
	
	EXPECT_NO_THROW(moscow_weather.GetDifferenceString("Murmansk", "Moscow"));
}

TEST_F(WeatherTestCase, TestOnApiKey) {
  moscow_weather.SetApiKey("test");
  EXPECT_EQ(moscow_weather.api_key_, "test");
}
