//
// Created by akhtyamovpavel on 5/1/20.
//

//#include <boost/filesystem/path.hpp>
#include "TreeTestCase.h"
#include "Tree.h"

using namespace boost::filesystem;

TreeTestCase::TreeTestCase() {
	path1 = current_path();
	path2 = current_path();
   	
	path1 += "/dir1";
	path2 += "/dir1/sub_dir";    
	
	create_directory(path1);
    	new_stream = std::ofstream("dir1/file1.cpp");
	
	create_directory(path2);
	new_stream = std::ofstream("dir1/sub_dir/file2.cpp");
}

TreeTestCase::~TreeTestCase() {
	remove_all(path1);
	remove_all(path2);
}

TEST_F(TreeTestCase, TestThrow) {
	ASSERT_THROW(GetTree("keklya", true), std::invalid_argument);
}

TEST_F(TreeTestCase, TestThrowDir) {
	ASSERT_THROW(GetTree(path1.string() + "/file1.cpp", true), std::invalid_argument);
}

TEST_F(TreeTestCase, TestNoThrow) {
	ASSERT_NO_THROW(GetTree(path1.string(), true));
}

TEST_F(TreeTestCase, ThirdTestOnSubDirFalse) {
  	ASSERT_NO_THROW(GetTree(path1.string(), false));
}

TEST_F(TreeTestCase, TestEquality) {
	ASSERT_TRUE(GetTree(path1.string(), true) == GetTree(path1.string(), true));
}
