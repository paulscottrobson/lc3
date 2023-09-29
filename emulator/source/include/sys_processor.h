// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		sys_processor.h
//		Purpose:	Processor Emulation (header)
//		Created:	8th October 2021
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#ifndef _PROCESSOR_H
#define _PROCESSOR_H

#define CYCLE_RATE 		(3580*1000)													// Cycles per second (3.58Mhz)

#define RAMSIZE 		(0x10000)													// Max memory in PC version (including ROM space)

typedef unsigned short WORD16;														// 8 and 16 bit types.
typedef unsigned char  BYTE8;
typedef unsigned int   LONG32;														// 32 bit type.

#define DEFAULT_BUS_VALUE (0xFF)													// What's on the bus if it's not memory.

#define AKEY_BACKSPACE	(0x5F)														// Apple Backspace

void CPUReset(void);
int CPUExecuteInstruction(void);
BYTE8 CPUWriteKeyboard(BYTE8 pattern);
BYTE8 CPUReadMemory(WORD16 address);
BYTE8 CPUReadCharacterROM(int ch,int row);
void CPUWriteMemory(WORD16 address,BYTE8 data);
int CPUGetCycles(void);
void CPUSetPC(WORD16 newPC);

#ifdef INCLUDE_DEBUGGING_SUPPORT													// Only required for debugging

typedef struct __CPUSTATUS {
	int AF,BC,DE,HL;
	int AFalt,BCalt,DEalt,HLalt;
	int IE,PC,SP,IX,IY,cycles;
} CPUSTATUS;

CPUSTATUS *CPUGetStatus(void);
int CPUExecute(WORD16 breakPoint1,WORD16 breakPoint2);
WORD16 CPUGetStepOverBreakpoint(void);
void CPUEndRun(void);
void CPULoadBinary(int argc,char *argv[]);
void CPUExit(void);

#endif
#endif