// Generated by gencpp from file industrial_msgs/ServiceReturnCode.msg
// DO NOT EDIT!


#ifndef INDUSTRIAL_MSGS_MESSAGE_SERVICERETURNCODE_H
#define INDUSTRIAL_MSGS_MESSAGE_SERVICERETURNCODE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace industrial_msgs
{
template <class ContainerAllocator>
struct ServiceReturnCode_
{
  typedef ServiceReturnCode_<ContainerAllocator> Type;

  ServiceReturnCode_()
    : val(0)  {
    }
  ServiceReturnCode_(const ContainerAllocator& _alloc)
    : val(0)  {
  (void)_alloc;
    }



   typedef int8_t _val_type;
  _val_type val;



  enum {
    SUCCESS = 1,
    FAILURE = -1,
  };


  typedef boost::shared_ptr< ::industrial_msgs::ServiceReturnCode_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::industrial_msgs::ServiceReturnCode_<ContainerAllocator> const> ConstPtr;

}; // struct ServiceReturnCode_

typedef ::industrial_msgs::ServiceReturnCode_<std::allocator<void> > ServiceReturnCode;

typedef boost::shared_ptr< ::industrial_msgs::ServiceReturnCode > ServiceReturnCodePtr;
typedef boost::shared_ptr< ::industrial_msgs::ServiceReturnCode const> ServiceReturnCodeConstPtr;

// constants requiring out of line definition

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::industrial_msgs::ServiceReturnCode_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::industrial_msgs::ServiceReturnCode_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace industrial_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'industrial_msgs': ['/home/ur5/catkin_ws2/src/industrial_core/industrial_msgs/msg'], 'trajectory_msgs': ['/opt/ros/kinetic/share/trajectory_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::industrial_msgs::ServiceReturnCode_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::industrial_msgs::ServiceReturnCode_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::industrial_msgs::ServiceReturnCode_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::industrial_msgs::ServiceReturnCode_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::industrial_msgs::ServiceReturnCode_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::industrial_msgs::ServiceReturnCode_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::industrial_msgs::ServiceReturnCode_<ContainerAllocator> >
{
  static const char* value()
  {
    return "85a4e241266be66b1e1426b03083a412";
  }

  static const char* value(const ::industrial_msgs::ServiceReturnCode_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x85a4e241266be66bULL;
  static const uint64_t static_value2 = 0x1e1426b03083a412ULL;
};

template<class ContainerAllocator>
struct DataType< ::industrial_msgs::ServiceReturnCode_<ContainerAllocator> >
{
  static const char* value()
  {
    return "industrial_msgs/ServiceReturnCode";
  }

  static const char* value(const ::industrial_msgs::ServiceReturnCode_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::industrial_msgs::ServiceReturnCode_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Service return codes for simple requests.  All ROS-Industrial service\n\
# replies are required to have a return code indicating success or failure\n\
# Specific return codes for different failure should be negative.\n\
int8 val\n\
\n\
int8 SUCCESS = 1\n\
int8 FAILURE = -1\n\
\n\
";
  }

  static const char* value(const ::industrial_msgs::ServiceReturnCode_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::industrial_msgs::ServiceReturnCode_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.val);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ServiceReturnCode_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::industrial_msgs::ServiceReturnCode_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::industrial_msgs::ServiceReturnCode_<ContainerAllocator>& v)
  {
    s << indent << "val: ";
    Printer<int8_t>::stream(s, indent + "  ", v.val);
  }
};

} // namespace message_operations
} // namespace ros

#endif // INDUSTRIAL_MSGS_MESSAGE_SERVICERETURNCODE_H
