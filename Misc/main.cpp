#include <bits/stdc++.h>
#include <windows.h>
#include <mmsystem.h>
#include <thread>

using namespace std;

string x = "";

void T2()
{
    PlaySound(TEXT("soundtrack.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void ProgrammingTools()
{
    cout << "Programming Tools are being installed..." << endl;
    string a, b, c;
    a = x + "codeblocks-16.01mingw-setup.exe";
    b = x + "fpc-3.0.2.i386-win32.exe";
    c = x + "fpc-3.0.2.i386-win32.cross.x86_64-win64.exe";
    ShellExecute(NULL,"open",a.c_str(),NULL,NULL,SW_SHOW);
    ShellExecute(NULL,"open",b.c_str(),NULL,NULL,SW_SHOW);
    ShellExecute(NULL,"open",c.c_str(),NULL,NULL,SW_SHOW);
}

void InternetBrowser()
{
    string a;
    cout << "Chrome are being installed..." << endl;
    a = x + "ChromeSetup.exe";
    ShellExecute(NULL,"open",a.c_str(),NULL,NULL,SW_SHOW);
}

void VCRedist()
{
    cout << "VCRedist are being installed..." << endl;
    string a, b, c, d;
    a = x + "vc_redist.x64.exe";
    b = x + "vc_redist.x86.exe";
    c = x + "vcredist_x64.exe";
    d = x + "vcredist_x86.exe";
    ShellExecute(NULL,"open",a.c_str(),NULL,NULL,SW_SHOW);
    ShellExecute(NULL,"open",b.c_str(),NULL,NULL,SW_SHOW);
    ShellExecute(NULL,"open",c.c_str(),NULL,NULL,SW_SHOW);
    ShellExecute(NULL,"open",d.c_str(),NULL,NULL,SW_SHOW);
}

void SystemTools()
{
    cout << "System Tools are being installed..." << endl;
    string a, b, c;
    a = x + "ccsetup529.exe";
    b = x + "sd5_setup.exe";
    c = x + "avast_free_antivirus_setup_online.exe";
    ShellExecute(NULL,"open",a.c_str(),NULL,NULL,SW_SHOW);
    ShellExecute(NULL,"open",b.c_str(),NULL,NULL,SW_SHOW);
    ShellExecute(NULL,"open",c.c_str(),NULL,NULL,SW_SHOW);
}

void KMSPico()
{
    cout << "Executing KMS GUI ELDI ..." << endl;
    string a = x + "KMSELDI.exe";
    ShellExecute(NULL,"open",a.c_str(),NULL,NULL,SW_SHOW);
}

void InstallAll()
{
    KMSPico();
    ProgrammingTools();
    InternetBrowser();
    SystemTools();
    VCRedist();
}

void InstallAllButKMS()
{
    //KMSPico();
    ProgrammingTools();
    InternetBrowser();
    SystemTools();
    VCRedist();
}

void InstallAllButVCRe()
{
    KMSPico();
    ProgrammingTools();
    InternetBrowser();
    SystemTools();
    //VCRedist();
}

void InstallProg()
{
    //KMSPico();
    ProgrammingTools();
    InternetBrowser();
    SystemTools();
    //VCRedist();
}

void Choice()
{
    long long c = 0;
    while ((c<-1) || ((c<1) && (c>-1)) || (c>10))
    {
        cout << "Your choice: ";
        cin >> c;
        if (c==1) ProgrammingTools();
        if (c==2) InternetBrowser();
        if (c==3) VCRedist();
        if (c==4) SystemTools();
        if (c==5) KMSPico();
        if (c==6) InstallAll();
        if (c==7) InstallAllButVCRe();
        if (c==8) InstallAllButKMS();
        if (c==9) InstallProg();
        if (c==-1) break;
        c = 69;
    }
    //Play();
}

void Init()
{
    cout << "       Welcome to CTB Essential Installer by Bu1th4nh!" << endl;
    cout << endl;
    cout << "----------------------------00000----------------------------" << endl;
    cout << endl;
    cout << "Enter the install files dir: " ;
    getline(cin, x);
    cout << endl;
    cout << "Please enter your choice listed below:" << endl;
    cout << endl;
    cout << "1: Install Programing Tool (including FPC and C::B)" << endl;
    cout << "2: Install Chrome" << endl;
    cout << "3: Install VCRedist" << endl;
    cout << "4: Install System Tool (including Smart Defrag, Avast AV and CCleaner)" << endl;
    cout << "5: Activate Windows and Office!" << endl;
    cout << "6: Install Everything!" << endl;
    cout << "7: Install Everything without VCRedist" << endl;
    cout << "8: Install Everything without KMSPico" << endl;
    cout << "9: Install Everything without KMSPico and VCRedist" << endl;
    cout << "-1: Exit the program" << endl;
    cout << endl;
    cout << "----------------------------BEGIN----------------------------" << endl;
    x = x + "\\";
}

void T1()
{
    //Play();
    Init();
    //Play();
    Choice();
    cout << "I love Nham Thuy Hang <3 <3" << endl;
}

int main()
{
    thread first (T1);
    thread second (T2);
    system("pause");
    return 0;
}

