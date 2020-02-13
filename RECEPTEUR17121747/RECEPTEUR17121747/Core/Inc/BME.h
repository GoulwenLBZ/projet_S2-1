/*
 * BME.h
 *
 *  Created on: 18 oct. 2019
 *      Author: goule
 */

#ifndef BME_H_
#define BME_H_



#endif /* BME_H_ */
#include "main.h"

// Adresses possibles du capteur.
#define BME680_ADDR_GND				0x76// Quand le SDO est brancher sur le GND.
#define BME680_ADDR_VDDIO			0x77// Quand le SDO est brancher sur le VDDIO.

// Adresse utilisé.
#define BME680_ADDR 				BME680_ADDR_GND << 1 // En I2C, il faut décalé de 1 vers la gauche les adresses.

// Adresses des registres de configuration.
#define BME680_REG_CONF_TMP			0x74
#define BME680_REG_CONF_H			0x72
#define BME680_REG_CONF_F			0x75

// Données à écrire dans les registres de configuration.
#define BME680_DATA_CONF_TMP		0x55 // Correspond à ..
#define BME680_DATA_CONF_H			0x01 // Correspond à ..
#define BME680_DATA_CONF_F			0x1C // Correspond à ..

// Adresses des registres pour lecture des données température, hygrométrie et pression AT.
#define BME680_REG_TEMP_MSB			0x22
#define BME680_REG_TEMP_LSB			0x23
#define BME680_REG_TEMP_XLSB		0x24

#define BME680_REG_HYGRO_MSB		0x25
#define BME680_REG_HYGRO_LSB		0x26

#define BME680_REG_PRESS_MSB		0x1F
#define BME680_REG_PRESS_LSB		0x20
#define BME680_REG_PRESS_XLSB 		0x21

// Configuration du mode économie d'énergie
#define BME680_FORCE_MODE			0x55
#define BME680_STOP_MODE			0x54
/*
#define par_t1			26098 //26041
#define	par_t2			26610 //26469
#define	par_t3			3
#define	par_gh1			-30
#define	par_gh2			-24754
#define par_gh3			18
#define par_h1			676
#define par_h2			1029
#define par_h3			0
#define par_h4			45
#define par_h5			20
#define par_h6			120
#define par_h7			156 //-100
#define par_p1			37147 //36673
#define par_p2			55034 //-10515
#define par_p3			88
#define par_p4			7563 //7310
#define par_p5			65403 //-129
#define par_p6			30
#define par_p7			60 //46
#define par_p8			60672 //-3177
#define par_p9			63847 //-2379
#define par_p10			30
//#define t_fine			136667
*/

void confBMEI2C();
void DONNEES_BRUTES();
float Calcul_temp(double temperature_brute);
float Calcul_hygro(double hygrometrie_brute, float temperature);
float Calcul_press(float pression_brute);
void Cal_press();
void par_t();
void par_h();
void par_p();
void par_gh();

typedef struct {
	/*! Variable to store calibrated humidity data */
	uint16_t par_h1;
	/*! Variable to store calibrated humidity data */
	uint16_t par_h2;
	/*! Variable to store calibrated humidity data */
	int8_t par_h3;
	/*! Variable to store calibrated humidity data */
	int8_t par_h4;
	/*! Variable to store calibrated humidity data */
	int8_t par_h5;
	/*! Variable to store calibrated humidity data */
	uint8_t par_h6;
	/*! Variable to store calibrated humidity data */
	int8_t par_h7;
	/*! Variable to store calibrated gas data */
	int8_t par_gh1;
	/*! Variable to store calibrated gas data */
	int16_t par_gh2;
	/*! Variable to store calibrated gas data */
	int8_t par_gh3;
	/*! Variable to store calibrated temperature data */
	uint16_t par_t1;
	/*! Variable to store calibrated temperature data */
	int16_t par_t2;
	/*! Variable to store calibrated temperature data */
	int8_t par_t3;
	/*! Variable to store calibrated pressure data */
	uint16_t par_p1;
	/*! Variable to store calibrated pressure data */
	int16_t par_p2;
	/*! Variable to store calibrated pressure data */
	int8_t par_p3;
	/*! Variable to store calibrated pressure data */
	int16_t par_p4;
	/*! Variable to store calibrated pressure data */
	int16_t par_p5;
	/*! Variable to store calibrated pressure data */
	int8_t par_p6;
	/*! Variable to store calibrated pressure data */
	int8_t par_p7;
	/*! Variable to store calibrated pressure data */
	int16_t par_p8;
	/*! Variable to store calibrated pressure data */
	int16_t par_p9;
	/*! Variable to store calibrated pressure data */
	uint8_t par_p10;
}bme680_calib_data;

bme680_calib_data CALIB;


