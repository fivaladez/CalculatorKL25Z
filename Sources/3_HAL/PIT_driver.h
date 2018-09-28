/*
 * PIT_driver.h
 *
 *  Created on: Sep 6, 2018
 *      Author: ivan_
 */

#ifndef PIT_DRIVER_H_
#define PIT_DRIVER_H_

#include "derivative.h"

#define LDVAL_1S	0X1406F3F
#define LDVAL_500MS	0xA0379F
#define LDVAL_250MS	0x501BCF
#define LDVAL_100MS	0x200B1F//Cicles to achieve 100ms
#define LDVAL_10MS	0x30D3F
#define LDVAL_1MS	0x4E1F
#define LDVAL_40US	0x347 //839

typedef enum
{
	eCHANNEL_0_PIT,
	eCHANNEL_1_PIT
}eChannelx_PIT_t;

typedef enum
{
	eNOTREADY_PIT,
	eREADY_PIT
}eState_PIT_t;

typedef uint32_t u32Time_PIT_t;

typedef struct
{
	u32Time_PIT_t u32Time_PIT;
	eChannelx_PIT_t eChannel_PIT;
	eState_PIT_t eState_PIT;
	
}sPITx_t;

eState_PIT_t efInit_PIT(u32Time_PIT_t u32Time, eChannelx_PIT_t eChannel_PIT, sPITx_t *sPitx);

eState_PIT_t efRead_PIT(sPITx_t *sPitx);

void vfEnable_PIT (sPITx_t *sPitx);
void vfDisable_PIT(sPITx_t *sPitx);

#endif /* PIT_DRIVER_H_ */
