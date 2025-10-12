# RIFF_WAV_reader
Foundational program that parses over RIFF style WAV, checks validity, and outputs data to console. 

NOTE: 
      !!! This file only works for RIFF files !!!
      - Compressed and RF64 files will not work
      - Binary alignment will be wonky if so...
      - Working on expanding this to more file types

USE:  
      - WAV file must be in working directory
      - Console will prompt for the file name (make sure to type it out precisely with no spaces)
          - Will make sure to add formatting checks etc...
      - Console will output the size and attributes of the file

IN DEVELOPMENT:
      - Recognizing and parsing various compressed and RF64 type files upon input
      - Block for PCM data processing to a new WAV file
          - (e.g. simple gain, delay, reverb, distortion, etc...)
      - Real time processing of chosen WAV file
          - (e.g. include API to allow audio out, adjustable sample rate, adjustable bit rate/size)

