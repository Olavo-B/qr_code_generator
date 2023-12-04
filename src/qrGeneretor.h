#ifndef __QRGENERETOR_H_
#define __QRGENERETOR_H_


#ifndef __cplusplus
typedef unsigned char bool;
static const bool false = 0;
static const bool true = 1;
#endif

#include <Arduino.h>
#include <stdint.h>
#include <HTTPClient.h>
#include <string>



class QrGeneretor
{
public:
    QrGeneretor();
    ~QrGeneretor();


    /* 
    * Generate QR code from text
    * @param text - text to generate QR code
    * @param size - size of QR code (100 - auto)
    * 
    * @return true - success, false - error
    */
    bool generateQrCode(const char* text, const int size = 100);
    
    void readQrCode(const char* filename);

    string getUrlString();

    void QRcodeFree();


private:

    void *qrCodeDecodeString(const char *string);

    void* mQrCode;
    string urlString;
};

#endif // __QRGENERETOR_H_