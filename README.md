# Mp3-tag-reader
MP3 tag reader is a software which reads and displays MP3 (ID3) tag information from MP3 files. The software is desktop based and not web based. All operations are performed using command line interface. The application is useful to individuals who wish to view and collect mp3 tag data. This project is also extended to be a tag editor, wherein users can modify mp3 tag information.

Technologies used:
Embedded C – File operations, Pointers, Functions, Makefiles, Command line arguments, String manipulation

Key challenges & Learnings:
- To learn about audio formats, compression and ID3 tags as a metadata container in an MP3 audio file thru’ www.id3.org which is the official id3 tag standards definitions and its versions.
- To identify an ID3 using its header.
- To extract and edit the ID3 tag frames which was achieved using iterating thru’ the file and string manipulation operations.
- To extract the metadata from the tail based on tags.
