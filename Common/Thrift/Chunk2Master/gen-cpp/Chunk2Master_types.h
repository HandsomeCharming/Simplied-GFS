/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Chunk2Master_TYPES_H
#define Chunk2Master_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace GFS {

typedef struct _ChunkServerInfo__isset {
  _ChunkServerInfo__isset() : ipAddr(false), totalMem(false), availMem(false), availPort(false) {}
  bool ipAddr;
  bool totalMem;
  bool availMem;
  bool availPort;
} _ChunkServerInfo__isset;

class ChunkServerInfo {
 public:

  static const char* ascii_fingerprint; // = "7C36FC499DF904D899DB644F48C285E8";
  static const uint8_t binary_fingerprint[16]; // = {0x7C,0x36,0xFC,0x49,0x9D,0xF9,0x04,0xD8,0x99,0xDB,0x64,0x4F,0x48,0xC2,0x85,0xE8};

  ChunkServerInfo() : ipAddr(), totalMem(0), availMem(0) {
  }

  virtual ~ChunkServerInfo() throw() {}

  std::string ipAddr;
  int64_t totalMem;
  int64_t availMem;
  std::vector<int16_t>  availPort;

  _ChunkServerInfo__isset __isset;

  void __set_ipAddr(const std::string& val) {
    ipAddr = val;
  }

  void __set_totalMem(const int64_t val) {
    totalMem = val;
  }

  void __set_availMem(const int64_t val) {
    availMem = val;
  }

  void __set_availPort(const std::vector<int16_t> & val) {
    availPort = val;
  }

  bool operator == (const ChunkServerInfo & rhs) const
  {
    if (!(ipAddr == rhs.ipAddr))
      return false;
    if (!(totalMem == rhs.totalMem))
      return false;
    if (!(availMem == rhs.availMem))
      return false;
    if (!(availPort == rhs.availPort))
      return false;
    return true;
  }
  bool operator != (const ChunkServerInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkServerInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(ChunkServerInfo &a, ChunkServerInfo &b);

} // namespace

#endif
