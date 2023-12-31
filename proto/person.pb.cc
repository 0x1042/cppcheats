// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: person.proto

#include "person.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace tutorial {
PROTOBUF_CONSTEXPR PhoneNumber::PhoneNumber(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.number_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.pt_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct PhoneNumberDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PhoneNumberDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~PhoneNumberDefaultTypeInternal() {}
  union {
    PhoneNumber _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PhoneNumberDefaultTypeInternal _PhoneNumber_default_instance_;
PROTOBUF_CONSTEXPR Person_ExtrasEntry_DoNotUse::Person_ExtrasEntry_DoNotUse(
    ::_pbi::ConstantInitialized) {}
struct Person_ExtrasEntry_DoNotUseDefaultTypeInternal {
  PROTOBUF_CONSTEXPR Person_ExtrasEntry_DoNotUseDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~Person_ExtrasEntry_DoNotUseDefaultTypeInternal() {}
  union {
    Person_ExtrasEntry_DoNotUse _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 Person_ExtrasEntry_DoNotUseDefaultTypeInternal _Person_ExtrasEntry_DoNotUse_default_instance_;
PROTOBUF_CONSTEXPR Person::Person(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.numbers_)*/{}
  , /*decltype(_impl_.extras_)*/{::_pbi::ConstantInitialized()}
  , /*decltype(_impl_.name_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.email_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.id_)*/0
  , /*decltype(_impl_.age_)*/0u
  , /*decltype(_impl_.gender_)*/0
  , /*decltype(_impl_.role_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct PersonDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PersonDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~PersonDefaultTypeInternal() {}
  union {
    Person _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PersonDefaultTypeInternal _Person_default_instance_;
}  // namespace tutorial
static ::_pb::Metadata file_level_metadata_person_2eproto[3];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_person_2eproto[3];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_person_2eproto = nullptr;

const uint32_t TableStruct_person_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::tutorial::PhoneNumber, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::tutorial::PhoneNumber, _impl_.number_),
  PROTOBUF_FIELD_OFFSET(::tutorial::PhoneNumber, _impl_.pt_),
  PROTOBUF_FIELD_OFFSET(::tutorial::Person_ExtrasEntry_DoNotUse, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::tutorial::Person_ExtrasEntry_DoNotUse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::tutorial::Person_ExtrasEntry_DoNotUse, key_),
  PROTOBUF_FIELD_OFFSET(::tutorial::Person_ExtrasEntry_DoNotUse, value_),
  0,
  1,
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::tutorial::Person, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::tutorial::Person, _impl_.id_),
  PROTOBUF_FIELD_OFFSET(::tutorial::Person, _impl_.name_),
  PROTOBUF_FIELD_OFFSET(::tutorial::Person, _impl_.email_),
  PROTOBUF_FIELD_OFFSET(::tutorial::Person, _impl_.age_),
  PROTOBUF_FIELD_OFFSET(::tutorial::Person, _impl_.numbers_),
  PROTOBUF_FIELD_OFFSET(::tutorial::Person, _impl_.gender_),
  PROTOBUF_FIELD_OFFSET(::tutorial::Person, _impl_.role_),
  PROTOBUF_FIELD_OFFSET(::tutorial::Person, _impl_.extras_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::tutorial::PhoneNumber)},
  { 8, 16, -1, sizeof(::tutorial::Person_ExtrasEntry_DoNotUse)},
  { 18, -1, -1, sizeof(::tutorial::Person)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::tutorial::_PhoneNumber_default_instance_._instance,
  &::tutorial::_Person_ExtrasEntry_DoNotUse_default_instance_._instance,
  &::tutorial::_Person_default_instance_._instance,
};

const char descriptor_table_protodef_person_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\014person.proto\022\010tutorial\">\n\013PhoneNumber\022"
  "\016\n\006number\030\001 \001(\t\022\037\n\002pt\030\002 \001(\0162\023.tutorial.P"
  "honeType\"\203\002\n\006Person\022\n\n\002id\030\001 \001(\005\022\014\n\004name\030"
  "\002 \001(\t\022\r\n\005email\030\003 \001(\t\022\013\n\003age\030\004 \001(\r\022&\n\007num"
  "bers\030\005 \003(\0132\025.tutorial.PhoneNumber\022 \n\006gen"
  "der\030\006 \001(\0162\020.tutorial.Gender\022\034\n\004role\030\007 \001("
  "\0162\016.tutorial.Role\022,\n\006extras\030d \003(\0132\034.tuto"
  "rial.Person.ExtrasEntry\032-\n\013ExtrasEntry\022\013"
  "\n\003key\030\001 \001(\t\022\r\n\005value\030\002 \001(\t:\0028\001*+\n\tPhoneT"
  "ype\022\n\n\006MOBILE\020\000\022\010\n\004HOME\020\001\022\010\n\004WORK\020\002*+\n\006G"
  "ender\022\013\n\007UNKNOWN\020\000\022\010\n\004MALE\020\001\022\n\n\006FEMALE\020\002"
  "*!\n\004Role\022\014\n\010CIVILIAN\020\000\022\013\n\007SOLDIER\020\001B\006\200\001\001"
  "\370\001\001b\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_person_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_person_2eproto = {
    false, false, 491, descriptor_table_protodef_person_2eproto,
    "person.proto",
    &descriptor_table_person_2eproto_once, nullptr, 0, 3,
    schemas, file_default_instances, TableStruct_person_2eproto::offsets,
    file_level_metadata_person_2eproto, file_level_enum_descriptors_person_2eproto,
    file_level_service_descriptors_person_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_person_2eproto_getter() {
  return &descriptor_table_person_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_person_2eproto(&descriptor_table_person_2eproto);
namespace tutorial {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* PhoneType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_person_2eproto);
  return file_level_enum_descriptors_person_2eproto[0];
}
bool PhoneType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Gender_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_person_2eproto);
  return file_level_enum_descriptors_person_2eproto[1];
}
bool Gender_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Role_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_person_2eproto);
  return file_level_enum_descriptors_person_2eproto[2];
}
bool Role_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}


// ===================================================================

class PhoneNumber::_Internal {
 public:
};

PhoneNumber::PhoneNumber(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:tutorial.PhoneNumber)
}
PhoneNumber::PhoneNumber(const PhoneNumber& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  PhoneNumber* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.number_){}
    , decltype(_impl_.pt_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.number_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.number_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_number().empty()) {
    _this->_impl_.number_.Set(from._internal_number(), 
      _this->GetArenaForAllocation());
  }
  _this->_impl_.pt_ = from._impl_.pt_;
  // @@protoc_insertion_point(copy_constructor:tutorial.PhoneNumber)
}

inline void PhoneNumber::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.number_){}
    , decltype(_impl_.pt_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.number_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.number_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

PhoneNumber::~PhoneNumber() {
  // @@protoc_insertion_point(destructor:tutorial.PhoneNumber)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void PhoneNumber::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.number_.Destroy();
}

void PhoneNumber::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void PhoneNumber::Clear() {
// @@protoc_insertion_point(message_clear_start:tutorial.PhoneNumber)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.number_.ClearToEmpty();
  _impl_.pt_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* PhoneNumber::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string number = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_number();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "tutorial.PhoneNumber.number"));
        } else
          goto handle_unusual;
        continue;
      // .tutorial.PhoneType pt = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_pt(static_cast<::tutorial::PhoneType>(val));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* PhoneNumber::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:tutorial.PhoneNumber)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string number = 1;
  if (!this->_internal_number().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_number().data(), static_cast<int>(this->_internal_number().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "tutorial.PhoneNumber.number");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_number(), target);
  }

  // .tutorial.PhoneType pt = 2;
  if (this->_internal_pt() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      2, this->_internal_pt(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:tutorial.PhoneNumber)
  return target;
}

size_t PhoneNumber::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tutorial.PhoneNumber)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string number = 1;
  if (!this->_internal_number().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_number());
  }

  // .tutorial.PhoneType pt = 2;
  if (this->_internal_pt() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_pt());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData PhoneNumber::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    PhoneNumber::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*PhoneNumber::GetClassData() const { return &_class_data_; }


void PhoneNumber::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<PhoneNumber*>(&to_msg);
  auto& from = static_cast<const PhoneNumber&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:tutorial.PhoneNumber)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_number().empty()) {
    _this->_internal_set_number(from._internal_number());
  }
  if (from._internal_pt() != 0) {
    _this->_internal_set_pt(from._internal_pt());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void PhoneNumber::CopyFrom(const PhoneNumber& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tutorial.PhoneNumber)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PhoneNumber::IsInitialized() const {
  return true;
}

void PhoneNumber::InternalSwap(PhoneNumber* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.number_, lhs_arena,
      &other->_impl_.number_, rhs_arena
  );
  swap(_impl_.pt_, other->_impl_.pt_);
}

::PROTOBUF_NAMESPACE_ID::Metadata PhoneNumber::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_person_2eproto_getter, &descriptor_table_person_2eproto_once,
      file_level_metadata_person_2eproto[0]);
}

// ===================================================================

Person_ExtrasEntry_DoNotUse::Person_ExtrasEntry_DoNotUse() {}
Person_ExtrasEntry_DoNotUse::Person_ExtrasEntry_DoNotUse(::PROTOBUF_NAMESPACE_ID::Arena* arena)
    : SuperType(arena) {}
void Person_ExtrasEntry_DoNotUse::MergeFrom(const Person_ExtrasEntry_DoNotUse& other) {
  MergeFromInternal(other);
}
::PROTOBUF_NAMESPACE_ID::Metadata Person_ExtrasEntry_DoNotUse::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_person_2eproto_getter, &descriptor_table_person_2eproto_once,
      file_level_metadata_person_2eproto[1]);
}

// ===================================================================

class Person::_Internal {
 public:
};

Person::Person(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  if (arena != nullptr && !is_message_owned) {
    arena->OwnCustomDestructor(this, &Person::ArenaDtor);
  }
  // @@protoc_insertion_point(arena_constructor:tutorial.Person)
}
Person::Person(const Person& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Person* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.numbers_){from._impl_.numbers_}
    , /*decltype(_impl_.extras_)*/{}
    , decltype(_impl_.name_){}
    , decltype(_impl_.email_){}
    , decltype(_impl_.id_){}
    , decltype(_impl_.age_){}
    , decltype(_impl_.gender_){}
    , decltype(_impl_.role_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _this->_impl_.extras_.MergeFrom(from._impl_.extras_);
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_name().empty()) {
    _this->_impl_.name_.Set(from._internal_name(), 
      _this->GetArenaForAllocation());
  }
  _impl_.email_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.email_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_email().empty()) {
    _this->_impl_.email_.Set(from._internal_email(), 
      _this->GetArenaForAllocation());
  }
  ::memcpy(&_impl_.id_, &from._impl_.id_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.role_) -
    reinterpret_cast<char*>(&_impl_.id_)) + sizeof(_impl_.role_));
  // @@protoc_insertion_point(copy_constructor:tutorial.Person)
}

