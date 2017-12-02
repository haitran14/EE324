#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

#include <stdint.h>

#define HELLO_FROM_CHILD        0x00000010
#define HELLO_FROM_SUPER        0x00000011
#define HELLO_SUPER_TO_SUPER    0x00000012
#define FILE_INFO               0x00000020
#define FILE_INTO_RECV_SUCCESS  0x00000021
#define FILE_INFO_RECV_ERROR    0x00000022
#define SEARCH_QUERY            0x00000030
#define SEARCH_ANS_SUCCESS      0x00000031
#define SEARCH_ANS_FAIL         0x00000032
#define FILE_REQ                0x00000040
#define FILE_RES_SUCCESS        0x00000041
#define FILE_RES_FAIL           0x00000042
#define FILE_INFO_SHARE         0x00000050
#define FILE_INFO_SHARE_SUCCESS 0x00000051
#define FILE_INFO_SHARE_FAIL    0x00000052

#define DATA_SIZE       5000
#define HEADER_LENGTH   12
#define MAX_FILES       10

typedef struct headerPkt {
    uint32_t pktLen;
    uint32_t id;
    uint32_t msgType;
} headerPkt;

typedef struct helloFromChildPkt {
    headerPkt hdr;
    unsigned int portNum;
} helloFromChildPkt;

typedef struct fileInformation {
    char fileName[256];
    unsigned int fileSize;
} fileInformation;

typedef struct fileInfoPkt {
    headerPkt hdr;
    unsigned int fileNumber;
    fileInformation files[MAX_FILES];
} fileInfoPkt;

typedef struct fileInfoRecvSuccessPkt {
    headerPkt hdr;
    unsigned int fileNumber;
    char fileNames[MAX_FILES][256];
} fileInfoRecvSuccessPkt;

typedef struct searchQueryPkt {
    headerPkt hdr;
    char fileName[256];
} searchQueryPkt;

typedef struct searchAnsSuccessPkt {
    headerPkt hdr;
    char ipAddr[20];
    unsigned int portNum;
} searchAnsSuccessPkt;

typedef struct fileReqPkt {
    headerPkt hdr;
    char fileName[256];
} fileReqPkt;

typedef struct fileResSuccessPkt {
    headerPkt hdr;
    uint8_t data[DATA_SIZE];
} fileResSuccessPkt;

typedef struct fileInfoSharePkt {
    headerPkt hdr;
    unsigned int fileNumber;
    fileInformation files[MAX_FILES];
} fileInfoSharePkt;

typedef struct fileInfoShareSuccessPkt {
    headerPkt hdr;
    unsigned int fileNumber;
    fileInformation files[MAX_FILES];
} fileInfoShareSuccessPkt;

#endif  /*__PROTOCOL_H__*/
