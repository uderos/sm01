#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "sm_filter/FilterSM.h"

using namespace udr::sm;
using namespace udr::sm::filter_sm;

static void f_test04()
{
  std::cout << "test04 - BEGIN" << std::endl;

  std::vector<std::string> text {
    "First Line eol1",
    "g++ xx xx -o file1.o yy yy eol2",
    "Third Line eol3",
    "g++ xx xx eol4",
    "yy yy -o file2 ww ww eol5",
    "Sixth Line eol6"
  };

  FilterSM sm;

  for (const std::string & line : text)
  {
    std::istringstream iss(line);

    std::string token;
    while (iss >> token)
      sm.ProcessTextToken(token);
  }

  std::cout << "test04 - END" << std::endl;
}

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

