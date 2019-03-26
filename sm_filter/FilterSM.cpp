#include <iostream>
#include <memory>
#include "FilterSM.h"
#include "FilterSMEvents.h"
#include "FilterSMStates.h"

namespace udr {
namespace sm {
namespace filter_sm {


FilterSM::FilterSM() : 
  StateMachine("MakeFilterSM", 
               std::make_unique<StateWaitCmd>())
{
}

bool FilterSM::IsRunning() const
{
  return (! GetCurrentState().IsTerminal());
}

void FilterSM::ProcessTextToken(const std::string & text_token)
{
  EventPtr event_ptr = m_create_event(text_token);

  ProcessEvent(* event_ptr);
}

void FilterSM::ProcessEndOfLine()
{
  Event_EVENT_EOL event;
  ProcessEvent(event);
}

void FilterSM::ProcessEndOfFile()
{
  Event_EVENT_EOF event;
  ProcessEvent(event);
}

FilterSM::EventPtr FilterSM::m_create_event(const std::string & text_token) const
{
  if ((text_token == "g++") || (text_token == "c++"))
    return std::make_unique<Event_EVENT_CPP>();

  if (text_token == "ar")
    return std::make_unique<Event_EVENT_AR>();

  if (text_token == "-o")
    return std::make_unique<Event_EVENT_CPP_NAME_TAG>();

  if (text_token == "-cr")
    return std::make_unique<Event_EVENT_AR_NAME_TAG>();
    
  if (text_token == "\n")
    return std::make_unique<Event_EVENT_EOL>();
    
  return std::make_unique<Event_EVENT_TEXT>(text_token);
}

} // namespace filter_sm
} // namespace sm
} // namespace udr

