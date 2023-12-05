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

    /**
     * Generate QR code from text
     * @param text - text to generate QR code
     * @param size - size of QR code (100 - auto)
     * @return true - success, false - error
     */
    bool generateQrCode(const char* text, const int size = 100);
    
    /**
     * Read QR code from file
     * @param filename - name of the file containing the QR code
     */
    void readQrCode(const char* filename);

    /**
     * Get the URL string of the generated QR code
     * @return URL string
     */
    string getUrlString();

    /**
     * Free the memory allocated for the QR code
     */
    void QRcodeFree();

private:
    /**
     * Decode a string into a QR code
     * @param string - string to decode
     * @return pointer to the decoded QR code
     */
    void* qrCodeDecodeString(const char* string);

    void* mQrCode;
    string urlString;
};

#endif // __QRGENERETOR_H_