#ifndef GUARD_SAVE_H
#define GUARD_SAVE_H

struct SaveSectionLocation
{
    void *data;
    u16 size;
};

struct SaveSection
{
    u8 data[0xFF4];
    u16 id;
    u16 checksum;
    u32 security;
    u32 counter;
}; // size is 0x1000

// headless save section?
struct UnkSaveSection
{
    u8 data[0xFF4];
    u32 security;
}; // size is 0xFF8

struct SaveSectionOffsets
{
    u16 toAdd;
    u16 size;
};

// Emerald changes this definition to be the sectors per slot.
#define NUM_SECTORS_PER_SLOT 16

#define UNKNOWN_CHECK_VALUE 0x8012025

// SetDamagedSectorBits states
enum
{
    ENABLE,
    DISABLE,
    CHECK // unused
};

// Do save types
enum
{
    SAVE_NORMAL,
    SAVE_LINK,
    //EREADER_SAVE, // deprecated in Emerald
    SAVE_LINK2, // unknown 2nd link save
    SAVE_HALL_OF_FAME,
    SAVE_OVERWRITE_DIFFERENT_FILE,
    SAVE_HALL_OF_FAME_ERASE_BEFORE // unused
};

#define SECTOR_SAVE_SLOT_LENGTH 14
#define SECTOR_ID_HOF_1 28
#define SECTOR_ID_HOF_2 29
#define SECTOR_ID_TRAINER_HILL 30
#define SECTOR_ID_RECORDED_BATTLE  31
#define SECTORS_COUNT 32

extern u16 gLastWrittenSector;
extern u32 gLastSaveCounter;
extern u16 gLastKnownGoodSector;
extern u32 gDamagedSaveSectors;
extern u32 gSaveCounter;
extern struct SaveSection *gFastSaveSection;
extern u16 gUnknown_03006208;
extern u16 gSaveFileStatus;
extern void (*gGameContinueCallback)(void);
extern struct SaveSectionLocation gRamSaveSectionLocations[];
extern u16 gUnknown_03006294;

extern struct SaveSection gSaveDataBuffer;

void ClearSaveData(void);
void Save_ResetSaveCounters(void);
u8 HandleSavingData(u8 saveType);
u8 TrySavingData(u8 saveType);
bool8 sub_8153380(void);
bool8 sub_81533AC(void);
u8 sub_81533E0(void);
u8 sub_8153408(void);
u8 sub_8153430(void);
bool8 sub_8153474(void);
u8 Save_LoadGameData(u8 a1);
u16 sub_815355C(void);
u8 sub_81534D0(u8);
u8 sub_8153430(void);
bool8 sub_8153474(void);
u32 TryCopySpecialSaveSection(u8 sector, u8* dst);
u32 sub_8153634(u8 sector, u8* src);
void sub_8153688(u8 taskId);

#endif // GUARD_SAVE_H
