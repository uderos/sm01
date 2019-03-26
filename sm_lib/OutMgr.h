#ifndef UDR_SM_OUT_MGR
#define UDR_SM_OUT_MGR

#include <iosfwd>
#include <memory>
#include <vector>


namespace udr {
namespace sm {

namespace local { 

using ostream_ptr_list_t = std::vector<std::ostream *>;

class outstream
{
  public:

    outstream() = default;
    ~outstream() = default;

    template <typename T>
    outstream & operator<<(const T & data);

    outstream & operator<<(std::ostream&(*pf)(std::ostream &));

    void SetOutStreams(const ostream_ptr_list_t & streams);

  private:

    ostream_ptr_list_t m_stream_ptr_list;

    outstream(const outstream &) = delete;
    outstream(outstream &&) = delete;
    outstream & operator=(const outstream &) = delete;
    outstream & operator=(outstream &&) = delete;
};

template <typename T>
outstream & outstream::operator<<(const T & data)
{
  for (auto os_ptr : m_stream_ptr_list)
    (*os_ptr) << data;

  return (*this);
}
    
} // namespace local

class OutMgr
{
  public:

    local::outstream & StdOut();
    local::outstream & DbgOut();

    void SetStdoutStreams(const local::ostream_ptr_list_t & streams);
    void SetDebugStreams(const local::ostream_ptr_list_t & streams);

    static OutMgr & Instance();

  private:
    OutMgr();
    virtual ~OutMgr() = default;

    static OutMgr * m_instance_ptr;

    std::unique_ptr<local::outstream> m_stdout_stream_ptr;
    std::unique_ptr<local::outstream> m_debug_stream_ptr;
};

#define g_STDOUT (OutMgr::Instance().StdOut())
#define g_DBGOUT (OutMgr::Instance().DbgOut())


} // namespace sm
} // namespace udr

#endif // UDR_SM_OUT_MGR
