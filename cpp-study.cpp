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

	printf("==========ファイルヘッダ===========\n");
	// ファイルタイプ　通常は'BM'
	char* p = bmp;
	char buff[3];
	buff[0] = *p; p++;
	buff[1] = *p; p++;
	buff[2] = 0;
	printf("bfType = %s", buff);
	printf("\n");

	//ファイルサイズ取得
	int* size = (int*)*p; p += 4;
	printf("\nbfSize = %d", size);
	printf("\n");

	//予約領域
	p += 4;

	//ファイル先頭から画像データまでのオフセット (byte)
	int* bfOffBits = (int*)*p; p += 4;
	printf("\nbfOffBits = %d", bfOffBits);

	printf("\n====================================\n");
	printf("\n");


	printf("=============情報ヘッダ==============");
	//ヘッダサイズ
	int* headSize = (int*)*p; p += 4;
	printf("\nheadSize = %d", headSize);

	//画像の幅
	int* bcWidth = (int*)*p; p += 4;
	printf("\n");
	printf("\nbcWidth = %d", bcWidth);

	//画像の高さ
	int* bcHeight = (int*)*p; p += 4;
	printf("\n");
	printf("\nbcHeight = %d", bcHeight);

	//プレーン数
	short* planes = (short*)*p; p += 2;
	printf("\n");
	printf("\nbcPlanes = %d", planes);

	//1画素あたりのデータサイズ (bit)
	short* bitCount = (short*)*p; p += 2;
	printf("\n");
	printf("\nbcBitCount = %d", bitCount);

	//圧縮形式
	int* compression = (int*)*p; p += 4;
	printf("\n");
	printf("\nbicompression = %d", compression);

	//画像データ部のサイズ (byte)
	int* sizeImage = (int*)*p; p += 4;
	printf("\n");
	printf("\nbiSizeImage = %d", sizeImage);

	//横方向解像度
	int* biXPixPerMeter = (int*)*p; p += 4;
	printf("\n");
	printf("\nbiXPixPerMeter = %d", biXPixPerMeter);

	//縦方向解像度
	int* biYPixPerMeter = (int*)*p; p += 4;
	printf("\n");
	printf("\nbiYPixPerMeter = %d", biYPixPerMeter);

	//格納されているパレット数
	int* biClrUsed = (int*)*p; p += 4;
	printf("\n");
	printf("\nbiClrUsed = %d", biClrUsed);

	//重要なパレットのインデックス
	int* biCirImportant = (int*)*p; p += 4;
	printf("\n");
	printf("\nbiCirImportant = %d", biCirImportant);

	printf("\n====================================\n");
	printf("\n");
}
