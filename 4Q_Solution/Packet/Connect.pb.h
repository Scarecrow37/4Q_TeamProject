// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: Connect.proto
// Protobuf C++ Version: 5.29.2

#ifndef Connect_2eproto_2epb_2eh
#define Connect_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/runtime_version.h"
#if PROTOBUF_VERSION != 5029002
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/message_lite.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_Connect_2eproto

namespace google {
namespace protobuf {
namespace internal {
template <typename T>
::absl::string_view GetAnyMessageName();
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_Connect_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_Connect_2eproto;
namespace ConnectMsg {
class EnterAccept;
struct EnterAcceptDefaultTypeInternal;
extern EnterAcceptDefaultTypeInternal _EnterAccept_default_instance_;
class Exit;
struct ExitDefaultTypeInternal;
extern ExitDefaultTypeInternal _Exit_default_instance_;
class SetRoomMaster;
struct SetRoomMasterDefaultTypeInternal;
extern SetRoomMasterDefaultTypeInternal _SetRoomMaster_default_instance_;
class SyncPlayer;
struct SyncPlayerDefaultTypeInternal;
extern SyncPlayerDefaultTypeInternal _SyncPlayer_default_instance_;
}  // namespace ConnectMsg
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace ConnectMsg {

// ===================================================================


// -------------------------------------------------------------------

class SyncPlayer final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:ConnectMsg.SyncPlayer) */ {
 public:
  inline SyncPlayer() : SyncPlayer(nullptr) {}
  ~SyncPlayer() PROTOBUF_FINAL;

#if defined(PROTOBUF_CUSTOM_VTABLE)
  void operator delete(SyncPlayer* msg, std::destroying_delete_t) {
    SharedDtor(*msg);
    ::google::protobuf::internal::SizedDelete(msg, sizeof(SyncPlayer));
  }
#endif

  template <typename = void>
  explicit PROTOBUF_CONSTEXPR SyncPlayer(
      ::google::protobuf::internal::ConstantInitialized);

