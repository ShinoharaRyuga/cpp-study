#include <iostream>

int main()
{
	char* bmp = new char[70];
	FILE* fp = nullptr;

	fopen_s(&fp, "test.bmp", "rb");

	if (fp) {
		fread_s(bmp, 70, 70, 1, fp);
		fclose(fp);
	}

	char* p = bmp;
	char buff[3];
	buff[0] = *p; p++;
	buff[1] = *p; p++;
	buff[2] = 0;
	printf("bfType = %s", buff);

	/*char sizebuff[5];
	sizebuff[0] = *p; p++;
	sizebuff[1] = *p; p++;
	sizebuff[2] = *p; p++;
	sizebuff[3] = *p; p++;
	sizebuff[4] = 0;*/

	int* size = (int*)*p;

	printf("\n");
	printf("\nbfSize = %d", size);
}