inline void Person::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.numbers_){arena}
    , /*decltype(_impl_.extras_)*/{::_pbi::ArenaInitialized(), arena}
    , decltype(_impl_.name_){}
    , decltype(_impl_.email_){}
    , decltype(_impl_.id_){0}
    , decltype(_impl_.age_){0u}
    , decltype(_impl_.gender_){0}
    , decltype(_impl_.role_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.email_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.email_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

Person::~Person() {
  // @@protoc_insertion_point(destructor:tutorial.Person)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    ArenaDtor(this);
    return;
  }
  SharedDtor();
}

inline void Person::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.numbers_.~RepeatedPtrField();
  _impl_.extras_.Destruct();
  _impl_.extras_.~MapField();
  _impl_.name_.Destroy();
  _impl_.email_.Destroy();
}

void Person::ArenaDtor(void* object) {
  Person* _this = reinterpret_cast< Person* >(object);
  _this->_impl_.extras_.Destruct();
}
void Person::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Person::Clear() {
// @@protoc_insertion_point(message_clear_start:tutorial.Person)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.numbers_.Clear();
  _impl_.extras_.Clear();
  _impl_.name_.ClearToEmpty();
  _impl_.email_.ClearToEmpty();
  ::memset(&_impl_.id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.role_) -
      reinterpret_cast<char*>(&_impl_.id_)) + sizeof(_impl_.role_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Person::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string name = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "tutorial.Person.name"));
        } else
          goto handle_unusual;
        continue;
      // string email = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_email();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "tutorial.Person.email"));
        } else
          goto handle_unusual;
        continue;
      // uint32 age = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          _impl_.age_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated .tutorial.PhoneNumber numbers = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 42)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_numbers(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<42>(ptr));
        } else
          goto handle_unusual;
        continue;
      // .tutorial.Gender gender = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 48)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_gender(static_cast<::tutorial::Gender>(val));
        } else
          goto handle_unusual;
        continue;
      // .tutorial.Role role = 7;
      case 7:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 56)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_role(static_cast<::tutorial::Role>(val));
        } else
          goto handle_unusual;
        continue;
      // map<string, string> extras = 100;
      case 100:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          ptr -= 2;
          do {
            ptr += 2;
            ptr = ctx->ParseMessage(&_impl_.extras_, ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<802>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Person::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:tutorial.Person)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 id = 1;
  if (this->_internal_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_id(), target);
  }

  // string name = 2;
  if (!this->_internal_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "tutorial.Person.name");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_name(), target);
  }

  // string email = 3;
  if (!this->_internal_email().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_email().data(), static_cast<int>(this->_internal_email().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "tutorial.Person.email");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_email(), target);
  }

  // uint32 age = 4;
  if (this->_internal_age() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(4, this->_internal_age(), target);
  }

  // repeated .tutorial.PhoneNumber numbers = 5;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_numbers_size()); i < n; i++) {
    const auto& repfield = this->_internal_numbers(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(5, repfield, repfield.GetCachedSize(), target, stream);
  }

  // .tutorial.Gender gender = 6;
  if (this->_internal_gender() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      6, this->_internal_gender(), target);
  }

  // .tutorial.Role role = 7;
  if (this->_internal_role() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      7, this->_internal_role(), target);
  }

  // map<string, string> extras = 100;
  if (!this->_internal_extras().empty()) {
    using MapType = ::_pb::Map<std::string, std::string>;
    using WireHelper = Person_ExtrasEntry_DoNotUse::Funcs;
    const auto& map_field = this->_internal_extras();
    auto check_utf8 = [](const MapType::value_type& entry) {
      (void)entry;
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
        entry.first.data(), static_cast<int>(entry.first.length()),
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
        "tutorial.Person.ExtrasEntry.key");
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
        entry.second.data(), static_cast<int>(entry.second.length()),
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
        "tutorial.Person.ExtrasEntry.value");
    };

    if (stream->IsSerializationDeterministic() && map_field.size() > 1) {
      for (const auto& entry : ::_pbi::MapSorterPtr<MapType>(map_field)) {
        target = WireHelper::InternalSerialize(100, entry.first, entry.second, target, stream);
        check_utf8(entry);
      }
    } else {
      for (const auto& entry : map_field) {
        target = WireHelper::InternalSerialize(100, entry.first, entry.second, target, stream);
        check_utf8(entry);
      }
    }
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:tutorial.Person)
  return target;
}