  inline SyncPlayer(const SyncPlayer& from) : SyncPlayer(nullptr, from) {}
  inline SyncPlayer(SyncPlayer&& from) noexcept
      : SyncPlayer(nullptr, std::move(from)) {}
  inline SyncPlayer& operator=(const SyncPlayer& from) {
    CopyFrom(from);
    return *this;
  }
  inline SyncPlayer& operator=(SyncPlayer&& from) noexcept {
    if (this == &from) return *this;
    if (::google::protobuf::internal::CanMoveWithInternalSwap(GetArena(), from.GetArena())) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const SyncPlayer& default_instance() {
    return *internal_default_instance();
  }
  static inline const SyncPlayer* internal_default_instance() {
    return reinterpret_cast<const SyncPlayer*>(
        &_SyncPlayer_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 3;
  friend void swap(SyncPlayer& a, SyncPlayer& b) { a.Swap(&b); }
  inline void Swap(SyncPlayer* other) {
    if (other == this) return;
    if (::google::protobuf::internal::CanUseInternalSwap(GetArena(), other->GetArena())) {
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SyncPlayer* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  SyncPlayer* New(::google::protobuf::Arena* arena = nullptr) const {
    return ::google::protobuf::Message::DefaultConstruct<SyncPlayer>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const SyncPlayer& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const SyncPlayer& from) { SyncPlayer::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() PROTOBUF_FINAL;
  #if defined(PROTOBUF_CUSTOM_VTABLE)
  private:
  static ::size_t ByteSizeLong(const ::google::protobuf::MessageLite& msg);
  static ::uint8_t* _InternalSerialize(
      const MessageLite& msg, ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream);

  public:
  ::size_t ByteSizeLong() const { return ByteSizeLong(*this); }
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const {
    return _InternalSerialize(*this, target, stream);
  }
  #else   // PROTOBUF_CUSTOM_VTABLE
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  #endif  // PROTOBUF_CUSTOM_VTABLE
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  static void SharedDtor(MessageLite& self);
  void InternalSwap(SyncPlayer* other);
 private:
  template <typename T>
  friend ::absl::string_view(
      ::google::protobuf::internal::GetAnyMessageName)();
  static ::absl::string_view FullMessageName() { return "ConnectMsg.SyncPlayer"; }

 protected:
  explicit SyncPlayer(::google::protobuf::Arena* arena);
  SyncPlayer(::google::protobuf::Arena* arena, const SyncPlayer& from);
  SyncPlayer(::google::protobuf::Arena* arena, SyncPlayer&& from) noexcept
      : SyncPlayer(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::internal::ClassData* GetClassData() const PROTOBUF_FINAL;
  static void* PlacementNew_(const void*, void* mem,
                             ::google::protobuf::Arena* arena);
  static constexpr auto InternalNewImpl_();
  static const ::google::protobuf::internal::ClassDataFull _class_data_;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kSerialnumberFieldNumber = 1,
    kXFieldNumber = 2,
    kYFieldNumber = 3,
    kZFieldNumber = 4,
  };
  // optional int32 serialnumber = 1;
  bool has_serialnumber() const;
  void clear_serialnumber() ;
  ::int32_t serialnumber() const;
  void set_serialnumber(::int32_t value);

  private:
  ::int32_t _internal_serialnumber() const;
  void _internal_set_serialnumber(::int32_t value);

  public:
  // optional float x = 2;
  bool has_x() const;
  void clear_x() ;
  float x() const;
  void set_x(float value);

  private:
  float _internal_x() const;
  void _internal_set_x(float value);

  public:
  // optional float y = 3;
  bool has_y() const;
  void clear_y() ;
  float y() const;
  void set_y(float value);

  private:
  float _internal_y() const;
  void _internal_set_y(float value);

  public:
  // optional float z = 4;
  bool has_z() const;
  void clear_z() ;
  float z() const;
  void set_z(float value);

  private:
  float _internal_z() const;
  void _internal_set_z(float value);

  public:
  // @@protoc_insertion_point(class_scope:ConnectMsg.SyncPlayer)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      2, 4, 0,
      0, 2>
      _table_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const SyncPlayer& from_msg);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    ::google::protobuf::internal::CachedSize _cached_size_;
    ::int32_t serialnumber_;
    float x_;
    float y_;
    float z_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Connect_2eproto;
};
// -------------------------------------------------------------------

class SetRoomMaster final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:ConnectMsg.SetRoomMaster) */ {
 public:
  inline SetRoomMaster() : SetRoomMaster(nullptr) {}
  ~SetRoomMaster() PROTOBUF_FINAL;

#if defined(PROTOBUF_CUSTOM_VTABLE)
  void operator delete(SetRoomMaster* msg, std::destroying_delete_t) {
    SharedDtor(*msg);
    ::google::protobuf::internal::SizedDelete(msg, sizeof(SetRoomMaster));
  }
#endif

  template <typename = void>
  explicit PROTOBUF_CONSTEXPR SetRoomMaster(
      ::google::protobuf::internal::ConstantInitialized);

  inline SetRoomMaster(const SetRoomMaster& from) : SetRoomMaster(nullptr, from) {}
  inline SetRoomMaster(SetRoomMaster&& from) noexcept
      : SetRoomMaster(nullptr, std::move(from)) {}
  inline SetRoomMaster& operator=(const SetRoomMaster& from) {
    CopyFrom(from);
    return *this;
  }
  inline SetRoomMaster& operator=(SetRoomMaster&& from) noexcept {
    if (this == &from) return *this;
    if (::google::protobuf::internal::CanMoveWithInternalSwap(GetArena(), from.GetArena())) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const SetRoomMaster& default_instance() {
    return *internal_default_instance();
  }
  static inline const SetRoomMaster* internal_default_instance() {
    return reinterpret_cast<const SetRoomMaster*>(
        &_SetRoomMaster_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 1;
  friend void swap(SetRoomMaster& a, SetRoomMaster& b) { a.Swap(&b); }
  inline void Swap(SetRoomMaster* other) {
    if (other == this) return;
    if (::google::protobuf::internal::CanUseInternalSwap(GetArena(), other->GetArena())) {
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SetRoomMaster* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  SetRoomMaster* New(::google::protobuf::Arena* arena = nullptr) const {
    return ::google::protobuf::Message::DefaultConstruct<SetRoomMaster>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const SetRoomMaster& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const SetRoomMaster& from) { SetRoomMaster::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() PROTOBUF_FINAL;
  #if defined(PROTOBUF_CUSTOM_VTABLE)
  private:
  static ::size_t ByteSizeLong(const ::google::protobuf::MessageLite& msg);
  static ::uint8_t* _InternalSerialize(
      const MessageLite& msg, ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream);

  public:
  ::size_t ByteSizeLong() const { return ByteSizeLong(*this); }
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const {
    return _InternalSerialize(*this, target, stream);
  }
  #else   // PROTOBUF_CUSTOM_VTABLE
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  #endif  // PROTOBUF_CUSTOM_VTABLE
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  static void SharedDtor(MessageLite& self);
  void InternalSwap(SetRoomMaster* other);
 private:
  template <typename T>
  friend ::absl::string_view(
      ::google::protobuf::internal::GetAnyMessageName)();
  static ::absl::string_view FullMessageName() { return "ConnectMsg.SetRoomMaster"; }

 protected:
  explicit SetRoomMaster(::google::protobuf::Arena* arena);
  SetRoomMaster(::google::protobuf::Arena* arena, const SetRoomMaster& from);
  SetRoomMaster(::google::protobuf::Arena* arena, SetRoomMaster&& from) noexcept
      : SetRoomMaster(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::internal::ClassData* GetClassData() const PROTOBUF_FINAL;
  static void* PlacementNew_(const void*, void* mem,
                             ::google::protobuf::Arena* arena);
  static constexpr auto InternalNewImpl_();
  static const ::google::protobuf::internal::ClassDataFull _class_data_;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kSerialnumberFieldNumber = 1,
  };
  // optional int32 serialnumber = 1;
  bool has_serialnumber() const;
  void clear_serialnumber() ;
  ::int32_t serialnumber() const;
  void set_serialnumber(::int32_t value);

  private:
  ::int32_t _internal_serialnumber() const;
  void _internal_set_serialnumber(::int32_t value);

  public:
  // @@protoc_insertion_point(class_scope:ConnectMsg.SetRoomMaster)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 0,
      0, 2>
      _table_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const SetRoomMaster& from_msg);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    ::google::protobuf::internal::CachedSize _cached_size_;
    ::int32_t serialnumber_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Connect_2eproto;
};
// -------------------------------------------------------------------

class Exit final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:ConnectMsg.Exit) */ {
 public:
  inline Exit() : Exit(nullptr) {}
  ~Exit() PROTOBUF_FINAL;

#if defined(PROTOBUF_CUSTOM_VTABLE)
  void operator delete(Exit* msg, std::destroying_delete_t) {
    SharedDtor(*msg);
    ::google::protobuf::internal::SizedDelete(msg, sizeof(Exit));
  }
#endif

  template <typename = void>
  explicit PROTOBUF_CONSTEXPR Exit(
      ::google::protobuf::internal::ConstantInitialized);

  inline Exit(const Exit& from) : Exit(nullptr, from) {}
  inline Exit(Exit&& from) noexcept
      : Exit(nullptr, std::move(from)) {}
  inline Exit& operator=(const Exit& from) {
    CopyFrom(from);
    return *this;
  }
  inline Exit& operator=(Exit&& from) noexcept {
    if (this == &from) return *this;
    if (::google::protobuf::internal::CanMoveWithInternalSwap(GetArena(), from.GetArena())) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Exit& default_instance() {
    return *internal_default_instance();
  }
  static inline const Exit* internal_default_instance() {
    return reinterpret_cast<const Exit*>(
        &_Exit_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 2;
  friend void swap(Exit& a, Exit& b) { a.Swap(&b); }
  inline void Swap(Exit* other) {
    if (other == this) return;
    if (::google::protobuf::internal::CanUseInternalSwap(GetArena(), other->GetArena())) {
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Exit* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Exit* New(::google::protobuf::Arena* arena = nullptr) const {
    return ::google::protobuf::Message::DefaultConstruct<Exit>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Exit& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const Exit& from) { Exit::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() PROTOBUF_FINAL;
  #if defined(PROTOBUF_CUSTOM_VTABLE)
  private:
  static ::size_t ByteSizeLong(const ::google::protobuf::MessageLite& msg);
  static ::uint8_t* _InternalSerialize(
      const MessageLite& msg, ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream);

  public:
  ::size_t ByteSizeLong() const { return ByteSizeLong(*this); }
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const {
    return _InternalSerialize(*this, target, stream);
  }
  #else   // PROTOBUF_CUSTOM_VTABLE
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  #endif  // PROTOBUF_CUSTOM_VTABLE
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  static void SharedDtor(MessageLite& self);
  void InternalSwap(Exit* other);
 private:
  template <typename T>
  friend ::absl::string_view(
      ::google::protobuf::internal::GetAnyMessageName)();
  static ::absl::string_view FullMessageName() { return "ConnectMsg.Exit"; }

 protected:
  explicit Exit(::google::protobuf::Arena* arena);
  Exit(::google::protobuf::Arena* arena, const Exit& from);
  Exit(::google::protobuf::Arena* arena, Exit&& from) noexcept
      : Exit(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::internal::ClassData* GetClassData() const PROTOBUF_FINAL;
  static void* PlacementNew_(const void*, void* mem,
                             ::google::protobuf::Arena* arena);
  static constexpr auto InternalNewImpl_();
  static const ::google::protobuf::internal::ClassDataFull _class_data_;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kSerialnumberFieldNumber = 1,
  };
  // optional int32 serialnumber = 1;
  bool has_serialnumber() const;
  void clear_serialnumber() ;
  ::int32_t serialnumber() const;
  void set_serialnumber(::int32_t value);

  private:
  ::int32_t _internal_serialnumber() const;
  void _internal_set_serialnumber(::int32_t value);

  public:
  // @@protoc_insertion_point(class_scope:ConnectMsg.Exit)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 0,
      0, 2>
      _table_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const Exit& from_msg);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    ::google::protobuf::internal::CachedSize _cached_size_;
    ::int32_t serialnumber_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Connect_2eproto;
};
// -------------------------------------------------------------------

class EnterAccept final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:ConnectMsg.EnterAccept) */ {
 public:
  inline EnterAccept() : EnterAccept(nullptr) {}
  ~EnterAccept() PROTOBUF_FINAL;

#if defined(PROTOBUF_CUSTOM_VTABLE)
  void operator delete(EnterAccept* msg, std::destroying_delete_t) {
    SharedDtor(*msg);
    ::google::protobuf::internal::SizedDelete(msg, sizeof(EnterAccept));
  }
#endif

  template <typename = void>
  explicit PROTOBUF_CONSTEXPR EnterAccept(
      ::google::protobuf::internal::ConstantInitialized);

  inline EnterAccept(const EnterAccept& from) : EnterAccept(nullptr, from) {}
  inline EnterAccept(EnterAccept&& from) noexcept
      : EnterAccept(nullptr, std::move(from)) {}
  inline EnterAccept& operator=(const EnterAccept& from) {
    CopyFrom(from);
    return *this;
  }
  inline EnterAccept& operator=(EnterAccept&& from) noexcept {
    if (this == &from) return *this;
    if (::google::protobuf::internal::CanMoveWithInternalSwap(GetArena(), from.GetArena())) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const EnterAccept& default_instance() {
    return *internal_default_instance();
  }
  static inline const EnterAccept* internal_default_instance() {
    return reinterpret_cast<const EnterAccept*>(
        &_EnterAccept_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(EnterAccept& a, EnterAccept& b) { a.Swap(&b); }
  inline void Swap(EnterAccept* other) {
    if (other == this) return;
    if (::google::protobuf::internal::CanUseInternalSwap(GetArena(), other->GetArena())) {
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(EnterAccept* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  EnterAccept* New(::google::protobuf::Arena* arena = nullptr) const {
    return ::google::protobuf::Message::DefaultConstruct<EnterAccept>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const EnterAccept& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const EnterAccept& from) { EnterAccept::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() PROTOBUF_FINAL;
  #if defined(PROTOBUF_CUSTOM_VTABLE)
  private:
  static ::size_t ByteSizeLong(const ::google::protobuf::MessageLite& msg);
  static ::uint8_t* _InternalSerialize(
      const MessageLite& msg, ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream);

  public:
  ::size_t ByteSizeLong() const { return ByteSizeLong(*this); }
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const {
    return _InternalSerialize(*this, target, stream);
  }
  #else   // PROTOBUF_CUSTOM_VTABLE
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  #endif  // PROTOBUF_CUSTOM_VTABLE
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  static void SharedDtor(MessageLite& self);
  void InternalSwap(EnterAccept* other);
 private:
  template <typename T>
  friend ::absl::string_view(
      ::google::protobuf::internal::GetAnyMessageName)();
  static ::absl::string_view FullMessageName() { return "ConnectMsg.EnterAccept"; }

 protected:
  explicit EnterAccept(::google::protobuf::Arena* arena);
  EnterAccept(::google::protobuf::Arena* arena, const EnterAccept& from);
  EnterAccept(::google::protobuf::Arena* arena, EnterAccept&& from) noexcept
      : EnterAccept(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::internal::ClassData* GetClassData() const PROTOBUF_FINAL;
  static void* PlacementNew_(const void*, void* mem,
                             ::google::protobuf::Arena* arena);
  static constexpr auto InternalNewImpl_();
  static const ::google::protobuf::internal::ClassDataFull _class_data_;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kGrantnumberFieldNumber = 1,
  };
  // optional int32 grantnumber = 1;
  bool has_grantnumber() const;
  void clear_grantnumber() ;
  ::int32_t grantnumber() const;
  void set_grantnumber(::int32_t value);

  private:
  ::int32_t _internal_grantnumber() const;
  void _internal_set_grantnumber(::int32_t value);

  public:
  // @@protoc_insertion_point(class_scope:ConnectMsg.EnterAccept)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 0,
      0, 2>
      _table_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const EnterAccept& from_msg);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    ::google::protobuf::internal::CachedSize _cached_size_;
    ::int32_t grantnumber_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Connect_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// EnterAccept

// optional int32 grantnumber = 1;
inline bool EnterAccept::has_grantnumber() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void EnterAccept::clear_grantnumber() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.grantnumber_ = 0;
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline ::int32_t EnterAccept::grantnumber() const {
  // @@protoc_insertion_point(field_get:ConnectMsg.EnterAccept.grantnumber)
  return _internal_grantnumber();
}
inline void EnterAccept::set_grantnumber(::int32_t value) {
  _internal_set_grantnumber(value);
  _impl_._has_bits_[0] |= 0x00000001u;
  // @@protoc_insertion_point(field_set:ConnectMsg.EnterAccept.grantnumber)
}
inline ::int32_t EnterAccept::_internal_grantnumber() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.grantnumber_;
}
inline void EnterAccept::_internal_set_grantnumber(::int32_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.grantnumber_ = value;
}

// -------------------------------------------------------------------

// SetRoomMaster

// optional int32 serialnumber = 1;
inline bool SetRoomMaster::has_serialnumber() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void SetRoomMaster::clear_serialnumber() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.serialnumber_ = 0;
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline ::int32_t SetRoomMaster::serialnumber() const {
  // @@protoc_insertion_point(field_get:ConnectMsg.SetRoomMaster.serialnumber)
  return _internal_serialnumber();
}
inline void SetRoomMaster::set_serialnumber(::int32_t value) {
  _internal_set_serialnumber(value);
  _impl_._has_bits_[0] |= 0x00000001u;
  // @@protoc_insertion_point(field_set:ConnectMsg.SetRoomMaster.serialnumber)
}
inline ::int32_t SetRoomMaster::_internal_serialnumber() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.serialnumber_;
}
inline void SetRoomMaster::_internal_set_serialnumber(::int32_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.serialnumber_ = value;
}

// -------------------------------------------------------------------

// Exit

// optional int32 serialnumber = 1;
inline bool Exit::has_serialnumber() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void Exit::clear_serialnumber() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.serialnumber_ = 0;
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline ::int32_t Exit::serialnumber() const {
  // @@protoc_insertion_point(field_get:ConnectMsg.Exit.serialnumber)
  return _internal_serialnumber();
}
inline void Exit::set_serialnumber(::int32_t value) {
  _internal_set_serialnumber(value);
  _impl_._has_bits_[0] |= 0x00000001u;
  // @@protoc_insertion_point(field_set:ConnectMsg.Exit.serialnumber)
}
inline ::int32_t Exit::_internal_serialnumber() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.serialnumber_;
}
inline void Exit::_internal_set_serialnumber(::int32_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.serialnumber_ = value;
}

// -------------------------------------------------------------------

// SyncPlayer

// optional int32 serialnumber = 1;
inline bool SyncPlayer::has_serialnumber() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void SyncPlayer::clear_serialnumber() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.serialnumber_ = 0;
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline ::int32_t SyncPlayer::serialnumber() const {
  // @@protoc_insertion_point(field_get:ConnectMsg.SyncPlayer.serialnumber)
  return _internal_serialnumber();
}
inline void SyncPlayer::set_serialnumber(::int32_t value) {
  _internal_set_serialnumber(value);
  _impl_._has_bits_[0] |= 0x00000001u;
  // @@protoc_insertion_point(field_set:ConnectMsg.SyncPlayer.serialnumber)
}
inline ::int32_t SyncPlayer::_internal_serialnumber() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.serialnumber_;
}
inline void SyncPlayer::_internal_set_serialnumber(::int32_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.serialnumber_ = value;
}

// optional float x = 2;
inline bool SyncPlayer::has_x() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline void SyncPlayer::clear_x() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.x_ = 0;
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline float SyncPlayer::x() const {
  // @@protoc_insertion_point(field_get:ConnectMsg.SyncPlayer.x)
  return _internal_x();
}
inline void SyncPlayer::set_x(float value) {
  _internal_set_x(value);
  _impl_._has_bits_[0] |= 0x00000002u;
  // @@protoc_insertion_point(field_set:ConnectMsg.SyncPlayer.x)
}
inline float SyncPlayer::_internal_x() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.x_;
}
inline void SyncPlayer::_internal_set_x(float value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.x_ = value;
}

// optional float y = 3;
inline bool SyncPlayer::has_y() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline void SyncPlayer::clear_y() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.y_ = 0;
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline float SyncPlayer::y() const {
  // @@protoc_insertion_point(field_get:ConnectMsg.SyncPlayer.y)
  return _internal_y();
}
inline void SyncPlayer::set_y(float value) {
  _internal_set_y(value);
  _impl_._has_bits_[0] |= 0x00000004u;
  // @@protoc_insertion_point(field_set:ConnectMsg.SyncPlayer.y)
}
inline float SyncPlayer::_internal_y() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.y_;
}
inline void SyncPlayer::_internal_set_y(float value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.y_ = value;
}

// optional float z = 4;
inline bool SyncPlayer::has_z() const {
  bool value = (_impl_._has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline void SyncPlayer::clear_z() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.z_ = 0;
  _impl_._has_bits_[0] &= ~0x00000008u;
}
inline float SyncPlayer::z() const {
  // @@protoc_insertion_point(field_get:ConnectMsg.SyncPlayer.z)
  return _internal_z();
}
inline void SyncPlayer::set_z(float value) {
  _internal_set_z(value);
  _impl_._has_bits_[0] |= 0x00000008u;
  // @@protoc_insertion_point(field_set:ConnectMsg.SyncPlayer.z)
}
inline float SyncPlayer::_internal_z() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.z_;
}
inline void SyncPlayer::_internal_set_z(float value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.z_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace ConnectMsg


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // Connect_2eproto_2epb_2eh
