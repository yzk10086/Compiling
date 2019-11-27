#include "catch2/catch.hpp"
#include "tokenizer/tokenizer.h"
#include "fmt/core.h"

#include <sstream>
#include <vector>
#include <iostream>

#include "analyser/analyser.h"
#include "instruction/instruction.h"
// 下面是示例如何书写测试用例
TEST_CASE("Test for Tokenizer.") {
	std::string input = 
		"begin\n"
		"	const b = 1;\n"
		"	var a = 3;\n"
		"	var c ;\n"
		"	c = a + 100;\n"
		"	print(a+b+c);"
		"end\n";
	std::stringstream ss;
	ss.str(input);
	miniplc0::Tokenizer tkz(ss);
	std::vector<miniplc0::Token> output = {
		
	};
	auto result = tkz.AllTokens();
	std::vector<miniplc0::Token> tmp = result.first;
	//miniplc0::Analyser anlz(result.first);

	for (std::vector<miniplc0::Token>::iterator it = tmp.begin(); it != tmp.end(); it++)
	{
		miniplc0::TokenType type = it->GetType();
		std::any value = it->GetValue();
		std::pair<int, int> p1 = it->GetStartPos();
		std::pair<int, int> p2 = it->GetEndPos();
		std::cout << "Line: " << p1.first << " Column: " << p1.second << " Type: " 
			<< type << " Value: " << std::any_cast<std::string>(value) << "\n";
	}
	/*
	if (!anlz.Analyse().second.has_value())
		std::cout << "correct!";
	else
		std::cout << "fail\n";
	*/
	if (result.second.has_value()) {
		FAIL();
	}
	// REQUIRE( (result.first == output) );
}