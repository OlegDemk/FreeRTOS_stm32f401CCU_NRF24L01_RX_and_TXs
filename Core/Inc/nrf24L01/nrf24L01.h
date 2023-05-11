/*
 * nrf24L01.h
 *
 *  Created on: Apr 6, 2023
 *      Author: odemki
 */

#ifndef INC_NRF24L01_NRF24L01_H_
#define INC_NRF24L01_NRF24L01_H_


#define CS_GPIO_PORT GPIOA
#define CS_PIN nrf_CS_Pin
#define CS_ON HAL_GPIO_WritePin(CS_GPIO_PORT, CS_PIN, GPIO_PIN_RESET)
#define CS_OFF HAL_GPIO_WritePin(CS_GPIO_PORT, CS_PIN, GPIO_PIN_SET)

#define CE_GPIO_PORT GPIOA
#define CE_PIN nrf_CE_Pin
#define CE_RESET HAL_GPIO_WritePin(CE_GPIO_PORT, CE_PIN, GPIO_PIN_RESET)
#define CE_SET HAL_GPIO_WritePin(CE_GPIO_PORT, CE_PIN, GPIO_PIN_SET)

#define IRQ_GPIO_PORT GPIOA
#define IRQ_PIN nrf_IRQ_Pin
#define IRQ HAL_GPIO_ReadPin(IRQ_GPIO_PORT, IRQ_PIN)

#define LED_GPIO_PORT GPIOC
#define LED_PIN LED_Pin
#define LED_ON HAL_GPIO_WritePin(LED_GPIO_PORT, LED_PIN, GPIO_PIN_RESET)
#define LED_OFF HAL_GPIO_WritePin(LED_GPIO_PORT, LED_PIN, GPIO_PIN_SET)
#define LED_TGL HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN)


#define ACTIVATE 0x50 //
#define RD_RX_PLOAD 0x61 // Define RX payload register address
#define WR_TX_PLOAD 0xA0 // Define TX payload register address
#define FLUSH_TX 0xE1
#define FLUSH_RX 0xE2

#define CONFIG 0x00 //'Config' register address
#define EN_AA 0x01 //'Enable Auto Acknowledgment' register address
#define EN_RXADDR 0x02 //'Enabled RX addresses' register address
#define SETUP_AW 0x03 //'Setup address width' register address
#define SETUP_RETR 0x04 //'Setup Auto. Retrans' register address
#define RF_CH 0x05 //'RF channel' register address
#define RF_SETUP 0x06 //'RF setup' register address
#define STATUS 0x07 //'Status' register address
#define OBSERVE_TX 0x08 //'Transmit observe' register

#define RPD 0x09		// Received Power Director

#define RX_ADDR_P0 0x0A //'RX address pipe0' register address
#define RX_ADDR_P1 0x0B //'RX address pipe1' register address
#define RX_ADDR_P2 0x0C //'RX address pipe2' register address
#define RX_ADDR_P3 0x0D //'RX address pipe3' register address
#define RX_ADDR_P4 0x0E //'RX address pipe4' register address
#define RX_ADDR_P5 0x0F //'RX address pipe5' register address


#define TX_ADDR 0x10 //'TX address' register address
#define RX_PW_P0 0x11 //'RX payload width, pipe0' register address
#define RX_PW_P1 0x12 //'RX payload width, pipe1' register address
#define RX_PW_P2 0x13 //'RX payload width, pipe2' register address
#define RX_PW_P3 0x14 //'RX payload width, pipe3' register address
#define RX_PW_P4 0x15 //'RX payload width, pipe4' register address
#define RX_PW_P5 0x16 //'RX payload width, pipe5' register address

#define FIFO_STATUS 0x17 //'FIFO Status Register' register address
#define DYNPD 0x1C
#define FEATURE 0x1D

#define PRIM_RX 0x00 //RX/TX control (1: PRX, 0: PTX)
#define PWR_UP 0x01 //1: POWER UP, 0:POWER DOWN
#define RX_DR 0x40 //Data Ready RX FIFO interrupt
#define TX_DS 0x20 //Data Sent TX FIFO interrupt
#define MAX_RT 0x10 //Maximum number of TX retransmits interrupt

#define W_REGISTER 0x20 //write in register

//////////////////////////////////////////////////
// RF_SETUP register
#define RF_SPEED_DATA_RATES_1Mbps 0x00
#define RF_SPEED_DATA_RATES_2Mbps 0x8
#define RF_SPEED_DATA_RATES_250kbps 0x32

