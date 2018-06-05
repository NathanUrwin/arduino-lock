#include <RcLock.h>

RcLock rcLock();

void setup() {
}

void loop() {
  rcLock.read();
  rcLock.write();
  delay(rcLock.DELAY);
}
