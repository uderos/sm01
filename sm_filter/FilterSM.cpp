
#include "States.h"

FilterSM::FilterSM() : StateMachine("MakeFilterSM", std::make_unique<StateWaitCmd>())
{
}

StatePtr StateIdle::m_process_event(const Event & event)
{
  switch (event.GetId())
  {
    case eEventId::EVENT_CPP:
      return std::make_unique<StateWaitCppNameArg>();
      break;
    case EventId::EVENT_AR:
      return std::make_unique<StateWaitArNameArg>();
      break;
    case EventId::EVENT_STR:
      
      break;
  }
}


FilterSM::FilterSM() : StateMachine("FilterSM")
{
}

