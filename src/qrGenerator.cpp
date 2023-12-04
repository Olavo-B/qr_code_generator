#include "qrGeneretor.h"

QrGeneretor::QrGeneretor()
{
    mQrCode   = NULL;
    urlString = "";
}

QrGeneretor::~QrGeneretor()
{
    if (mQrCode != NULL)
    {
        QRcodeFree(mQrCode);
    }
}

bool QrGeneretor::generateQrCode(const char* text, const int size)
{
    
    string url = "http://api.qrserver.com/v1/create-qr-code/?data=";
    url += text;
    url += "&size=" + size + 'x' + size;

    urlString = url;
    
    HTTPClient http_qr_code;
    http_qr_code.useHTTP10(true);
    http_qr_code.begin(url.c_str());
    http_qr_code.GET();


    if (http_qr_code.getSize() > 0)
    {
        mQrCode = QRcode_decodeString(http_qr_code.getString().c_str());
        return true;
    }
    else
    {
        return false;
    }

}

void QrGeneretor::readQrCode(const char* filename)
{

}


string QrGeneretor::getUrlString()
{
    return urlString;
}

void QrGeneretor::QRcodeFree()
{
    free(mQrCode)
}

void* QrGeneretor::QRcode_decodeString(const char *string)
{

}




