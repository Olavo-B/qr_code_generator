#pragma once

#ifndef __QR_CODE_GENERATOR_H_
#define __QR_CODE_GENERATOR_H_

#ifndef __cplusplus
typedef unsigned char bool;
static const bool false = 0;
static const bool true = 1;
#endif

#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include <stdint.h>
#include <string>

class qr_code_generator
{
public:
    qr_code_generator();
    ~qr_code_generator();

    /**
     * Generate QR code from text
     * @param text - text to generate QR code
     * @param size - size of QR code (100 - auto)
     * @return true - success, false - error
     */
    bool generateQrCode(const char* text, const int size = 100);

    /**
     * Get content from QR code
     * @param path - path to the file containing the text
     * @return true - success, false - error
     */
    bool generateText(const char* path);
    
    /**
     * Get the URL string of the generated QR code
     * @return URL string
     */
    String getUrlString();

    /**
     * Get the QR code
     * @return pointer to the QR code
     */
    void* getQrCode();

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
    void* QRcode_decodeString(const char* string);

    void* mQrCode;
    String mUrlString;
};

#endif // __QR_CODE_GENERATOR_H_