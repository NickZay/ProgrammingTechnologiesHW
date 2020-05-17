//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <gtest/gtest.h>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;


class TreeTestCase : public ::testing::Test {
public:
  	path path1, path2;
  	std::ofstream new_stream, new_new_stream;
	
	TreeTestCase();
	~TreeTestCase();	
};


