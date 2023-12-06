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
    http_qr_code.begin(url.c_str());
    http_qr_code.GET();

    printf("QR code URL: %s\n", url.c_str());
    printf("QR code HTTP code: %s\n", http_qr_code.getString().c_str());

    if (http_qr_code.getSize() > 0){
        mQrCode = QRcode_decodeString(http_qr_code.getString().c_str());
        return true;
    }else{
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

}




