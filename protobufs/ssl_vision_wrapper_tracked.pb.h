// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ssl_vision_wrapper_tracked.proto

#ifndef PROTOBUF_INCLUDED_ssl_5fvision_5fwrapper_5ftracked_2eproto
#define PROTOBUF_INCLUDED_ssl_5fvision_5fwrapper_5ftracked_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "ssl_vision_detection_tracked.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_ssl_5fvision_5fwrapper_5ftracked_2eproto 

namespace protobuf_ssl_5fvision_5fwrapper_5ftracked_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_ssl_5fvision_5fwrapper_5ftracked_2eproto
class TrackerWrapperPacket;
class TrackerWrapperPacketDefaultTypeInternal;
extern TrackerWrapperPacketDefaultTypeInternal _TrackerWrapperPacket_default_instance_;
namespace google {
namespace protobuf {
template<> ::TrackerWrapperPacket* Arena::CreateMaybeMessage<::TrackerWrapperPacket>(Arena*);
}  // namespace protobuf
}  // namespace google

// ===================================================================

class TrackerWrapperPacket : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:TrackerWrapperPacket) */ {
 public:
  TrackerWrapperPacket();
  virtual ~TrackerWrapperPacket();

  TrackerWrapperPacket(const TrackerWrapperPacket& from);

  inline TrackerWrapperPacket& operator=(const TrackerWrapperPacket& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  TrackerWrapperPacket(TrackerWrapperPacket&& from) noexcept
    : TrackerWrapperPacket() {
    *this = ::std::move(from);
  }

  inline TrackerWrapperPacket& operator=(TrackerWrapperPacket&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TrackerWrapperPacket& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const TrackerWrapperPacket* internal_default_instance() {
    return reinterpret_cast<const TrackerWrapperPacket*>(
               &_TrackerWrapperPacket_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(TrackerWrapperPacket* other);
  friend void swap(TrackerWrapperPacket& a, TrackerWrapperPacket& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline TrackerWrapperPacket* New() const final {
    return CreateMaybeMessage<TrackerWrapperPacket>(NULL);
  }

  TrackerWrapperPacket* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<TrackerWrapperPacket>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const TrackerWrapperPacket& from);
  void MergeFrom(const TrackerWrapperPacket& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(TrackerWrapperPacket* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string uuid = 1;
  bool has_uuid() const;
  void clear_uuid();
  static const int kUuidFieldNumber = 1;
  const ::std::string& uuid() const;
  void set_uuid(const ::std::string& value);
  #if LANG_CXX11
  void set_uuid(::std::string&& value);
  #endif
  void set_uuid(const char* value);
  void set_uuid(const char* value, size_t size);
  ::std::string* mutable_uuid();
  ::std::string* release_uuid();
  void set_allocated_uuid(::std::string* uuid);

  // optional string source_name = 2;
  bool has_source_name() const;
  void clear_source_name();
  static const int kSourceNameFieldNumber = 2;
  const ::std::string& source_name() const;
  void set_source_name(const ::std::string& value);
  #if LANG_CXX11
  void set_source_name(::std::string&& value);
  #endif
  void set_source_name(const char* value);
  void set_source_name(const char* value, size_t size);
  ::std::string* mutable_source_name();
  ::std::string* release_source_name();
  void set_allocated_source_name(::std::string* source_name);

  // optional .TrackedFrame tracked_frame = 3;
  bool has_tracked_frame() const;
  void clear_tracked_frame();
  static const int kTrackedFrameFieldNumber = 3;
  private:
  const ::TrackedFrame& _internal_tracked_frame() const;
  public:
  const ::TrackedFrame& tracked_frame() const;
  ::TrackedFrame* release_tracked_frame();
  ::TrackedFrame* mutable_tracked_frame();
  void set_allocated_tracked_frame(::TrackedFrame* tracked_frame);

  // @@protoc_insertion_point(class_scope:TrackerWrapperPacket)
 private:
  void set_has_uuid();
  void clear_has_uuid();
  void set_has_source_name();
  void clear_has_source_name();
  void set_has_tracked_frame();
  void clear_has_tracked_frame();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr uuid_;
  ::google::protobuf::internal::ArenaStringPtr source_name_;
  ::TrackedFrame* tracked_frame_;
  friend struct ::protobuf_ssl_5fvision_5fwrapper_5ftracked_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// TrackerWrapperPacket

// required string uuid = 1;
inline bool TrackerWrapperPacket::has_uuid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void TrackerWrapperPacket::set_has_uuid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void TrackerWrapperPacket::clear_has_uuid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void TrackerWrapperPacket::clear_uuid() {
  uuid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_uuid();
}
inline const ::std::string& TrackerWrapperPacket::uuid() const {
  // @@protoc_insertion_point(field_get:TrackerWrapperPacket.uuid)
  return uuid_.GetNoArena();
}
inline void TrackerWrapperPacket::set_uuid(const ::std::string& value) {
  set_has_uuid();
  uuid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:TrackerWrapperPacket.uuid)
}
#if LANG_CXX11
inline void TrackerWrapperPacket::set_uuid(::std::string&& value) {
  set_has_uuid();
  uuid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:TrackerWrapperPacket.uuid)
}
#endif
inline void TrackerWrapperPacket::set_uuid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_uuid();
  uuid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:TrackerWrapperPacket.uuid)
}
inline void TrackerWrapperPacket::set_uuid(const char* value, size_t size) {
  set_has_uuid();
  uuid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:TrackerWrapperPacket.uuid)
}
inline ::std::string* TrackerWrapperPacket::mutable_uuid() {
  set_has_uuid();
  // @@protoc_insertion_point(field_mutable:TrackerWrapperPacket.uuid)
  return uuid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* TrackerWrapperPacket::release_uuid() {
  // @@protoc_insertion_point(field_release:TrackerWrapperPacket.uuid)
  if (!has_uuid()) {
    return NULL;
  }
  clear_has_uuid();
  return uuid_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void TrackerWrapperPacket::set_allocated_uuid(::std::string* uuid) {
  if (uuid != NULL) {
    set_has_uuid();
  } else {
    clear_has_uuid();
  }
  uuid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), uuid);
  // @@protoc_insertion_point(field_set_allocated:TrackerWrapperPacket.uuid)
}

// optional string source_name = 2;
inline bool TrackerWrapperPacket::has_source_name() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void TrackerWrapperPacket::set_has_source_name() {
  _has_bits_[0] |= 0x00000002u;
}
inline void TrackerWrapperPacket::clear_has_source_name() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void TrackerWrapperPacket::clear_source_name() {
  source_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_source_name();
}
inline const ::std::string& TrackerWrapperPacket::source_name() const {
  // @@protoc_insertion_point(field_get:TrackerWrapperPacket.source_name)
  return source_name_.GetNoArena();
}
inline void TrackerWrapperPacket::set_source_name(const ::std::string& value) {
  set_has_source_name();
  source_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:TrackerWrapperPacket.source_name)
}
#if LANG_CXX11
inline void TrackerWrapperPacket::set_source_name(::std::string&& value) {
  set_has_source_name();
  source_name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:TrackerWrapperPacket.source_name)
}
#endif
inline void TrackerWrapperPacket::set_source_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_source_name();
  source_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:TrackerWrapperPacket.source_name)
}
inline void TrackerWrapperPacket::set_source_name(const char* value, size_t size) {
  set_has_source_name();
  source_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:TrackerWrapperPacket.source_name)
}
inline ::std::string* TrackerWrapperPacket::mutable_source_name() {
  set_has_source_name();
  // @@protoc_insertion_point(field_mutable:TrackerWrapperPacket.source_name)
  return source_name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* TrackerWrapperPacket::release_source_name() {
  // @@protoc_insertion_point(field_release:TrackerWrapperPacket.source_name)
  if (!has_source_name()) {
    return NULL;
  }
  clear_has_source_name();
  return source_name_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void TrackerWrapperPacket::set_allocated_source_name(::std::string* source_name) {
  if (source_name != NULL) {
    set_has_source_name();
  } else {
    clear_has_source_name();
  }
  source_name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), source_name);
  // @@protoc_insertion_point(field_set_allocated:TrackerWrapperPacket.source_name)
}

