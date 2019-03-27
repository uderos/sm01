#include <functional>
#include <iostream>
#include "FilterSMEvents.h"
#include "FilterSMStates.h"

namespace udr {
namespace sm {
namespace filter_sm {


#define REGISTER_HANDLER(EVENT, HANDLER) \
  RegisterEventHandler(eEventId :: EVENT, \
                       std::bind(& HANDLER, this, std::placeholders::_1));

#define STATE_TRANSITION(NEXT_STATE)  { return std::make_unique< NEXT_STATE >(); }
#define NO_STATE_TRANSITION  { return udr::sm::StatePtr(); }

//===========================================================================  

DefaultState::DefaultState(const std::string & name) : udr::sm::State(name)
{
  REGISTER_HANDLER(EVENT_EOF, DefaultState::m_EOF_handler);
}

udr::sm::StatePtr DefaultState::m_EOF_handler(const udr::sm::Event & event)
{
  STATE_TRANSITION(StateTheEnd);
}

//===========================================================================  

StateWaitCmd::StateWaitCmd() : DefaultState("WaitCmd")
{
  SetIgnoreEventList({eEventId::EVENT_CPP_NAME_TAG, eEventId::EVENT_CPP_NAME_TAG});

  REGISTER_HANDLER(EVENT_TEXT,      StateWaitCmd::m_TEXT_handler);
  REGISTER_HANDLER(EVENT_CPP,       StateWaitCmd::m_CPP_handler);
  REGISTER_HANDLER(EVENT_AR,        StateWaitCmd::m_AR_handler);
  REGISTER_HANDLER(EVENT_LD_WARN,   StateWaitCmd::m_LD_WARN_handler);
  REGISTER_HANDLER(EVENT_EOL,       StateWaitCmd::m_EOL_handler);
}

udr::sm::StatePtr StateWaitCmd::m_TEXT_handler(const udr::sm::Event & event)
{
  const auto & e = dynamic_cast<const Event_EVENT_TEXT &>(event);

  std::cout << e.GetData() << ' ';

  NO_STATE_TRANSITION;
}

udr::sm::StatePtr StateWaitCmd::m_CPP_handler(const udr::sm::Event & event)
{
  std::cout << "C++ ";
  STATE_TRANSITION(StateWaitCppNameTag);
}

udr::sm::StatePtr StateWaitCmd::m_AR_handler(const udr::sm::Event & event)
{
  std::cout << "AR ";
  STATE_TRANSITION(StateWaitArNameTag);
}

udr::sm::StatePtr StateWaitCmd::m_LD_WARN_handler(const udr::sm::Event & event)
{
  STATE_TRANSITION(StateDropLine);
}

udr::sm::StatePtr StateWaitCmd::m_EOL_handler(const udr::sm::Event & event)
{
  std::cout << std::endl;
  NO_STATE_TRANSITION;
}



//===========================================================================  

StateWaitCppNameTag::StateWaitCppNameTag() : DefaultState("WaitCppNameTag")
{
  SetIgnoreEventList( { eEventId::EVENT_TEXT, 
                        eEventId::EVENT_CPP, 
                        eEventId::EVENT_AR, 
                        eEventId::EVENT_LD_WARN, 
                        eEventId::EVENT_AR_NAME_TAG, 
                        eEventId::EVENT_EOL });

  REGISTER_HANDLER(EVENT_CPP_NAME_TAG,  StateWaitCppNameTag::m_CPP_NAME_TAG_handler);
}

udr::sm::StatePtr StateWaitCppNameTag::m_CPP_NAME_TAG_handler(const udr::sm::Event & event)
{
  STATE_TRANSITION(StateWaitFileName);
}

//===========================================================================  

StateWaitArNameTag::StateWaitArNameTag() : DefaultState("WaitArNameTag")
{
  SetIgnoreEventList( { eEventId::EVENT_TEXT, 
                        eEventId::EVENT_CPP, 
                        eEventId::EVENT_AR, 
                        eEventId::EVENT_LD_WARN, 
                        eEventId::EVENT_CPP_NAME_TAG, 
                        eEventId::EVENT_EOL });

  REGISTER_HANDLER(EVENT_AR_NAME_TAG,  StateWaitArNameTag::m_AR_NAME_TAG_handler);
}

udr::sm::StatePtr StateWaitArNameTag::m_AR_NAME_TAG_handler(const udr::sm::Event & event)
{
  STATE_TRANSITION(StateWaitFileName);
}

//===========================================================================  

StateWaitFileName::StateWaitFileName() : DefaultState("WaitFileName")
{
  SetIgnoreEventList( { eEventId::EVENT_CPP, 
                        eEventId::EVENT_AR, 
                        eEventId::EVENT_LD_WARN, 
                        eEventId::EVENT_CPP_NAME_TAG, 
                        eEventId::EVENT_AR_NAME_TAG, 
                        eEventId::EVENT_EOL });

  REGISTER_HANDLER(EVENT_TEXT,  StateWaitFileName::m_TEXT_handler);
}

udr::sm::StatePtr StateWaitFileName::m_TEXT_handler(const udr::sm::Event & event)
{
  const auto & e = dynamic_cast<const Event_EVENT_TEXT &>(event);

  std::cout << e.GetData() << ' ';

  STATE_TRANSITION(StateWaitEndOfLine);
}

//===========================================================================  

StateWaitEndOfLine::StateWaitEndOfLine() : DefaultState("WaitEndOfLine")
{
  SetIgnoreEventList( { eEventId::EVENT_TEXT, 
                        eEventId::EVENT_CPP, 
                        eEventId::EVENT_AR, 
                        eEventId::EVENT_LD_WARN, 
                        eEventId::EVENT_CPP_NAME_TAG, 
                        eEventId::EVENT_AR_NAME_TAG });

  REGISTER_HANDLER(EVENT_EOL,  StateWaitEndOfLine::m_EOL_handler);
}

udr::sm::StatePtr StateWaitEndOfLine::m_EOL_handler(const udr::sm::Event & event)
{
  std::cout << '\n';
  STATE_TRANSITION(StateWaitCmd);
}

//===========================================================================  

StateDropLine::StateDropLine() : DefaultState("DropLine")
{
  SetIgnoreEventList( { eEventId::EVENT_TEXT, 
                        eEventId::EVENT_CPP, 
                        eEventId::EVENT_AR, 
                        eEventId::EVENT_LD_WARN, 
                        eEventId::EVENT_CPP_NAME_TAG, 
                        eEventId::EVENT_AR_NAME_TAG });

  REGISTER_HANDLER(EVENT_EOL,  StateDropLine::m_EOL_handler);
}

udr::sm::StatePtr StateDropLine::m_EOL_handler(const udr::sm::Event & event)
{
  STATE_TRANSITION(StateWaitCmd);
}

//===========================================================================  

StateTheEnd::StateTheEnd() : DefaultState("TheEnd")
{
  SetIgnoreEventList( { eEventId::EVENT_TEXT, 
                        eEventId::EVENT_CPP, 
                        eEventId::EVENT_AR, 
                        eEventId::EVENT_LD_WARN, 
                        eEventId::EVENT_CPP_NAME_TAG, 
                        eEventId::EVENT_AR_NAME_TAG,
                        eEventId::EVENT_EOL });
}

bool StateTheEnd::IsTerminal() const
{
  return true;
}


} // namespace filter_sm
} // namespace sm
} // namespace udr

