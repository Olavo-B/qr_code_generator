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

// char* qr_code_generator::bmp2c(void *fp)
// {
//     if (fp == NULL)
//         return NULL;

//     fseek (fp, 0, SEEK_END);   // non-portable
//     sz = ftell (fp);
//     fseek (fp, 0, SEEK_SET);   // non-portable

//     array[len - 4] = '_'; 
//     printf("const unsigned char PROGMEM %s[%ld] = {\n", array, sz);
//     do {
//         n = fread(buf, 1, 16, fp);
//         for (i = 0; i < n; i++) {
//             printf("0x%02X,", buf[i]);
//         }
//         printf("\n");
//     }while(n > 0);
//     printf("};\n");
//     return array;
// }




