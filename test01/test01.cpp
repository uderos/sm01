#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "sm_filter/FilterSM.h"

using namespace udr::sm;
using namespace udr::sm::filter_sm;

static void f_test03()
{
  std::cout << "test03 - BEGIN" << std::endl;

  {
    auto p = StatePtr();
    std::cout << "p=" << p.get() << std::endl;
  }

  FilterSM sm;
  sm.ProcessTextToken("g++");
  sm.ProcessTextToken("xx");
  sm.ProcessTextToken("xx");
  sm.ProcessTextToken("xx");
  sm.ProcessTextToken("-o");
  sm.ProcessTextToken("FileName");
  sm.ProcessTextToken("xx");
  sm.ProcessTextToken("xx");
  sm.ProcessTextToken("xx");
  sm.ProcessEndOfLine();
  sm.ProcessTextToken("xx");
  sm.ProcessTextToken("xx");
  sm.ProcessEndOfLine();
  sm.ProcessTextToken("xx");
  sm.ProcessTextToken("xx");
  sm.ProcessTextToken("xx");
  sm.ProcessEndOfFile();
  sm.ProcessTextToken("xx");
  sm.ProcessTextToken("xx");

  std::cout << "test03 - END" << std::endl;
}

static void f_test02()
{
  std::cout << "test02 - BEGIN" << std::endl;

  std::ifstream ifs("/tmp/Build.exe");
  std::string line, token;

  FilterSM sm;

  while (std::getline(ifs, line))
  {
    std::istringstream iss(line);

    while (iss >> token)
      sm.ProcessTextToken(token);

    sm.ProcessEndOfLine();
  }
  
  sm.ProcessEndOfFile();

  std::cout << "test02 - END" << std::endl;
}

static void f_test01()
{
  std::cout << "test01 - BEGIN" << std::endl;


  {
    Event_EVENT_CPP e;
    StateWaitCmd s;
  }

  {
    FilterSM sm;
    std::cout << "sm: " << sm.to_string() << std::endl;
  }

  std::cout << "test01 - END" << std::endl;
}


int main()
{
  try
  {
    //f_test01();
    //f_test02();
    f_test03();
  }
  catch (const std::exception & e)
  {
    std::cout << "EXCEPTION: " << e.what() << std::endl;
  }

  return 0;
}

