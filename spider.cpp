
#include <iostream>
#include <stdio.h>
//#include <stdlib.h>

#ifdef _WIN32
#include <conio.h>
#else
#include <sys/select.h>
#include <termios.h>
//#include <stropts.h>
//#include <unistd.h>
//#include <fcntl.h>
#include <sys/ioctl.h>
int _kbhit() {
    static const int STDIN = 0;
    static bool initialized = false;

    if (! initialized) {
        // Use termios to turn off line buffering
        termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }

    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
}

#endif


using namespace std;

int main(){
  cout<<"Hello World"<<endl;
  while(!_kbhit());
}

