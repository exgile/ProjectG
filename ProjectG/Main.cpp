/*
Name: Pangya Dll
Copyright:
Author: João Victor Nunes De Oliveira
Date: 18/04/17 15:37
Description: SC Dasar untuk lebih mudah menggunakan RCD Logger
===============================================================
MOHON DESKRIPSI INI JANGAN DIBUANG !
*/

#include <Windows.h>
#include <stdlib.h>

#define DLLEXPORT EXTERN_C __declspec(dllexport)
#define BypassLauncher_adr 0x0A5F097 //ORIGINAL 0F 84 2E FF FF FF - JE 00A5EFCB
#define BypassGG_adr	   0x0A49580 //ORIGINAL 83 3D 14 8F EC 00 00 - CMP DWORD PTR [00EC8F14],00
#define BypassIp_adr	   0x0CDE2C4 //ORIGINAL 31 39 32 2E 39 36 2E 32 30 34 2E 31 35 33
#define BypassLink1_adr    0x0CD8AC4 //ORIGINAL 68 74 74 70 3A 2F 2F 31 39 32 2E 31 36 38 2E 38 31 2E 32 33 37 3A 38 38 38 38 2F 63 6C 69 65 6E 74 2F 75 70 64 61 74 65 74 65 73 74 2F
#define BypassLink2_adr	   0x0CD8AF4 //ORIGINAL 68 74 74 70 3A 2F 2F 70 79 2E 63 64 6E 2E 70 61 74 63 68 67 61 6D 65 72 61 67 65 2E 63 6F 6D 2F 6E 65 77 2F 53 65 72 76 69 63 65 2F 53 34 5F 50 61 74 63 68 2F
#define BypassLink3_adr	   0x0CDD2F8 //ORIGINAL 68 74 74 70 3A 2F 2F 67 6D 70 79 2E 67 61 6D 65 72 61 67 65 2E 63 6F 6D 3A 35 30 30 30 39 2F 54 72 61 6E 73 6C 61 74 69 6F 6E 2F 52 65 61 64 2E 61 73 70 78
#define BypassLink4_adr	   0x0CE9B48 //ORIGINAL 68 74 74 70 3A 2F 2F 70 61 6E 67 79 61 2E 67 61 6D 65 72 61 67 65 2E 63 6F 6D 2F 47 61 63 68 61 2F 47 61 63 68 61 2E 61 73 70 78
#define BypassLink5_adr	   0x0CE9EEC //ORIGINAL 68 74 74 70 3A 2F 2F 67 61 6D 65 72 61 67 65 2E 63 6F 6D 2F 72 65 63 68 61 72 67 65 2F 67 61 6D 65 2F 67 6F 74 6F 2F 70 79
#define BypassLink6_adr	   0x0CF1D6C //ORIGINAL 68 74 74 70 3A 2F 2F 31 39 32 2E 31 36 38 2E 38 31 2E 31 31 35 3A 35 30 30 30 39 2F 54 72 61 6E 73 6C 61 74 69 6F 6E 2F 52 65 61 64 2E 61 73 70 78
#define BypassLink7_adr	   0x0CF1DA8 //ORIGINAL 68 74 74 70 3A 2F 2F 67 6D 70 79 74 2E 67 61 6D 65 72 61 67 65 2E 63 6F 6D 3A 35 30 30 30 39 2F 54 72 61 6E 73 6C 61 74 69 6F 6E 2F 52 65 61 64 2E 61 73 70 78
#define BypassLink8_adr	   0x0D073DC //ORIGINAL 68 74 74 70 3A 2F 2F 67 6D 70 79 2E 67 61 6D 65 72 61 67 65 2E 63 6F 6D 3A 35 30 30 30 39 2F 52 65 70 6F 72 74 2F 52 65 70 6F 72 74 45 72 72 6F 72 2E 61 73 70 78
#define BypassLink9_adr	   0x0D0745C //ORIGINAL 68 74 74 70 3A 2F 2F 67 6D 70 79 2E 67 61 6D 65 72 61 67 65 2E 63 6F 6D 3A 35 30 30 30 39 2F 52 65 70 6F 72 74 2F 43 72 69 6D 65 52 65 70 6F 72 74 2E 61 73 70 78
#define BypassLink10_adr   0x0D0FE60 //ORIGINAL 68 74 74 70 3A 2F 2F 70 79 2E 63 64 6E 2E 70 61 74 63 68 67 61 6D 65 72 61 67 65 2E 63 6F 6D
#define BypassLink11_adr   0x0D11B10 //ORIGINAL 68 74 74 70 3A 2F 2F 67 6D 70 79 2E 67 61 6D 65 72 61 67 65 2E 63 6F 6D 3A 35 30 30 30 39 2F 53 65 6C 66 44 65 73 69 67 6E 2F 55 70 6C 6F 61 64 46 69 6C 65 73 2E 61 73 70 78
#define BypassLink12_adr   0x0D11B4C //ORIGINAL	68 74 74 70 3A 2F 2F 67 6D 70 79 2E 67 61 6D 65 72 61 67 65 2E 63 6F 6D 3A 35 30 30 30 39 2F 5F 46 69 6C 65 73 2F 53 65 6C 66 44 65 73 69 67 6E 2F
#define BypassLink13_adr   0x0D11B80 //ORIGINAL	68 74 74 70 3A 2F 2F 67 6D 70 79 2E 67 61 6D 65 72 61 67 65 2E 63 6F 6D 3A 35 30 30 30 39 2F 47 75 69 6C 64 45 6D 62 6C 65 6D 2F 55 70 6C 6F 61 64 46 69 6C 65 73 2E 61 73 70 78
#define BypassLink14_adr   0x0D11BBC //ORIGINAL 68 74 74 70 3A 2F 2F 67 6D 70 79 2E 67 61 6D 65 72 61 67 65 2E 63 6F 6D 3A 35 30 30 30 39 2F 5F 46 69 6C 65 73 2F 47 75 69 6C 64 45 6D 62 6C 65 6D 2F
#define BypassLink15_adr   0x0D1CC14 //ORIGINAL 68 74 74 70 3A 2F 2F 70 61 6E 67 79 61 2E 67 61 6D 65 72 61 67 65 2E 63 6F 6D 2F 45 6E 74 72 79 50 6F 69 6E 74 2F 65 74 70 2E 61 73 70 78
#define Map0               0x0D03378 // 77 69 6E 64 68 69 6C 6C
#define loby               0x0DFE378 // 6D 61 70 5F 77 69 6E 64 68 69 6C 6C 5F 6F 6E
#define lobi               0x0D19FC4 // 6D 61 70 5F 77 69 6E 64 68 69 6C 6C 5F 6F 66 66


