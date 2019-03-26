#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "sm_lib/OutMgr.h"
#include "sm_filter/FilterSM.h"

using namespace udr::sm;
using namespace udr::sm::filter_sm;

static void f_test01()
{
  std::ofstream dbgfile("/tmp/smdbg.txt");
  OutMgr::Instance().SetDebugStreams({&dbgfile});
  OutMgr::Instance().SetStdoutStreams({&std::cout, &dbgfile});

  FilterSM sm;

  std::string line;
  while (std::getline(std::cin, line))
  {
    std::istringstream iss(line);

    std::string token;
    while (iss >> token)
      sm.ProcessTextToken(token);

    sm.ProcessTextToken("\n");
  }

  OutMgr::Instance().Reset();
}


int main()
{
  try
  {
    f_test01();
  }
  catch (const std::exception & e)
  {
    std::cout << "EXCEPTION: " << e.what() << std::endl;
  }

  return 0;
}

