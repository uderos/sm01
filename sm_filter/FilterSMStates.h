#ifndef UDR_SM_FILTER_STATES_H
#define UDR_SM_FILTER_STATES_H

#include <sm_lib/State.h>

namespace udr {
namespace sm {
namespace filter_sm {

#define CONSTRUCTOR_DESTRUCTOR(CLASS) \
  CLASS(); \
  virtual ~ CLASS() = default

//===========================================================================  

class DefaultState : public udr::sm::State
{

  protected:
    DefaultState(const std::string & name);
    virtual ~DefaultState() = default;

  private:
    udr::sm::StatePtr m_EOF_handler(const udr::sm::Event & event);
};


//===========================================================================  

class StateWaitCmd : public DefaultState
{
  public:
    CONSTRUCTOR_DESTRUCTOR(StateWaitCmd);

  private:
    udr::sm::StatePtr m_TEXT_handler(const udr::sm::Event & event);
    udr::sm::StatePtr m_CPP_handler(const udr::sm::Event & event);
    udr::sm::StatePtr m_AR_handler(const udr::sm::Event & event);
    udr::sm::StatePtr m_LD_WARN_handler(const udr::sm::Event & event);
    udr::sm::StatePtr m_EOL_handler(const udr::sm::Event & event);
};


//===========================================================================  

class StateWaitCppNameTag : public DefaultState
{
  public:
    CONSTRUCTOR_DESTRUCTOR(StateWaitCppNameTag);

  private:
    udr::sm::StatePtr m_CPP_NAME_TAG_handler(const udr::sm::Event & event);
};

//===========================================================================  

class StateWaitArNameTag : public DefaultState
{
  public:
    CONSTRUCTOR_DESTRUCTOR(StateWaitArNameTag);

  private:
    udr::sm::StatePtr m_AR_NAME_TAG_handler(const udr::sm::Event & event);
};

//===========================================================================  

class StateWaitFileName : public DefaultState
{
  public:
    CONSTRUCTOR_DESTRUCTOR(StateWaitFileName);

  private:
    udr::sm::StatePtr m_TEXT_handler(const udr::sm::Event & event);
};

//===========================================================================  

class StateWaitEndOfLine : public DefaultState
{
  public:
    CONSTRUCTOR_DESTRUCTOR(StateWaitEndOfLine);

  private:
    udr::sm::StatePtr m_EOL_handler(const udr::sm::Event & event);
};

//===========================================================================  

class StateDropLine : public DefaultState
{
  public:
    CONSTRUCTOR_DESTRUCTOR(StateDropLine);

  private:
    udr::sm::StatePtr m_EOL_handler(const udr::sm::Event & event);
};

//===========================================================================  

class StateTheEnd : public DefaultState
{
  public:
    CONSTRUCTOR_DESTRUCTOR(StateTheEnd);
    virtual bool IsTerminal() const;
};



} // namespace filter_sm
} // namespace sm
} // namespace udr

#endif // UDR_SM_FILTER_STATES_H

