#ifndef CFILEIO_H
#define CFILEIO_H


#ifndef NULL
#define NULL ((void*) 0L)
#endif

#define OPENMODE std::ios_base::openmode
#define SEEKDIR  std::ios_base::seekdir


#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <NStringTool.h>
#include <EFileTypes.h>


enum EFileAttribut
{
	EFA_NOT_FOUND,
	EFA_FILE,
	EFA_FOLDER
};

class CFileIO
{
	public:

		CFileIO()
		{
			mOpenRead = false;
			mOpenWrite = false;
			mFs = NULL;
		}

		void*  ReadFile(const char* Filename, int* nBytes);
		bool   OpenFileRead(const char* Filename, OPENMODE OpenMode);
		bool   OpenFileWrite(const char*Filename, OPENMODE OpenMode);
		bool   OpenFileAppend(const char* Filename, OPENMODE OpenMode);
		bool   OpenFileChange(const char* Filename, int Position);
		bool   ReadBytes(void* buffer, int nBytes);
		void*  ReadBytes(int nBytes);
		bool   WriteBytes(const void* buffer, int nBytes);
		bool   WriteString(const char* str);
		bool   WriteFile(const char* Filename, const void* Buffer, int nBytes);
		char*  ReplaceAllStrings(char* SrcString, char* SearchString, char* SubString, int* Count);
		int    GetChar();
		bool   IsEof();
		void   Clear();
		void   SkipBytes(int nBytes);
		static EFileTypes GuessFileFormat(const char* Filename);
		static char*  ReplaceApp(const char* Filename, const char* neuApp);
		int    ReadLine(std::vector<char>* Line);
		int    ReadLine(std::string* Line);
		int    ReadSplitLine(stringvector* StringVector, char Div);
		int    WriteFromFile(const char* Filename);
		
		static std::string StripExtension(const char* FullPathName);
		static bool   ResolveWildCard(const char* Dir, const char* WildCard, stringvector* FileList);
		static char*  NewString(const char* OldStr);
		static char*  Fill0(int i, int n);
		static char*  Fill0(char* strbuffer, int i, int n);
		static bool   FileExists(const char* Filename);
		static char*  ExtractFilename(const char* FullPathName);
		static const char*  ExtractPath(const char* FullPathName);
		static bool   Strcmpx(const char* s1, const char* s2);
		static int GetFileSize(const char* Filename);



		void   DeleteStringList(char** StrList);
		std::string Fill0str(int i, int n);

		template <typename Tobject>
		bool ReadObject(Tobject* obj)
		{
			return ReadBytes(obj, sizeof(Tobject));
		}

		template <typename Tobject>
		bool WriteObject(const Tobject* obj)
		{
			return WriteBytes(obj, sizeof(Tobject));
		}

		template <typename Tobject>
		bool WriteObjectArray(const Tobject* obj, int Count)
		{
			return WriteBytes(obj, sizeof(Tobject) * Count);
		}

		bool Good()
		{
			return mFs->good();
		}


		void  CloseFile();

		bool 	SetReadPos(int pos);
		bool 	SetReadPos2(int pos, SEEKDIR where);
		int  	GetReadPos();

		int  	GetWritePos();
		void  SetWritePos(unsigned int pos);
		void 	SetWritePosEnd();



	protected:

		std::fstream* mFs;
		bool     mOpenWrite;
		bool     mOpenRead;
};

#endif