#define RF_PWR_MINUS_18dBM 0x00
#define RF_PWR_MINUS_12dBM 0x02
#define RF_PWR_MINUS_16dBM 0x04
#define RF_PWR_MINUS_0dBM 0x06

// Retransmit delay
enum {
	nRF24_ARD_NONE   = (uint8_t)0x00, // Dummy value for case when retransmission is not used
	nRF24_ARD_250us  = (uint8_t)0x00,
	nRF24_ARD_500us  = (uint8_t)0x01,
	nRF24_ARD_750us  = (uint8_t)0x02,
	nRF24_ARD_1000us = (uint8_t)0x03,
	nRF24_ARD_1250us = (uint8_t)0x04,
	nRF24_ARD_1500us = (uint8_t)0x05,
	nRF24_ARD_1750us = (uint8_t)0x06,
	nRF24_ARD_2000us = (uint8_t)0x07,
	nRF24_ARD_2250us = (uint8_t)0x08,
	nRF24_ARD_2500us = (uint8_t)0x09,
	nRF24_ARD_2750us = (uint8_t)0x0A,
	nRF24_ARD_3000us = (uint8_t)0x0B,
	nRF24_ARD_3250us = (uint8_t)0x0C,
	nRF24_ARD_3500us = (uint8_t)0x0D,
	nRF24_ARD_3750us = (uint8_t)0x0E,
	nRF24_ARD_4000us = (uint8_t)0x0F
};

// RF retransmit attemp TX mode
enum {
	nRF24_TXARC_0 = (uint8_t)0x00,			// Re-Transmit disabled
	nRF24_TXARC_1 = (uint8_t)0x01,
	nRF24_TXARC_2 = (uint8_t)0x02,
	nRF24_TXARC_3 = (uint8_t)0x03,
	nRF24_TXARC_4 = (uint8_t)0x04,
	nRF24_TXARC_5 = (uint8_t)0x05,
	nRF24_TXARC_6 = (uint8_t)0x06,
	nRF24_TXARC_7 = (uint8_t)0x07,
	nRF24_TXARC_8 = (uint8_t)0x08,
	nRF24_TXARC_9 = (uint8_t)0x09,
	nRF24_TXARC_10 = (uint8_t)0xA,
	nRF24_TXARC_11 = (uint8_t)0xB,
	nRF24_TXARC_12 = (uint8_t)0xC,
	nRF24_TXARC_13 = (uint8_t)0xD,
	nRF24_TXARC_14 = (uint8_t)0xE,
	nRF24_TXARC_15 = (uint8_t)0xF,
};

// Data rate
enum {
	nRF24_DR_250kbps = (uint8_t)0x20, // 250kbps data rate
	nRF24_DR_1Mbps   = (uint8_t)0x00, // 1Mbps data rate
	nRF24_DR_2Mbps   = (uint8_t)0x08  // 2Mbps data rate
};

// RF output power in TX mode
enum {
	nRF24_TXPWR_18dBm = (uint8_t)0x00, // -18dBm
	nRF24_TXPWR_12dBm = (uint8_t)0x02, // -12dBm
	nRF24_TXPWR_6dBm  = (uint8_t)0x04, //  -6dBm
	nRF24_TXPWR_0dBm  = (uint8_t)0x06  //   0dBm
};



void NRF24_init_RX(uint8_t zero_pipe, uint8_t first_pipe, uint8_t second_pipe,
		uint8_t third_pipe,	uint8_t fourth_pipe, uint8_t fifth_pipe,
		uint8_t chanel, uint8_t data_rate, uint8_t output_tx_power);

void NRF24_init_TX(uint8_t pipe, uint8_t chanel, uint8_t retrans_delay, uint8_t retransmit_attempt, uint8_t data_rate, uint8_t output_tx_power);
void NRF24L01_Transmit(uint8_t *pipe_address, char *data[]);
void NRF24_Read_Buf(uint8_t addr,uint8_t *pBuf,uint8_t bytes);
uint8_t NRF24L01_Send(uint8_t *pBuf, uint8_t *pipe_address);
void NRF24L01_Receive(void);


void testReadWriteSetingd(void);
void testDelay(void);
void led_test(void);


void NRF24_init(void);

#endif /* INC_NRF24L01_NRF24L01_H_ */
