#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define debug 0

char word[100000];
int ch_count=2;

unsigned char get_bit(unsigned char value, unsigned char shift)
{
	switch (shift)
	{
	case 0:
		return value & 0x1;
	case 1:
		return (value & 0x2) > 1;
	case 2:
		return (value & 0x4) > 2;
	case 3:
		return (value & 0x8) > 3;
	case 4:
		return (value & 0x10) > 4;
	case 5:
		return (value & 0x20) > 5;
	case 6:
		return (value & 0x40) > 6;
	case 7:
		return (value & 0x80) > 7;
	}
}

unsigned char set_bit(unsigned char value, unsigned char set, unsigned char shift)
{
	if (debug) printf("set_bit %d %d %d\n", value, set, shift);
	if (set == 1)
	{
		switch (shift)
		{
		case 0:
			return value | 0x1;
		case 1:
			return value | 0x2;
		case 2:
			return value | 0x4;
		case 3:
			return value | 0x8;
		case 4:
			return value | 0x10;;
		case 5:
			return value | 0x20;
		case 6:
			return value | 0x40;
		case 7:
			return value | 0x80;

		}
	}

	if (set == 0)
	{
		switch (shift)
		{
		case 0:
			return value & ~0x1;
		case 1:
			return value & ~0x2;
		case 2:
			return value & ~0x4;
		case 3:
			return value & ~0x8;
		case 4:
			return value & ~0x10;
		case 5:
			return value & ~0x20;
		case 6:
			return value & ~0x40;
		case 7:
			return value & ~0x80;
		}
	}
}

void bit_change(unsigned char* value, unsigned char bit_1, unsigned char bit_2)
{
	unsigned char tmp_bit_1, tmp_bit_2, tmp_value;
	tmp_value = *value;
	tmp_bit_1 = get_bit(tmp_value, bit_1);
	if (debug) printf("tmp_bit_1 %d\n", tmp_bit_1);
	tmp_bit_2 = get_bit(tmp_value, bit_2);
	if (debug)printf("tmp_bit_2 %d\n", tmp_bit_2);
	if (debug)printf("tmp_value %d\n", tmp_value);
	tmp_value = set_bit(tmp_value, tmp_bit_1, bit_2);
	//tmp_value=tmp_value&~0x4;
	if (debug)printf("1.tmp_value %d %x %d\n", tmp_value, tmp_bit_1, bit_2);
	tmp_value = set_bit(tmp_value, tmp_bit_2, bit_1);
	//tmp_value=tmp_value|0x1;
	if (debug)printf("2.tmp_value %d %x %d\n", tmp_value, 0x1, bit_1);
	if (debug)printf("tmp_value %d\n", tmp_value);
	*value = tmp_value;
}

void en_readfile(char *filename)
{
	FILE* ptr;
    char ch;
   	printf("!=>%s\n", filename);
    ptr = fopen(filename, "r");
    if (NULL == ptr) {
        printf("file can't be opened \n");
        }

    //printf("content of this file are \n");

    // Printing what is written in file
    // character by character using loop.
    while (ch != EOF){
        ch_count=ch_count+1;
        //printf("%c",ch);
        ch = fgetc(ptr);
        //printf("%x", ch);
        }
    printf("%d\n",ch_count);
    fclose(ptr);
    ptr = fopen(filename, "r");
    for(int i=0;i<ch_count-1;i++){
        word[i]=fgetc(ptr);
        //printf("%c",word[i]);
        }
    // Closing the file
    fclose(ptr);
}
void can_read_readfile(char *filename)
{

	FILE* ptr;
    char ch;
	printf("!=>%s\n", filename);
    ptr = fopen(filename, "r");
    if (NULL == ptr) {
        printf("file can't be opened \n");
        }

    //printf("content of this file are \n");

    // Printing what is written in file
    // character by character using loop.
    while (ch != EOF){
        ch_count=ch_count+1;
        printf("%c",ch);
        ch = fgetc(ptr);
        //printf("%x", ch);
        }
    printf("%d\n",ch_count);
    fclose(ptr);
    ptr = fopen(filename, "r");
    for(int i=0;i<ch_count-1;i++){
        word[i]=fgetc(ptr);
        printf("%c",word[i]);
        }
    // Closing the file
    fclose(ptr);
}
struct EXCHANGE_BIT
{
	unsigned char bit_1;
	unsigned char bit_2;
}_EXCHANGE_BIT;

int main(int argc, char *argv[])
{
	
	FILE* en;
	int in_put=atoi(argv[1]);
        //char fliename=atoi(argv[2]);
	printf("==>%s\n", argv[2]);
	struct EXCHANGE_BIT exchange_bit1[2];
	struct EXCHANGE_BIT exchange_bit2[2];
	struct EXCHANGE_BIT exchange_bit3[2];
	struct EXCHANGE_BIT exchange_bit4[2];
	exchange_bit1[0].bit_1 = 4;
	exchange_bit1[0].bit_2 = 2;
	exchange_bit1[1].bit_1 = 2;
	exchange_bit1[1].bit_2 = 4;
	
        exchange_bit2[0].bit_1 = 0;
        exchange_bit2[0].bit_2 = 3;
        exchange_bit2[1].bit_1 = 3;
        exchange_bit2[1].bit_2 = 0;
		
        exchange_bit3[0].bit_1 = 1;
        exchange_bit3[0].bit_2 = 6;
        exchange_bit3[1].bit_1 = 6;
        exchange_bit3[1].bit_2 = 1;
        
        exchange_bit4[0].bit_1 = 5;
        exchange_bit4[0].bit_2 = 7;
        exchange_bit4[1].bit_1 = 7;
        exchange_bit4[1].bit_2 = 5;
	//printf("%x\n",word[0]);
	if (in_put==0){
		can_read_readfile(argv[2]);
		en = fopen(argv[3], "w");

		for(int j0=0;j0<ch_count-1;j0++){
			//printf("1.%d %x\n",j0, word[j0]);
			bit_change(&word[j0], exchange_bit1[0].bit_1, exchange_bit1[0].bit_2);
			bit_change(&word[j0], exchange_bit2[0].bit_1, exchange_bit2[0].bit_2);
			bit_change(&word[j0], exchange_bit3[0].bit_1, exchange_bit3[0].bit_2);
			bit_change(&word[j0], exchange_bit4[0].bit_1, exchange_bit4[0].bit_2);
			//printf("2.%d %x\n",j0, word[j0]);
			fputc(word[j0],en);
			}
		fclose(en);

	}
	


	else if (in_put==1){
		en_readfile(argv[2]);
		en = fopen(argv[3], "w");

		for(int j1=0;j1<ch_count-1;j1++){
			//printf("3.%d %x\n",j1, word[j1]);
			bit_change(&word[j1], exchange_bit1[1].bit_1, exchange_bit1[1].bit_2);
			bit_change(&word[j1], exchange_bit2[1].bit_1, exchange_bit2[1].bit_2);
			bit_change(&word[j1], exchange_bit3[1].bit_1, exchange_bit3[1].bit_2);
			bit_change(&word[j1], exchange_bit4[1].bit_1, exchange_bit4[1].bit_2);
			fputc(word[j1],en);
			//printf("4.%d %x\n",j1, word[j1]);
	
		}
		fclose(en);

	}
}
