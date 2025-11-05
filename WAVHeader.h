#pragma once
#include <cstdint>

#pragma pack(push, 1)
struct riffChunk {   
    //"RIFF" chunk
    char chunkID[4];
    uint32_t chunkSize;
    char format[4];
};
struct formatChunk {
    // "fmt " chunk
    char subChunk1Id[4];
    uint32_t subChunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
};
struct dataChunk{
    // Data chunk
    char subChunk2Id[4];
    uint32_t subChunk2Size;
};
#pragma pack(pop)


// #endif //WAV_FILE_READER_WAVHEADER_H
