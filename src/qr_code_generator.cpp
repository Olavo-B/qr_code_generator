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

    
    printf("QR code URL: %s\n", url.c_str());
    printf("QR code HTTP code: %d\n", httpCode);
    printf("QR code result: %s length %d\n", result.c_str(), result.length());

    if (httpCode > 0) {
        
        mQrCode = QRcode_decodeString(http_qr_code.getString(), size);
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


uint16_t* qr_code_generator::QRcode_decodeString(const String& response, const int size)
{
    
    uint16_t* mImage = (uint16_t*)malloc(size * size * sizeof(uint16_t));
    const char* data = response.c_str();
    size_t dataSize  = response.length();

    // Exibir a imagem no display
    for (size_t i = 0; i < dataSize; i += 2) {
        uint16_t pixel = (data[i] << 8) | data[i + 1];
        mImage[i / 2]  = pixel;
    }

    return mImage;

}



