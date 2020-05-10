//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>
#include <boost/filesystem.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "Tree.h"

using namespace boost::filesystem;

class TreeTestCase : public ::testing::Test {
public:
  
  path path1, path2;
  std::ofstream new_stream, new_new_stream;
  
  TreeTestCase() {
    path1 = current_path();
	path2 = current_path();
    path1 += "/dir1";
	path2 += "/dir1/sub_dir";    
	
	create_directory(path1);
    new_stream = std::ofstream("dir1/file1.cpp");
	
	create_directory(path2);
	new_stream = std::ofstream("dir1/sub_dir/file2.cpp");
  }
  
  ~TreeTestCase() { 
	remove_all(path1);
	remove_all(path2);	
  }
};

TEST_F(TreeTestCase, FirstTestOnThrow) {
  EXPECT_THROW(GetTree("not/existed/file", true), std::invalid_argument);
}

TEST_F(TreeTestCase, SecondTestOnThrow) {
  EXPECT_THROW(GetTree(path1.string() + "/file1.cpp", true), std::invalid_argument);
}

TEST_F(TreeTestCase, ThirdTestOnSubDir) {
  EXPECT_NO_THROW(GetTree(path1.string(), true));
}

TEST_F(TreeTestCase, ThirdTestOnSubDirFalse) {
  EXPECT_NO_THROW(GetTree(path1.string(), false));
}

TEST_F(TreeTestCase, FinalTestOnEqual) {
  EXPECT_TRUE(GetTree(path1.string(), true) == GetTree(path1.string(), true));
}
