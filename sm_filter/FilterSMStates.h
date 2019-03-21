#ifndef UDR_SM_FILTER_STATES_H
#define UDR_SM_FILTER_STATES_H

#include <sm_lib/State.h>

namespace udr {
namespace sm {
namespace filter_sm {



//===========================================================================  

class DefaultState : public udr::sm::State
{
  protected:
    DefaultState(const std::string & name);

  private:
    udr::sm::StatePtr m_EOF_handler(const udr::sm::Event & event);
};


//===========================================================================  

class StateWaitCmd : public DefaultState
{
  public:
    StateWaitCmd();

  private:
    udr::sm::StatePtr m_TEXT_handler(const udr::sm::Event & event);
    udr::sm::StatePtr m_CPP_handler(const udr::sm::Event & event);
    udr::sm::StatePtr m_AR_handler(const udr::sm::Event & event);
    udr::sm::StatePtr m_EOL_handler(const udr::sm::Event & event);
};


//===========================================================================  

class StateWaitCppNameTag : public DefaultState
{
  public:
    StateWaitCppNameTag();

  private:
    udr::sm::StatePtr m_CPP_NAME_TAG_handler(const udr::sm::Event & event);
};

//===========================================================================  

class StateWaitArNameTag : public DefaultState
{
  public:
    StateWaitArNameTag();

  private:
    udr::sm::StatePtr m_AR_NAME_TAG_handler(const udr::sm::Event & event);
};

//===========================================================================  

class StateWaitFileName : public DefaultState
{
  public:
    StateWaitFileName();

  private:
    udr::sm::StatePtr m_TEXT_handler(const udr::sm::Event & event);
};

//===========================================================================  

class StateWaitEndOfLine : public DefaultState
{
  public:
    StateWaitEndOfLine();

  private:
    udr::sm::StatePtr m_EOL_handler(const udr::sm::Event & event);
};

//===========================================================================  

class StateTheEnd : public DefaultState
{
  public:
    StateTheEnd();
    virtual bool IsTerminal() const;
};



} // namespace filter_sm
} // namespace sm
} // namespace udr

#endif // UDR_SM_FILTER_STATES_H

