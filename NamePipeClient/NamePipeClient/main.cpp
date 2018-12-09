#include<windows.h>
#include<stdio.h>


int main()
{
	HANDLE h_pipe;
	OVERLAPPED ovi = {0};
	char buff[] = "Test of name pipe...";
	DWORD read_buff;
	printf("connecting name  pipe... ...\r\n");
	Sleep(5000);
	if (WaitNamedPipe("\\\\SKY\\pipe\\japanpipe",NMPWAIT_WAIT_FOREVER))
	{
		//open name pipe
		h_pipe = CreateFile("\\\\SKY\\pipe\\japan-pipe", 
			GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,NULL);
		if (INVALID_HANDLE_VALUE == h_pipe)
		{
			printf("failed to open name pipe...\r\n");
		}
		else
		{
			//write data to file
			if (WriteFile(h_pipe,buff,sizeof(buff),&read_buff,NULL))
			{
				printf("Successfully write data...\r\n");
			}
			else
			{
				printf("Failed to write data...\r\n");
			}
		}
	}
	else
	{
		printf("Failed to link to name pipe.\r\n");
	}

	return 0;
}