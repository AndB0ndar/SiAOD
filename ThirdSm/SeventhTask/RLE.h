#ifndef RUN_LENGTH_ENCODING_H
#define RUN_LENGTH_ENCODING_H

class RLE
{
	double compressRatio;
public:
	const char* Encode(const char* input);
	const char* Decode(const char* input);
	double GetCompressRatio() { return compressRatio; }
};

#endif
