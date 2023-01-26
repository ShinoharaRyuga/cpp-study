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

	// ファイルタイプ　通常は'BM'
	char* p = bmp;
	char buff[3];
	buff[0] = *p; p++;
	buff[1] = *p; p++;
	buff[2] = 0;
	printf("bfType = %s", buff);

	//ファイルサイズ取得
	int* size = (int*)*p; p += 4;
	printf("\n");
	printf("\nbfSize = %d", size);

	//予約領域
	p += 4;

	//ファイル先頭から画像データまでのオフセット (byte)
	int* bfOffBits = (int*)*p; p += 4;
	printf("\n");
	printf("\nbfOffBits = %d", bfOffBits);

	//ヘッダサイズ
	int* headSize = (int*)*p; p += 4;
	printf("\n");
	printf("\nheadSize = %d", headSize);

	//画像の幅 (ピクセル)
	int* bcWidth = (int*)*p; p += 4;
	printf("\n");
	printf("\nbcWidth = %d", bcWidth);

	//画像の高さ (ピクセル)
	int* bcHeight = (int*)*p; p += 4;
	printf("\n");
	printf("\nbcHeight = %d", bcHeight);

	//色取得　
	//青
	int* b = (int*)*p; p += 28;
	printf("\n");
	printf("\nblue = %d", b);

	//緑
	int* g = (int*)*p; p += 4;
	printf("\ngreen = %d", g);

	//青
	int* r = (int*)*p; p += 4;
	printf("\nred = %d", r);
}