size_t Person::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tutorial.Person)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .tutorial.PhoneNumber numbers = 5;
  total_size += 1UL * this->_internal_numbers_size();
  for (const auto& msg : this->_impl_.numbers_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // map<string, string> extras = 100;
  total_size += 2 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(this->_internal_extras_size());
  for (::PROTOBUF_NAMESPACE_ID::Map< std::string, std::string >::const_iterator
      it = this->_internal_extras().begin();
      it != this->_internal_extras().end(); ++it) {
    total_size += Person_ExtrasEntry_DoNotUse::Funcs::ByteSizeLong(it->first, it->second);
  }

  // string name = 2;
  if (!this->_internal_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // string email = 3;
  if (!this->_internal_email().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_email());
  }

  // int32 id = 1;
  if (this->_internal_id() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_id());
  }

  // uint32 age = 4;
  if (this->_internal_age() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_age());
  }

  // .tutorial.Gender gender = 6;
  if (this->_internal_gender() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_gender());
  }

  // .tutorial.Role role = 7;
  if (this->_internal_role() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_role());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Person::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Person::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Person::GetClassData() const { return &_class_data_; }


void Person::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Person*>(&to_msg);
  auto& from = static_cast<const Person&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:tutorial.Person)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.numbers_.MergeFrom(from._impl_.numbers_);
  _this->_impl_.extras_.MergeFrom(from._impl_.extras_);
  if (!from._internal_name().empty()) {
    _this->_internal_set_name(from._internal_name());
  }
  if (!from._internal_email().empty()) {
    _this->_internal_set_email(from._internal_email());
  }
  if (from._internal_id() != 0) {
    _this->_internal_set_id(from._internal_id());
  }
  if (from._internal_age() != 0) {
    _this->_internal_set_age(from._internal_age());
  }
  if (from._internal_gender() != 0) {
    _this->_internal_set_gender(from._internal_gender());
  }
  if (from._internal_role() != 0) {
    _this->_internal_set_role(from._internal_role());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Person::CopyFrom(const Person& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tutorial.Person)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Person::IsInitialized() const {
  return true;
}

void Person::InternalSwap(Person* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.numbers_.InternalSwap(&other->_impl_.numbers_);
  _impl_.extras_.InternalSwap(&other->_impl_.extras_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.name_, lhs_arena,
      &other->_impl_.name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.email_, lhs_arena,
      &other->_impl_.email_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Person, _impl_.role_)
      + sizeof(Person::_impl_.role_)
      - PROTOBUF_FIELD_OFFSET(Person, _impl_.id_)>(
          reinterpret_cast<char*>(&_impl_.id_),
          reinterpret_cast<char*>(&other->_impl_.id_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Person::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_person_2eproto_getter, &descriptor_table_person_2eproto_once,
      file_level_metadata_person_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace tutorial
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::tutorial::PhoneNumber*
Arena::CreateMaybeMessage< ::tutorial::PhoneNumber >(Arena* arena) {
  return Arena::CreateMessageInternal< ::tutorial::PhoneNumber >(arena);
}
template<> PROTOBUF_NOINLINE ::tutorial::Person_ExtrasEntry_DoNotUse*
Arena::CreateMaybeMessage< ::tutorial::Person_ExtrasEntry_DoNotUse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::tutorial::Person_ExtrasEntry_DoNotUse >(arena);
}
template<> PROTOBUF_NOINLINE ::tutorial::Person*
Arena::CreateMaybeMessage< ::tutorial::Person >(Arena* arena) {
  return Arena::CreateMessageInternal< ::tutorial::Person >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
