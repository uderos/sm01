#ifndef UDR_SM_EVENT_H
#define UDR_SM_EVENT_H

#include <memory>
#include <string>

namespace udr {
namespace sm {

class Event
{
  public:
    Event(const int event_id, const std::string & name);
    virtual ~Event() = default;

    int GetId() const;
    virtual std::string to_string() const;

  private:
    const int m_event_id;
    const std::string m_name;

    Event(const Event &) = delete;
    Event(Event &&) = delete;

    Event & operator=(const Event &) = delete;
    Event & operator=(Event &&) = delete;
    
};

template <typename DATA_T>
class EventWithData : public Event
{
  public:
    EventWithData(const int event_id, const std::string & name);
    EventWithData(const int event_id, const std::string & name, const DATA_T & data);
    virtual ~EventWithData() = default;

    virtual void SetData(const DATA_T & data);
    virtual DATA_T & GetData() const;

  private:
    DATA_T m_data;

};

template <typename DATA_T>
EventWithData<DATA_T>::EventWithData(const int event_id, 
                                     const std::string & name, 
                                     const DATA_T & data) :
  Event(event_id, name),
  m_data(data)
{
}

template <typename DATA_T>
EventWithData<DATA_T>::EventWithData(const int event_id, 
                                     const std::string & name)
  Event(event_id, name),
  m_data()
{
}

template <typename DATA_T>
const DATA_T & EventWithData<DATA_T>::GetData() const
{
  return m_data;
}

template <typename DATA_T>
void EventWithData<DATA_T>::SetData(const DATA_T & data) const
{
  m_data = data;
}



} // namespace sm
} // namespace udr

#endif // UDR_SM_EVENT_H
