#include <fstream>
#include <iostream>
#include <vector>
#include "OutMgr.h"

namespace udr {
namespace sm {

/////////////////////////////////////////////////////////////////////////////
namespace local {

void outstream::SetOutStreams(const ostream_ptr_list_t & streams)
{
    m_stream_ptr_list.clear();
    m_stream_ptr_list = streams;
}

outstream & outstream::operator<<(std::ostream&(*pf)(std::ostream &))
{
  for (auto os_ptr : m_stream_ptr_list)
    pf(*os_ptr);

  return (*this);
}

} // namespace local

/////////////////////////////////////////////////////////////////////////////

OutMgr * OutMgr::m_instance_ptr= nullptr;

OutMgr & OutMgr::Instance()
{
  if (! m_instance_ptr)
    m_instance_ptr = new OutMgr;

  return * m_instance_ptr;
}

OutMgr::OutMgr() :
  m_stdout_stream_ptr(std::make_unique<local::outstream>()),
  m_debug_stream_ptr(std::make_unique<local::outstream>())
{
}

void OutMgr::SetStdoutStreams(const local::ostream_ptr_list_t & streams)
{
  m_stdout_stream_ptr->SetOutStreams(streams);
}

void OutMgr::SetDebugStreams(const local::ostream_ptr_list_t & streams)
{
  m_debug_stream_ptr->SetOutStreams(streams);
}

void OutMgr::Reset()
{
  m_stdout_stream_ptr->SetOutStreams({});
  m_debug_stream_ptr->SetOutStreams({});
}

local::outstream & OutMgr::StdOut()
{
  return (*m_stdout_stream_ptr.get());
}

local::outstream & OutMgr::DbgOut()
{
  return (*m_debug_stream_ptr.get());
}



} // namespace sm
} // namespace udr

