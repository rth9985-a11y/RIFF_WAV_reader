#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>
#include "WAVHeader.h"
#include <cstring>

int main() {

    riffChunk riff;
    formatChunk format;
    dataChunk data;

    // File name variables as string
    std::string fileName;
    // User input for file to open
    std::cout << "What file would you like to look at?\n"
                << "(Please format it as my_file.wav): ";
    std::cin >> fileName;
    std::ifstream inFile(fileName, std::ios::binary);

    /*
     *  Can set up output WAV file is you want
     *  Do this if you want to process audio to another WAV file
     *  Cannot do real time processing with this
     */

    //std::ofstream outFile("output.wav", std::ios::binary);

    if (!inFile.is_open()) {
        std::cout << "This file does not exist or cannot be found\n"
                     "*** Make sure the file is in the current directory ***"
                    << std::endl;
        return 1;
    }

    inFile.read(reinterpret_cast<char*>(&riff), sizeof(riffChunk));

    std::cout << "Chunk ID: " << std::string (riff.chunkID, 4) << "\n";
    std::cout << "Chunk size: " << riff.chunkSize << "\n";
    std::cout << "Format: " << std::string (riff.format, 4) << "\n";

    inFile.read(reinterpret_cast<char*>(&format), sizeof(formatChunk));

    std::cout << "Sub chunk 1 ID: " << std::string (format.subChunk1Id, 4) << "\n";
    std::cout << "Sub chunk 1 size: " << format.subChunk1Size;
    std::cout << "Audio format: " << format.audioFormat << "\n";
    std::cout << "Number of channels: " << format.numChannels << "\n";
    std::cout << "Sample rate: " << format.sampleRate << "\n";
    std::cout << "Byte rate: " << format.byteRate << "\n";
    std::cout << "Block align: " << format.blockAlign << "\n";
    std::cout << "Bits per sample: " << format.bitsPerSample << "\n";

    inFile.read(reinterpret_cast<char*>(&data), sizeof(dataChunk));

    std::cout << "Sub chunk 2 ID: " << std::string (data.subChunk2Id, 4) << "\n";
    std::cout << "Sub chunk 2 size: " << data.subChunk2Size << "\n\n";


    /*
     * Validate WAV header
    */

    bool valid = true;

    if (std::string(riff.chunkID) != "RIFF") {
        std::cout << "***INVALID FILE: Subchunk 1 must contain 'RIFF' title\n";
        valid = false;
    }
    if (std::string(riff.format) != "WAVE") {
        std::cout << "***INVALID FILE: Format must be 'WAVE'\n";
        valid = false;
    }
    if (std::string(format.subChunk1Id) != "fmt ") {
        std::cout << "***INVALID FILE: Subchunk 1 ID must be 'fmt '\n";
        valid = false;
    }
    if (format.audioFormat != 1) {
        std::cout << "***INVALID FILE: Format must be PCM ( = 1 )\n";
        valid = false;
    }
    if (std::string(data.subChunk2Id) != "data") {
        std::cout << "***INVALID FILE: Subchunk 2 ID must be 'data'\n";
        valid = false;
    }

    if (valid) {
        std::cout << "WAV file format is correct" << std::endl;
    }
    else {
        std::cout << "WAV file format is not correct or this is not a RIFF WAVE file" << std::endl;
        return 1;
    }

    return 0;
}