DLLEXPORT void kuda(void *adr, void *ptr, int size)
{
	DWORD OldProtection;
	VirtualProtect(adr, size, PAGE_EXECUTE_READWRITE, &OldProtection);
	memcpy(adr, ptr, size);
	VirtualProtect(adr, size, OldProtection, &OldProtection);
}

DLLEXPORT DWORD WINAPI Trinngiling(LPVOID param)
{
	while (1)
	{
		DWORD ValueCheck = *(DWORD*)BypassLauncher_adr;
		if (ValueCheck == 4281238543)
		{
			//Jump Block Open Update.exe
			kuda((void*)(BypassLauncher_adr), (void*)(PBYTE)"\xE9\x2F\xFF\xFF\xFF\x90", 6);
			//GG Jump Pass
			kuda((void*)(BypassGG_adr), (void*)(PBYTE)"\xC3\x90\x90\x90\x90\x90\x90", 7);
			//IP SERVER 
			kuda((void*)(BypassIp_adr), (void*)(PBYTE)"\x31\x34\x39\x2E\x35\x36\x2E\x33\x33\x2E\x38\x35\x00\x00", 14);
			//http://192.168.81.237:8888/client/updatetest/ //testa o updatelist
			kuda((void*)(BypassLink1_adr), (void*)(PBYTE)"\x68\x74\x74\x70\x3A\x2F\x2F\x70\x61\x6E\x67\x79\x61\x66\x75\x70\x2E\x78\x79\x7A\x2F\x53\x34\x5F\x50\x61\x74\x63\x68\x2F\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 45);
			//Patch update > http://py.cdn.patchgamerage.com/new/Service/S4_Patch/
			kuda((void*)(BypassLink2_adr), (void*)(PBYTE)"\x68\x74\x74\x70\x3A\x2F\x2F\x70\x79\x2E\x63\x64\x6E\x2E\x70\x61\x74\x63\x68\x67\x61\x6D\x65\x72\x61\x67\x65\x2E\x63\x6F\x6D\x2F\x6E\x65\x77\x2F\x53\x65\x72\x76\x69\x63\x65\x2F\x53\x34\x5F\x50\x61\x74\x63\x68\x2F", 53);
			//Change Translation Read.aspx(http://gmpy.gamerage.com:50009/Translation/Read.aspx)
			kuda((void*)(BypassLink3_adr), (void*)(PBYTE)"\x68\x74\x74\x70\x3A\x2F\x2F\x70\x61\x6E\x67\x79\x61\x66\x72\x65\x73\x68\x75\x70\x2E\x67\x65\x61\x72\x2E\x68\x6F\x73\x74\x2F\x52\x65\x61\x64\x2E\x61\x73\x70\x78\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 52);
			//Change web page gacha > http://pangya.gamerage.com/Gacha/Gacha.aspx
			kuda((void*)(BypassLink4_adr), (void*)(PBYTE)"\x68\x74\x74\x70\x3A\x2F\x2F\x70\x61\x6E\x67\x79\x61\x66\x75\x70\x2E\x78\x79\x7A\x2F\x67\x61\x63\x68\x61\x2F\x47\x61\x63\x68\x61\x2E\x70\x68\x70\x00\x00\x00\x00\x00\x00\x00", 43);
			//Change web recharge points/cookies > http://gamerage.com/recharge/game/goto/py
			kuda((void*)(BypassLink5_adr), (void*)(PBYTE)"\x68\x74\x74\x70\x3A\x2F\x2F\x70\x61\x6E\x67\x79\x61\x66\x75\x70\x2E\x78\x79\x7A\x2F\x63\x61\x64\x61\x73\x74\x72\x6F\x2F\x64\x6F\x61\x72\x2E\x70\x68\x70\x00\x00\x00", 41);
			//Change translation read.aspx 2? > http://192.168.81.115:50009/Translation/Read.aspx
			kuda((void*)(BypassLink6_adr), (void*)(PBYTE)"\x68\x74\x74\x70\x3A\x2F\x2F\x70\x61\x6E\x67\x79\x61\x66\x75\x70\x2E\x78\x79\x7A\x2F\x54\x72\x61\x6E\x73\x6C\x61\x74\x69\x6F\x6E\x2F\x52\x65\x61\x64\x2E\x68\x74\x6D\x6C\x00\x00\x00\x00\x00\x00\x00", 49);
			//Change translation read.aspx Principal > http://gmpyt.gamerage.com:50009/Translation/Read.aspx 
			kuda((void*)(BypassLink7_adr), (void*)(PBYTE)"\x68\x74\x74\x70\x3A\x2F\x2F\x70\x61\x6E\x67\x79\x61\x66\x72\x65\x73\x68\x75\x70\x2E\x67\x65\x61\x72\x2E\x68\x6F\x73\x74\x2F\x52\x65\x61\x64\x2E\x61\x73\x70\x78\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 53);
			//Web Page Report.aspx > http://gmpy.gamerage.com:50009/Report/ReportError.aspx
			kuda((void*)(BypassLink8_adr), (void*)(PBYTE)"\x68\x74\x74\x70\x3A\x2F\x2F\x70\x61\x6E\x67\x79\x61\x66\x75\x70\x2E\x78\x79\x7A\x2F\x52\x65\x70\x6F\x72\x74\x2F\x42\x75\x67\x52\x65\x70\x6F\x72\x74\x2E\x70\x68\x70\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 54);
			//Web Page CrimeReport.aspx > http://gmpy.gamerage.com:50009/Report/CrimeReport.aspx
			kuda((void*)(BypassLink9_adr), (void*)(PBYTE)"\x68\x74\x74\x70\x3A\x2F\x2F\x70\x61\x6E\x67\x79\x61\x66\x75\x70\x2E\x78\x79\x7A\x2F\x70\x6F\x73\x74\x2F\x43\x72\x69\x6D\x65\x52\x65\x70\x6F\x72\x74\x2E\x70\x68\x70\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 54);
			//Web Page cnd patch > http://py.cdn.patchgamerage.com
			kuda((void*)(BypassLink10_adr), (void*)(PBYTE)"\x68\x74\x74\x70\x3A\x2F\x2F\x70\x61\x6E\x67\x79\x61\x66\x75\x70\x2E\x78\x79\x7A\x2F\x6E\x65\x77\x2F\x53\x65\x72\x76\x69\x63", 31);
			//Web Page Upload File Self Design > http://gmpy.gamerage.com:50009/SelfDesign/UploadFiles.aspx
			kuda((void*)(BypassLink11_adr), (void*)(PBYTE)"\x68\x74\x74\x70\x3A\x2F\x2F\x70\x61\x6E\x67\x79\x61\x66\x75\x70\x2E\x78\x79\x7A\x2F\x53\x65\x6C\x66\x44\x65\x73\x69\x67\x6E\x2F\x55\x70\x6C\x6F\x61\x64\x46\x69\x6C\x65\x73\x2E\x70\x68\x70\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 58);
			//Web File Folder Self Design > http://gmpy.gamerage.com:50009/_Files/SelfDesign/
			kuda((void*)(BypassLink12_adr), (void*)(PBYTE)"\x68\x74\x74\x70\x3A\x2F\x2F\x70\x61\x6E\x67\x79\x61\x66\x75\x70\x2E\x78\x79\x7A\x2F\x5F\x46\x69\x6C\x65\x73\x2F\x53\x65\x6C\x66\x44\x65\x73\x69\x67\x6E\x2F\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 49);
			//Web Page Upload File Guild Image > http://gmpy.gamerage.com:50009/GuildEmblem/UploadFiles.aspx
			kuda((void*)(BypassLink13_adr), (void*)(PBYTE)"\x68\x74\x74\x70\x3A\x2F\x2F\x70\x61\x6E\x67\x79\x61\x66\x75\x70\x2E\x78\x79\x7A\x2F\x47\x75\x69\x6C\x64\x45\x6D\x62\x6C\x65\x6D\x2F\x55\x70\x6C\x6F\x61\x64\x46\x69\x6C\x65\x73\x2E\x70\x68\x70\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 59);
			//Web File Folder Guild Image > http://gmpy.gamerage.com:50009/_Files/GuildEmblem/
			kuda((void*)(BypassLink14_adr), (void*)(PBYTE)"\x68\x74\x74\x70\x3A\x2F\x2F\x70\x61\x6E\x67\x79\x61\x66\x75\x70\x2E\x78\x79\x7A\x2F\x5F\x46\x69\x6C\x65\x73\x2F\x47\x75\x69\x6C\x64\x45\x6D\x62\x6C\x65\x6D\x2F\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 50);
			//Web Page Entry Point > http://pangya.gamerage.com/EntryPoint/etp.aspx
			kuda((void*)(BypassLink15_adr), (void*)(PBYTE)"\x68\x74\x74\x70\x3A\x2F\x2F\x70\x61\x6E\x67\x79\x61\x66\x75\x70\x2E\x78\x79\x7A\x2F\x45\x6E\x74\x72\x79\x50\x6F\x69\x6E\x74\x2F\x65\x74\x70\x2E\x70\x68\x70\x00\x00\x00\x00\x00\x00\x00", 46);

			/*kuda((void*)(Map0), (void*)(PBYTE)"\x6C\x75\x6E\x61\x00\x00\x00\x00", 8);
			kuda((void*)(loby), (void*)(PBYTE)"\x6C\x6F\x62\x62\x79\x5F\x70\x69\x6E\x69", 10);
			kuda((void*)(lobi), (void*)(PBYTE)"\x6C\x6F\x62\x62\x79\x5F\x70\x69\x6E\x69", 10);*/
		}

		Sleep(5);
	}
	return (0);
}

BOOL WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{
	DisableThreadLibraryCalls(hDll);
	if (dwReason == DLL_PROCESS_ATTACH) {

		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Trinngiling, 0, 0, 0);
	}
	return TRUE;
}
