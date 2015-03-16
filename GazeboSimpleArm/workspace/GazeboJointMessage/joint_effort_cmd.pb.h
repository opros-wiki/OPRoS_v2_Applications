// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: joint_effort_cmd.proto

#ifndef PROTOBUF_joint_5feffort_5fcmd_2eproto__INCLUDED
#define PROTOBUF_joint_5feffort_5fcmd_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

namespace my_msgs {
namespace msgs {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_joint_5feffort_5fcmd_2eproto();
void protobuf_AssignDesc_joint_5feffort_5fcmd_2eproto();
void protobuf_ShutdownFile_joint_5feffort_5fcmd_2eproto();

class JointEffortCmdRequest;

// ===================================================================

class JointEffortCmdRequest : public ::google::protobuf::Message {
 public:
  JointEffortCmdRequest();
  virtual ~JointEffortCmdRequest();
  
  JointEffortCmdRequest(const JointEffortCmdRequest& from);
  
  inline JointEffortCmdRequest& operator=(const JointEffortCmdRequest& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const JointEffortCmdRequest& default_instance();
  
  void Swap(JointEffortCmdRequest* other);
  
  // implements Message ----------------------------------------------
  
  JointEffortCmdRequest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const JointEffortCmdRequest& from);
  void MergeFrom(const JointEffortCmdRequest& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // repeated string name = 1;
  inline int name_size() const;
  inline void clear_name();
  static const int kNameFieldNumber = 1;
  inline const ::std::string& name(int index) const;
  inline ::std::string* mutable_name(int index);
  inline void set_name(int index, const ::std::string& value);
  inline void set_name(int index, const char* value);
  inline void set_name(int index, const char* value, size_t size);
  inline ::std::string* add_name();
  inline void add_name(const ::std::string& value);
  inline void add_name(const char* value);
  inline void add_name(const char* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& name() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_name();
  
  // repeated double effort = 2;
  inline int effort_size() const;
  inline void clear_effort();
  static const int kEffortFieldNumber = 2;
  inline double effort(int index) const;
  inline void set_effort(int index, double value);
  inline void add_effort(double value);
  inline const ::google::protobuf::RepeatedField< double >&
      effort() const;
  inline ::google::protobuf::RepeatedField< double >*
      mutable_effort();
  
  // @@protoc_insertion_point(class_scope:my_msgs.msgs.JointEffortCmdRequest)
 private:
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::google::protobuf::RepeatedPtrField< ::std::string> name_;
  ::google::protobuf::RepeatedField< double > effort_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];
  
  friend void  protobuf_AddDesc_joint_5feffort_5fcmd_2eproto();
  friend void protobuf_AssignDesc_joint_5feffort_5fcmd_2eproto();
  friend void protobuf_ShutdownFile_joint_5feffort_5fcmd_2eproto();
  
  void InitAsDefaultInstance();
  static JointEffortCmdRequest* default_instance_;
};
// ===================================================================


// ===================================================================

// JointEffortCmdRequest

// repeated string name = 1;
inline int JointEffortCmdRequest::name_size() const {
  return name_.size();
}
inline void JointEffortCmdRequest::clear_name() {
  name_.Clear();
}
inline const ::std::string& JointEffortCmdRequest::name(int index) const {
  return name_.Get(index);
}
inline ::std::string* JointEffortCmdRequest::mutable_name(int index) {
  return name_.Mutable(index);
}
inline void JointEffortCmdRequest::set_name(int index, const ::std::string& value) {
  name_.Mutable(index)->assign(value);
}
inline void JointEffortCmdRequest::set_name(int index, const char* value) {
  name_.Mutable(index)->assign(value);
}
inline void JointEffortCmdRequest::set_name(int index, const char* value, size_t size) {
  name_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
}
inline ::std::string* JointEffortCmdRequest::add_name() {
  return name_.Add();
}
inline void JointEffortCmdRequest::add_name(const ::std::string& value) {
  name_.Add()->assign(value);
}
inline void JointEffortCmdRequest::add_name(const char* value) {
  name_.Add()->assign(value);
}
inline void JointEffortCmdRequest::add_name(const char* value, size_t size) {
  name_.Add()->assign(reinterpret_cast<const char*>(value), size);
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
JointEffortCmdRequest::name() const {
  return name_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
JointEffortCmdRequest::mutable_name() {
  return &name_;
}

// repeated double effort = 2;
inline int JointEffortCmdRequest::effort_size() const {
  return effort_.size();
}
inline void JointEffortCmdRequest::clear_effort() {
  effort_.Clear();
}
inline double JointEffortCmdRequest::effort(int index) const {
  return effort_.Get(index);
}
inline void JointEffortCmdRequest::set_effort(int index, double value) {
  effort_.Set(index, value);
}
inline void JointEffortCmdRequest::add_effort(double value) {
  effort_.Add(value);
}
inline const ::google::protobuf::RepeatedField< double >&
JointEffortCmdRequest::effort() const {
  return effort_;
}
inline ::google::protobuf::RepeatedField< double >*
JointEffortCmdRequest::mutable_effort() {
  return &effort_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace msgs
}  // namespace my_msgs

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_joint_5feffort_5fcmd_2eproto__INCLUDED