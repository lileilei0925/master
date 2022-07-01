#include "../inc/common_teypedef.h"
#include "../inc/common_macro.h"

/* 每个PDU的头,包含pduType，pduSize */
typedef struct
{
    uint16_t pduType; /* 0:PRACH, 1:PUSCH, 2:PUCCH, 3:SRS */
    uint16_t pduSize; /* Size of the PDU control information (in bytes). This length value includes the 4 bytes required for the PDU type and PDU size parameters */
} PduHeadInfo;

/* Slot Messages Ul_TTI.request的头,PDU信息之前的部分 */
typedef struct
{
    uint16_t sfnNum;                           /* system frame number [0: 1023] */
    uint16_t slotNum;                          /* SLOT number [0: 159] */
    uint16_t pduNum;                           /* Number of PDUs that are included in this message */
    uint8_t  ulPduTypes;                       /* Maximum number of UL PDU types supported by UL_TTI.request */
    uint16_t pduNumPerType[MAX_UL_PDU_TYPES];  /* Number of PDUs of each type that are included in this message,nUlPduTypes = 5 */
    uint8_t  ueGroupNum;                       /* Number of UE Groups included in this message */
} UlTtiRequestHeadInfo;

/* UeGroupInfo,包含ue数和每个ue对应得pduIndex */
typedef struct
{
    uint8_t ueNum;           /* Number of UE in this group For SU-MIMO, one group includes one UE only. For MU-MIMO, one group includes up to 12 UEs */
    uint8_t pduIdx[];        /* This value is an index for number of PDU identified by nPDU in this message */
} UeGoupNumInfo;

/* UlPduMappingInfo, 用来解析pdu和ueGroup之间的对应关系 */
typedef struct 
{
    uint8_t  groupIndex;
    uint8_t  ueIndex;
    uint8_t  pduIndex;
} UlPduMappingInfo;

/* P7 Prach slot messages local structure*/
typedef struct 
{
    uint16_t pduIndex;
    uint16_t phyCellID;
    uint8_t  prachTdOcasNum;
    uint8_t  prachFormat;
    uint8_t  PrachFdmIndex; /* Frequency domain occasion index :msg1-FDM*/     
    uint8_t  prachStartSymb;/* Starting symbol for the first PRACH TD occasion in the current PRACH FD occasion */
    uint16_t ncsValue;      /* Zero-correlation zone configuration number */

    uint32_t handle;
    uint8_t  prachCfgScope;/* 0: for PHY ID 0; 1: for current PHY ID */
    uint16_t prachResCfgIndex;/* The PRACH configuration for which this PRACH PDU is signaled  */
    uint8_t  prachFdmNum;  /* Number of frequency domain occasions,starting with PrachFdmIndex */
    uint8_t  startPreambleIndex;
    uint8_t  preambleIndicesNum;

    uint8_t  trpScheme; /* This field shall be set to 0, to identify that this table is used */
    uint16_t prgNum;
    uint16_t prgSize;
    uint8_t  digitalBfNum;/* Number of logical antenna ports */
    uint16_t beamIndex[MAX_PRG_NUM][MAX_BF_PORT];
} L1PrachPduParaInfo;

typedef struct 
{
    uint16_t sfnNum;        /* system frame number [0: 1023] */
    uint16_t slotNum;       /* SLOT number [0: 159] */
    uint16_t prachPduNum;   /* Number of PrachPdus that are parse from FAPI UlTTIRequset */
    
} L12PrachPduParaInfo;


# if 0
/* PrachLowPhyPara structure: prach LowphyPara config para */
typedef struct
{
    uint16_t sfnNum;         /* system frame number [0: 1023] */
    uint16_t slotNum;        /* slot number [0: 159]  */
    uint16_t cellIndex;      /* */
    uint8_t  antNum;         /* */
    uint16_t fftSizeIndex;   /* */     
    uint8_t  prachFeEn;      /* 是否启动PrachLowphy处理标志 */
    uint16_t bwpStart;       /* */
    uint16_t bwpSize;
    uint8_t  sampleRate;
    uint8_t  ulBwpPuschScs;
    uint8_t  prachSubScs;
    uint8_t  nRaRB;
    uint8_t  kBar;
    uint8_t  nRaStart;
    uint8_t  indexFdRa;
    uint16_t freqShiftValue;
} PrachLowPhyPara;
#endif

/* P7 Pusch slot messages local structure*/
typedef struct 
{
 /*data info*/
} PuschPduParaInfo;

/* P7 Pucch slot messages local structure*/
typedef struct 
{
 /*data info*/
} PucchPduParaInfo;

/* P7 Srs slot messages local structure*/
typedef struct 
{
 /*data info*/
} SrsPduParaInfo;