// optional .TrackedFrame tracked_frame = 3;
inline bool TrackerWrapperPacket::has_tracked_frame() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void TrackerWrapperPacket::set_has_tracked_frame() {
  _has_bits_[0] |= 0x00000004u;
}
inline void TrackerWrapperPacket::clear_has_tracked_frame() {
  _has_bits_[0] &= ~0x00000004u;
}
inline const ::TrackedFrame& TrackerWrapperPacket::_internal_tracked_frame() const {
  return *tracked_frame_;
}
inline const ::TrackedFrame& TrackerWrapperPacket::tracked_frame() const {
  const ::TrackedFrame* p = tracked_frame_;
  // @@protoc_insertion_point(field_get:TrackerWrapperPacket.tracked_frame)
  return p != NULL ? *p : *reinterpret_cast<const ::TrackedFrame*>(
      &::_TrackedFrame_default_instance_);
}
inline ::TrackedFrame* TrackerWrapperPacket::release_tracked_frame() {
  // @@protoc_insertion_point(field_release:TrackerWrapperPacket.tracked_frame)
  clear_has_tracked_frame();
  ::TrackedFrame* temp = tracked_frame_;
  tracked_frame_ = NULL;
  return temp;
}
inline ::TrackedFrame* TrackerWrapperPacket::mutable_tracked_frame() {
  set_has_tracked_frame();
  if (tracked_frame_ == NULL) {
    auto* p = CreateMaybeMessage<::TrackedFrame>(GetArenaNoVirtual());
    tracked_frame_ = p;
  }
  // @@protoc_insertion_point(field_mutable:TrackerWrapperPacket.tracked_frame)
  return tracked_frame_;
}
inline void TrackerWrapperPacket::set_allocated_tracked_frame(::TrackedFrame* tracked_frame) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(tracked_frame_);
  }
  if (tracked_frame) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      tracked_frame = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, tracked_frame, submessage_arena);
    }
    set_has_tracked_frame();
  } else {
    clear_has_tracked_frame();
  }
  tracked_frame_ = tracked_frame;
  // @@protoc_insertion_point(field_set_allocated:TrackerWrapperPacket.tracked_frame)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_ssl_5fvision_5fwrapper_5ftracked_2eproto
