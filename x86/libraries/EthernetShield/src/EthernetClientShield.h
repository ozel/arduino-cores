// Modified for Intel Galileo - dino.tinitigan@intel.com

#ifndef ethernetclient_h
#define ethernetclient_h
#include "Arduino.h"	
#include "Print.h"
#include "ClientShield.h"
#include "IPAddressShield.h"

class EthernetClientShield : public ClientShield {

public:
  EthernetClientShield();
  EthernetClientShield(uint8_t sock);

  uint8_t status();
  virtual int connect(IPAddressShield ip, uint16_t port);
  virtual int connect(const char *host, uint16_t port);
  virtual size_t write(uint8_t);
  virtual size_t write(const uint8_t *buf, size_t size);
  virtual int available();
  virtual int read();
  virtual int read(uint8_t *buf, size_t size);
  virtual int peek();
  virtual void flush();
  virtual void stop();
  virtual uint8_t connected();
  virtual operator bool();
  virtual bool operator==(const EthernetClientShield&);
  virtual bool operator!=(const EthernetClientShield& rhs) { return !this->operator==(rhs); };

  friend class EthernetServerShield;
  
  using Print::write;

private:
  static uint16_t _srcport;
  uint8_t _sock;
};

#endif
