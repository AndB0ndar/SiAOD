#ifndef RUN_LENGTH_ENCODING_H
#define RUN_LENGTH_ENCODING_H

class RLE
{
public:
	const char* Encode(const char* input);
	const char* Decode(const char* input);
};

#endif
