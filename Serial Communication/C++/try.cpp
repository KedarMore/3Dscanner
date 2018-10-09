#include <windows.h>
#include <string>
#include <stdio.h>
#define ARDUINO_WAIT_TIME 2000
using namespace std;

string portNumber;
HANDLE hSerial;
bool connected;
COMSTAT status;

bool connectPrinter(char *portName){

    //Connects to the port.
    hSerial = CreateFileA(portName,
    GENERIC_READ | GENERIC_WRITE,
    0,
    NULL,
    OPEN_EXISTING,
    FILE_ATTRIBUTE_NORMAL,
    NULL);

    if(hSerial==INVALID_HANDLE_VALUE)
    {
        if(GetLastError()==ERROR_FILE_NOT_FOUND){
            printf("ERROR: Handle was not attached. Reason: %s not available.\n", portName);
            return false;
        }
        else
        {
            //If port is in use by another program or did not closed previous process.
            printf("ERROR!!! \n");
            CloseHandle(hSerial);
            return false;
        }
    }
    else
    {

        DCB dcbSerialParams = {0};

        if (!GetCommState(hSerial, &dcbSerialParams))
        {
            printf("failed to get current serial parameters!");
            return false;
        }
        else
        {
            // Set Serial Port specifications.
            dcbSerialParams.BaudRate=CBR_9600;
            dcbSerialParams.ByteSize=8;
            dcbSerialParams.StopBits=ONESTOPBIT;
            dcbSerialParams.Parity=NOPARITY;

             if(!SetCommState(hSerial, &dcbSerialParams))
             {
                printf("ALERT: Could not set Serial Port parameters");
                return false;
             }
             else
             {
                 connected = true;
                 printf("Connection Successful for :%s !!! \n" ,portName);
                 //Wait 2s as the arduino board will be reseting
                 return true;
                 Sleep(ARDUINO_WAIT_TIME);
             }
        }
    }

}


int readData(char *buffer,unsigned int nbChar){

    DWORD bytesRead;
    DWORD dwCommModemStatus;

        //Set the type of data to be caught.(RXCHAR -> Data available on RX pin.)
        SetCommMask (hSerial, EV_RXCHAR );

        while (hSerial != INVALID_HANDLE_VALUE)
        {
          // Wait for an event to occur for the port.
          WaitCommEvent (hSerial, &dwCommModemStatus, 0);

          if (dwCommModemStatus & EV_RXCHAR )
          {
                //unsigned int toRead;
                //ClearCommError(this->hSerial, &this->errors, &this->status);
                do
                {
                  // Read the data from the serial port.
                    ReadFile (hSerial, buffer, 1, &bytesRead, 0);
                  // Display the data read.
                      printf ("%s" ,buffer);

                } while (bytesRead > 0);
          }
        }
    //}
    //If nothing has been read, or that an error was detected return -1
    return -1;
}

    int main()
    {

        char* buffer = new char[32768];
        int nbChar= 32768;
        string str="////.//COM12"; // Use your port number to connect

        char * writable = new char[str.size() + 1];
        std::copy(str.begin(), str.end(), writable);
        writable[str.size()] = '\0';

        connectPrinter(writable);
        delete []writable;
        readData(buffer,nbChar);
        return 0;
    }
