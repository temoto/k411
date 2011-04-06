#ifndef HAL_PORTS_H
// Copied from dux/metodo @ http://github.com/duckinator/dux
#define HAL_PORTS_H

/* Ports */
void HalOutPort(uint16_t port, uint8_t val);
uint8_t HalInPort(uint16_t port);
void HalOutPortWord(uint16_t port, uint16_t val);
uint16_t HalInPortWord(uint16_t port);
void HalOutPortLong(uint16_t port, uint32_t val);
uint32_t HalInPortLong(uint16_t port);

void HalIOWait(void);

#endif /* end of include guard: HAL_PORTS_H */
