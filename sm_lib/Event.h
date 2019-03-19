#ifndef UDR_SM_EVENT_H
#define UDR_SM_EVENT_H

#include <memory>
#include <string>

namespace udr {
namespace sm {

class Event
{
  public:
    Event(const std::string & name);
    virtual ~Event() = default;

    virtual int GetId() const = 0;
    virtual std::string to_string() const;

  private:
    const std::string m_name;

    Event(const Event &) = delete;
    Event(Event &&) = delete;

    Event & operator=(const Event &) = delete;
    Event & operator=(Event &&) = delete;
    
};

template <int EVENT_ID>
class EventBase
{
  public:
    EventBase(const std::string & name) : Event(name) {};
    virtual ~EventBase() = default;
    virtual int GetId() const;
};

template <int EVENT_ID>
int EventBase<EVENT_ID>::GetId() const
{
  return EVENT_ID;
}

template <int EVENT_ID, typename DATA_T>
class EventBaseWithData<EVENT_ID, DATA_T> : public EventBase<EVENT_ID>
{
  public:
    EventBaseWithData(const std::string & name);
    EventBaseWithData(const std::string & name, const DATA_T & data);
    virtual ~EventBaseWithData() = default;

    virtual void SetData(const DATA_T & data);
    virtual DATA_T & GetData() const;

  private:
    DATA_T m_data;

};

template <int EVENT_ID, typename DATA_T>
EventBaseWithData<EVENT_ID, DATA_T>::EventBaseWithData(const std::string & name, 
                                               const DATA_T & data) :
  EventBase<EVENT_ID>(name),
  m_data(data)
{
}

template <int EVENT_ID, typename DATA_T>
EventBaseWithData<EVENT_ID, DATA_T>::EventBaseWithData(const std::string & name)
  EventBase<EVENT_ID>(name),
  m_data(DATA_T())
{
}

template <int EVENT_ID, typename DATA_T>
const DATA_T & EventBaseWithData<EVENT_ID, DATA_T>::GetData() const
{
  return m_data;
}

template <int EVENT_ID, typename DATA_T>
void EventBaseWithData<EVENT_ID, DATA_T>::SetData(const DATA_T & data) const
{
  m_data = data;
}



} // namespace sm
} // namespace udr

#endif // UDR_SM_EVENT_H
