#ifndef __CLIENT_MODBUSLIB_H__
#define __CLIENT_MODBUSLIB_H__
#include <stdint.h>
#include <stdio.h>

void CRC_C(uint8_t* modbus_data_crc, uint8_t modbus_data_len_crc, uint8_t* data_low, uint8_t* data_high);
void transmit(uint8_t mode, uint8_t * data, uint8_t len,uint8_t modbus_id, uint8_t * modbus_data, uint8_t *data_transmit, uint8_t * data_transmit_lan);
void read_holding_register(uint8_t modbus_id, uint8_t * modbus_data, uint8_t modbus_data_len, uint16_t *Register, uint8_t *data_transmit, uint8_t * data_transmit_lan);
void write_single_register(uint8_t * DataInput,uint8_t *DataInputLen,uint8_t * registers, uint8_t *data_transmit, uint8_t *data_transmit_lan);
void modbus(uint8_t modbus_id, uint8_t *modbus_data, uint8_t modbus_data_len, uint16_t *Register, uint8_t *data_transmit, uint8_t *data_transmit_lan);
#endif