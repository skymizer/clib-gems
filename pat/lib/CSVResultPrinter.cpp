//===- CSVResultPrinter.cpp -----------------------------------------------===//
//
//                     The pat Team
//
// This file is distributed under the New BSD License. 
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <pat/CSVResultPrinter.h>
#include <pat/Color.h>
#include <iostream>

using namespace pat;

//===----------------------------------------------------------------------===//
// CSVResultPrinter
//===----------------------------------------------------------------------===//
void CSVResultPrinter::PrintCaseName(const std::string& pCase,
                                        const std::string& pTest)
{
}

void CSVResultPrinter::OnTestProgramStart(const testing::UnitTest& pUnitTest)
{
}

void CSVResultPrinter::OnTestCaseStart(const testing::TestCase& pTestCase)
{
}

void CSVResultPrinter::OnTestStart(const testing::TestInfo& pTestInfo)
{
}

void CSVResultPrinter::OnTestEnd(const testing::TestInfo& pTestInfo)
{
  // performance test results
  if (!pTestInfo.result().performance().empty()) {
    // timer's result
    testing::TestResult::Performance::const_iterator perf =
                                      pTestInfo.result().performance().begin();
    testing::TestResult::Performance::const_iterator pEnd =
                                      pTestInfo.result().performance().end();
    while (perf != pEnd) {
      std::cout << (*perf)->getTimerNum() << ",";
      ++perf;
    }
  }
}

void CSVResultPrinter::OnTestProgramEnd(const testing::UnitTest& pUnitTest)
{
}
