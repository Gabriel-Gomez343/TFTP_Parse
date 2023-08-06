#pragma once

#include <stdbool.h>

#define BLKSIZE 512

// RRQ/WRQ packet
typedef struct {
	int opcode;
	char* filename;
	char* mode;
} RQ;

// DATA packet
typedef struct {
	int opcode;
	int block;
	char *data;
	bool last;
} DP;

// ACK packet
typedef struct {
	int opcode;
	int block;
} ACK;

// ERROR packet
typedef struct {
	int opcode;
	int error;
	char* msg;
} EP;

void handle_read_request(RQ *rrq);
void handle_write_request(RQ *wrq);
void handle_data_packet(DP *dp);
void handle_ack_packet(ACK *ack);
void handle_error_packet(EP *ep);


