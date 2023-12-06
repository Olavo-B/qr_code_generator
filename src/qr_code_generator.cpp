/**
 * @file qr_code_generator.cpp
 * @brief Implementation file for the qr_code_generator class.
 */
#include "qr_code_generator.h"

qr_code_generator::qr_code_generator()
{


    mQrCode   = NULL;
    mUrlString = "";
}

void qr_code_generator::QRcodeFree()
{
    free(mQrCode);
}

qr_code_generator::~qr_code_generator()
{
    if (mQrCode != NULL)
    {
        QRcodeFree();
    }
}

bool qr_code_generator::generateQrCode(const char* text, const int size)
{
    
    String url = "http://api.qrserver.com/v1/create-qr-code/?data=" + String(text) + "&size=" + String(size) + 'x' + String(size);

    mUrlString = url;
    
    HTTPClient http_qr_code;
    http_qr_code.useHTTP10(true);
    if (http_qr_code.begin(url.c_str())){
        printf("HTTP begin\n");
    } else {
        printf("HTTP begin failed\n");
    }
    int httpCode  = http_qr_code.GET();
    String result = http_qr_code.getString();

    String files = String("/") + String(text) + String(".png");


    // Delete the files inside spiffs every time and download them again
    if (SPIFFS.exists(files)) {
        SPIFFS.remove(files);
    }

    printf("QR code URL: %s\n", url.c_str());
    printf("QR code HTTP code: %d\n", httpCode);
    printf("QR code result: %s\n", result.c_str());

    if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        printf("[HTTPS] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {

            // Save the acquired data in spiffs for storage
            fs::File f = SPIFFS.open(files, "w", true);
            WiFiClient stream = http_qr_code.getStream();
            printf("SIZE:%d\n", http_qr_code.getSize());

            http_qr_code.writeToStream(&f);

            printf("\n");
            printf("FileWrite :"); printf(f.getWriteError() + "\n");
            printf("FileSize :"); printf(f.size() + "\n");
            f.close();
        }
        http_qr_code.end();
        return true;
    } else {
        printf("[HTTPS] GET... failed, error: %s\n", http_qr_code.errorToString(httpCode).c_str());
        return false;
    }

  

}

bool qr_code_generator::generateText(const char* path)
{


}


String qr_code_generator::getUrlString()
{
    if (mUrlString.length() == 0)
    {
        return "No URL";
    }
    else
    {
        return mUrlString;
    }
}

void* qr_code_generator::getQrCode()
{
    if (mQrCode == NULL)
    {
        return NULL;
    }
    else
    {
        return mQrCode;
    }
}


void* qr_code_generator::QRcode_decodeString(const char *string)
{

    printf(string);

}




